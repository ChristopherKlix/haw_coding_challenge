#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

// OS-specific clear screen function
#ifdef _WIN32
void clear_screen()
{
    system("cls");
}
#else
void clear_screen()
{
    system("clear");
}
#endif

// This function is a proxy for `safely_convert_string_to_long()`
// It allows for a more succinct call to the function.
//
// This function is used to safely convert a string to a long integer.
// It checks for errors and exits the program if an error occurs
// if the exit_on_error argument is set to true
// after printing an error message to stderr.
// Otherwise, it returns zero.
long safe_strtol(const char *str, bool exit_on_error)
{
    return safely_convert_string_to_long(str, exit_on_error);
}

// This function is used to safely convert a string to a long integer.
// It checks for errors and exits the program if an error occurs
// if the exit_on_error argument is set to true
// after printing an error message to stderr.
// Otherwise, it returns zero.
long safely_convert_string_to_long(const char *str, bool exit_on_error)
{
    // The endptr argument is used to store a pointer
    // to the first character in the string
    // that could not be successfully converted.
    // If this pointer is not equal
    // to the null character ('\0') at the end of the string,
    // it means that not all of the characters
    // in the string could be converted, indicating an error,
    // or if the number is too large to be represented by a long integer,
    // pointing to the first character that could not be converted anymore.
    char *endptr;

    // The errno global variable is also checked
    // to see if any errors occurred during the conversion.
    // We set it to 0 before the conversion
    // to overwrite possible earlier calls to strtol().
    // If the string provided is not a valid number,
    // strtol will set errno to EINVAL.
    // If the number is too large to be represented by a long integer,
    // it will set errno to ERANGE.
    errno = 0;

    // The strtol() function converts the initial part of the string
    // in the string argument to a long integer value according to the given base,
    // which must be between 2 and 36 inclusive, or be the special value 0.
    //
    // Error cases:
    //
    // Case 1: Not a valid number
    //
    // If the provided string is not a valid number,
    // the function returns 0 and sets errno to EINVAL,
    // and set the endptr variable to point
    // to the first character in the string
    // that could not be converted.
    //
    // Case 2: Number too large to be represented by a long integer
    //
    // If the number is too large to be represented by a long integer,
    // the function returns LONG_MAX or LONG_MIN
    // (depending on the sign of the number)
    // and sets errno to ERANGE,
    // and set the endptr variable to point
    // to the first character in the string
    // that could not be converted anymore.
    long number = strtol(str, &endptr, BASE_10);

    // Check if an error occurred
    // See previous comment for more information
    // when which error can occur

    // If the exit_on_error argument is set to false
    // the function returns zero.
    if (!exit_on_error)
    {
        if (errno != 0 || *endptr != '\0')
        {
            return 0;
        }
    }

    // If the exit_on_error argument is set to true
    // the function exits the program
    // after printing an error message to stderr.

    if (errno == EINVAL)
    {
        // Handle error
        fprintf(stderr, "strtol: %s is not a number.\n", str);
        perror("strtol");
        exit(EXIT_FAILURE);
    }

    if (errno == ERANGE)
    {
        // Handle error
        fprintf(stderr, "strtol: %s is too large to be represented by a long integer.\n", str);
        perror("strtol");
        exit(EXIT_FAILURE);
    }

    // Check if the endptr variable is not equal to the null character ('\0')
    // and errno is not covered by the previous if statements
    if (*endptr != '\0')
    {
        // Handle error
        fprintf(stderr, "strtol: Unknown error while trying to convert \"%s\".\n", str);
        exit(EXIT_FAILURE);
    }

    // Return the converted number
    return number;
}