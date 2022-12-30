// Allowed libraries are already included
// You can add your own libraries if you need to
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>

#include "util.h"

// Macros
// You may change these to your likings
#define CELSIUS_OFFSET 273.15
#define FAHRENHEIT_FRACTION 9/5
#define FAHRENHEIT_OFFSET 32

// #define DEBUG

// Might change that later...
// Knew I forgot something
typedef enum TEMPERATURE_UNIT
{
    T_U_CELSIUS = 'c',
    T_U_FAHRENHEIT = 'f',
    T_U_KELVIN = 'k',
    T_U_NONE
}
TEMPERATURE_UNIT;

typedef struct TEMPERATURE
{
    double value;
    TEMPERATURE_UNIT unit;
}
TEMPERATURE;

// Not a good name...
typedef struct CONFIG
{
    TEMPERATURE source;
    TEMPERATURE target;
    int rounding_places;
}
CONFIG;

// Protoypes
CONFIG parse_args(int argc, char const *argv[]);
void print_usage_instructions(const char *program_name);
void print_delimiter(char delimiter, int length);
double parse_temp_value(char *arg);
TEMPERATURE_UNIT parse_src_temp_unit(char *program_name, char *arg);
TEMPERATURE_UNIT parse_target_temp_unit(char *program_name, char *flag, char *val);
TEMPERATURE_UNIT parse_temp_unit(char *program_name, char *arg);
int parse_rounding_places(int argc, char const*argv[]);
TEMPERATURE convert_temperature(TEMPERATURE src, TEMPERATURE_UNIT target_unit);
TEMPERATURE round_temperature(TEMPERATURE temperature, int rounding_places);

// IMPORTANT REQUIREMENTS/LIMITATIONS
//
// Read the requirements and limitations carefully.
// You can find them in the README.md file.
//
// Example CLI usage:
// $ ./temp-conv 293.15 kelvin -t celsius
//
// Use dedicated functions to convert temperatures.
// Use dedicated functions to print the output.
// stdin/stdout should not happend in the main!!!

int main(int argc, char const *argv[])
{
    // TODO: Write your code here

    // Step 0: Write the CLI 😂

    CONFIG config = parse_args(argc, argv);

    // Now to the fun stuff!!!

    // Printing UI
    // Lines usually get quite long...
    print_delimiter('-', 32);
    printf("Converting %.2f %c to %c\n", config.source.value, toupper(config.source.unit), toupper(config.target.unit));
    printf("Rounding to %d decimal places\n", config.rounding_places);
    print_delimiter('-', 32);

    // Step 1: Convert the temperature
    config.target = convert_temperature(config.source, config.target.unit);

    // More UI stuff
    printf("%.2f %c = %.*f %c\n", config.source.value, toupper(config.source.unit), config.rounding_places, config.target.value, toupper(config.target.unit));
    print_delimiter('-', 32);
    printf("✅ Done!\n");

    // Step 2: Round the temperature
    config.target = round_temperature(config.target, config.rounding_places);

    return 0;
}

// UI stuff

void print_delimiter(char delimiter, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", delimiter);
    }
    printf("\n");
}

// Conversion functions

