// Allowed libraries are already included
// DO NOT MODIFY
#include <stdio.h>
#include <stdlib.h>

// Protoypes
void print_christmas_tree(size_t height);
void print_star(size_t height);
void print_tree(size_t height);
void print_trunk(size_t height);

// IMPORTANT REQUIREMENTS/LIMITATIONS
//
// Read the requirements and limitations carefully.
// You can find them in the README.md file.

int main(int argc, char const *argv[])
{
    // TODO: Write your code here

    // Easy: Call the function print_christmas_tree()
    //       with a fixed the height, e.g.: 8

    /* Code */

    // Medium: Call the function print_christmas_tree()
    //         with a value from the command line

    /* Code */

    // Hard: Call the function print_christmas_tree()
    //       like in medium but with limitations (see README.md)

    /* Code */

    return 0;
}

// Do NOT modify this function
void print_christmas_tree(size_t height)
{
    // Example for height = 8
    //
    //      *
    //      #
    //     ###
    //    #####
    //   #######
    //  #########
    // ###########
    //      |

    print_star(height);
    print_tree(height);
    print_trunk(height);

    return;
}

// Implement this function
void print_star(size_t height)
{
    /* Code */

    return;
}

// Implement this function
void print_tree(size_t height)
{
    /* Code */

    return;
}

// Implement this function
void print_trunk(size_t height)
{
    /* Code */

    return;
}