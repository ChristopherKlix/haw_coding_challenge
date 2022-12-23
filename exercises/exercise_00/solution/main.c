// Allowed libraries are already included
// DO NOT MODIFY
#include <stdio.h>
#include <stdlib.h>

// Marcos
#define WINDOW_WIDTH 80
#define DELIMITER_CHAR '='

// Protoypes
void print_delimiter(char delimiter, size_t count);


// IMPORTANT REQUIREMENTS/LIMITATIONS
//
// Read the requirements and limitations carefully.
// You can find them in the README.md file.

int main(int argc, char const *argv[])
{
    // TODO: Write your code here

    // Step 0: Print the starting delimiter

    print_delimiter(DELIMITER_CHAR, WINDOW_WIDTH);

    // Step 1: Print the following message:
    //         "Hello REE!"

    printf("Hello REE!\n");

    // Step 2: Print the ending delimiter

    print_delimiter(DELIMITER_CHAR, WINDOW_WIDTH);

    return 0;
}

// Implement this function
void print_delimiter(char delimiter, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        printf("%c", delimiter);
    }

    printf("\n");

    return;
}