TEMPERATURE convert_temperature(TEMPERATURE src, TEMPERATURE_UNIT target_unit)
{
    TEMPERATURE target;

    #ifdef DEBUG
    printf("src.value: %lf\n", src.value);
    printf("src.unit: %c\n", src.unit);
    #endif

    target.value = src.value;
    target.unit = src.unit;

    #ifdef DEBUG
    printf("target.value: %lf\n", target.value);
    printf("target.unit: %c\n", target.unit);
    #endif

    // First convert to Kelvin

    #ifdef DEBUG
    printf("Converting to Kelvin...\n");
    #endif

    // GPT for the win
    switch (src.unit)
    {
        case T_U_CELSIUS:
            target.value += CELSIUS_OFFSET;
            break;
        case T_U_FAHRENHEIT:
            target.value = (target.value - FAHRENHEIT_OFFSET) * FAHRENHEIT_FRACTION + CELSIUS_OFFSET;
            break;
        case T_U_KELVIN:
            // Do nothing
            break;
        default:
            // Handle error
            fprintf(stderr, "convert_temperature: Unknown temperature unit.\n");
            exit(EXIT_FAILURE);
    }

    target.unit = T_U_KELVIN;

    #ifdef DEBUG
    printf("target.value: %lf\n", target.value);
    printf("target.unit: %c\n", target.unit);
    printf("Converting to target unit...\n");
    #endif

    // Now convert Kelvin to target unit
    switch (target_unit)
    {
        case T_U_CELSIUS:
            target.value -= CELSIUS_OFFSET;
            break;
        case T_U_FAHRENHEIT:
            target.value = (target.value - CELSIUS_OFFSET) * FAHRENHEIT_FRACTION + FAHRENHEIT_OFFSET;
            break;
        case T_U_KELVIN:
            // Do nothing
            break;
        default:
            // Handle error
            fprintf(stderr, "convert_temperature: Unknown temperature unit.\n");
            exit(EXIT_FAILURE);
    }

    target.unit = target_unit;

    #ifdef DEBUG
    printf("target.value: %lf\n", target.value);
    printf("target.unit: %c\n", target.unit);
    #endif

    // Work smart, not hard

    return target;
}

TEMPERATURE round_temperature(TEMPERATURE temperature, int rounding_places)
{
    temperature.value = round(temperature.value * pow(10, rounding_places)) / pow(10, rounding_places);

    return temperature;
}

// Parsing stufffffff

CONFIG parse_args(int argc, char const *argv[])
{
    CONFIG config;

    // Check if the user provided the correct number of arguments
    // $ ./temp-convert <source_value> <source_unit> -t <target_unit> [-r] [rounding_places]
    // the -r flag is optional
    if (argc < 5)
    {
        // This should be outside`main` but for the sake of simplicity
        // Indexing in argv[0] is always safe since it's the program name
        print_usage_instructions(argv[0]);
        exit(EXIT_FAILURE);
    }

    // Brute force approach to parse arguments
    // Usually getopt or similiar libraries are used

    // Step 1: Parse the CLI

    // Parse temperature value
    double source_value = parse_temp_value(argv[1]);
    config.source.value = source_value;

    // Parse source unit

    // Unit can either be full words, e.g. "celsius" or "kelvin"
    // or abbreviations, e.g. "c" or "k", lowercase or uppercase
    TEMPERATURE_UNIT source_unit = parse_src_temp_unit(argv[0], argv[2]);
    config.source.unit = source_unit;

    // Parse target unit
    // Look for -t flag
    TEMPERATURE_UNIT target_unit = parse_target_temp_unit(argv[0], argv[3], argv[4]);
    config.target.unit = target_unit;

    // Let's see if the user wants to round the result
    // Check if the user provided the rounding_places argument
    // Default is two places
    config.rounding_places = parse_rounding_places(argc, argv);

    return config;
}

double parse_temp_value(char *arg)
{
    // End pointer contains the address of the first character that is not a part of the number
    // or the address of the terminating null byte ('\0') if the entire string is a valid number
    char *endptr = NULL;

    // Set errno to 0 before calling strtod
    errno = 0;

    double source_value = strtod(arg, &endptr);

    // Check if the conversion was successful

    // If the exit_on_error argument is set to true
    // the function exits the program
    // after printing an error message to stderr.

    if (errno == EINVAL)
    {
        // Handle error
        fprintf(stderr, "strtod: %s is not a number.\n", arg);
        perror("strtod");
        exit(EXIT_FAILURE);
    }

    if (errno == ERANGE)
    {
        // Handle error
        fprintf(stderr, "strtod: %s is too large to be represented by a long integer.\n", arg);
        perror("strtod");
        exit(EXIT_FAILURE);
    }

    // Check if the endptr variable is not equal to the null character ('\0')
    // and errno is not covered by the previous if statements
    if (*endptr != '\0')
    {
        // Handle error
        fprintf(stderr, "strtod: Unknown error while trying to convert \"%s\".\n", arg);
        exit(EXIT_FAILURE);
    }

    return source_value;
}

TEMPERATURE_UNIT parse_src_temp_unit(char *program_name, char *arg)
{
    TEMPERATURE_UNIT source_unit = T_U_NONE;

    source_unit = parse_temp_unit(program_name, arg);

    return source_unit;
}

// Don't like the program_name thing...
TEMPERATURE_UNIT parse_target_temp_unit(char *program_name, char *flag, char *val)
{
    // Compare flag with -t
    if (strcmp(flag, "-t") != 0)
    {
        // Handle error
        fprintf(stderr, "Unknown flag: %s\n", flag);
        print_usage_instructions(program_name);
        exit(EXIT_FAILURE);
    }

    TEMPERATURE_UNIT target_unit = T_U_NONE;

    target_unit = parse_temp_unit(program_name, val);

    return target_unit;
}

// Now we only need to implement this logic once... smart!!!
TEMPERATURE_UNIT parse_temp_unit(char *program_name, char *arg)
{
    TEMPERATURE_UNIT source_unit = T_U_NONE;

    size_t source_unit_length = strlen(arg);

    if (source_unit_length == 1)
    {
        // Handle abbreviations
        char source_unit_char = arg[0];

        switch (source_unit_char)
        {
            case 'c':
            case 'C':
                // Handle Celsius
                source_unit = T_U_CELSIUS;
                break;
            case 'f':
            case 'F':
                // Handle Fahrenheit
                source_unit = T_U_FAHRENHEIT;
                break;
            case 'k':
            case 'K':
                // Handle Kelvin
                source_unit = T_U_KELVIN;
                break;
            default:
                // Handle error
                fprintf(stderr, "Unknown temperature unit: %s\n", arg);
                print_usage_instructions(program_name);
                exit(EXIT_FAILURE);
        }
    }
    else
    {
        // Handle full words

        char src_unit_str[100] = "";
        strcpy(src_unit_str, arg);

        // Convert to lowercase
        for (size_t i = 0; i < strlen(src_unit_str); i++)
        {
            src_unit_str[i] = tolower(src_unit_str[i]);
        }

        if (strcmp(src_unit_str, "celsius") == 0)
        {
            // Handle Celsius
            source_unit = T_U_CELSIUS;
        }
        else if (strcmp(src_unit_str, "fahrenheit") == 0)
        {
            // Handle Fahrenheit
            source_unit = T_U_FAHRENHEIT;
        }
        else if (strcmp(src_unit_str, "kelvin") == 0)
        {
            // Handle Kelvin
            source_unit = T_U_KELVIN;
        }
        else
        {
            // Handle error
            fprintf(stderr, "Unknown temperature unit: %s\n", arg);
            print_usage_instructions(program_name);
            exit(EXIT_FAILURE);
        }
    }

    return source_unit;
}

// Parse rounding places
int parse_rounding_places(int argc, char const *argv[])
{
    int rounding_places = 2;
    bool flag_provided = false;

    if (argc < 6)
    {
        return rounding_places;
    }

    // Check if the -r flag is provided
    if (strcmp(argv[5], "-r") == 0)
    {
        flag_provided = true;
    }

    if (argc == 7)
    {
        // Handle rounding places
        rounding_places = safe_strtol(argv[6], true);
    }
    else
    {
        // Handle error
        fprintf(stderr, "You must provide the rounding_places argument if you want to round the result.\n");
        print_usage_instructions(argv[0]);
        exit(EXIT_FAILURE);
    }

    return rounding_places;
}

// This function prints usage instructions
void print_usage_instructions(const char *program_name)
{
    // Looks about right...
    fprintf(stderr, "\033[1mUSAGE\033[0m\n");
    fprintf(stderr, "\t%s <source_value> <source_unit> -t <target_unit> [-r] [rounding_places] \n", program_name);
    fprintf(stderr, "\n");

    fprintf(stderr, "\033[1mOPTIONS\033[0m\n");
    fprintf(stderr, "\t-t\tSpecify source temperature value.\n");
    fprintf(stderr, "\t-u\tSpecify source temperature unit.\n");
    fprintf(stderr, "\t-r\tSpecify rounding places of target value. [optional]\n");
    fprintf(stderr, "\n");
}