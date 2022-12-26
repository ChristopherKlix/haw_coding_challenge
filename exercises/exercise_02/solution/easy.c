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

    print_christmas_tree(20);

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
    int tree_layers = height - 1 - 1;

    for (size_t i = 0; i < tree_layers; i++)
    {
        printf(" ");
    }

    printf("*\n");

    return;
}

// Implement this function
void print_tree(size_t height)
{
    // Layers equals height - 1 (star) - 1 (trunk)
    // e.g.: height = 8 -> layers = 6
    int tree_layers = height - 1 - 1;

    // Width equals height + 1 to center the leaves
    // e.g.: height = 8 -> width = 11
    int tree_width = (tree_layers * 2) - 1;

    // Width of the tree plus a space on each side
    //  e.g.: height = 8 -> total_width = 13
    int total_width = tree_width + 2;

    for (int i = 0; i < tree_layers; i++)
    {
        int spaces = tree_layers - i;
        int hashes = total_width - (spaces * 2);

        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < hashes; j++)
        {
            printf("#");
        }

        printf("\n");
    }

    return;
}

// Implement this function
void print_trunk(size_t height)
{
    int tree_layers = height - 1 - 1;

    for (size_t i = 0; i < tree_layers; i++)
    {
        printf(" ");
    }

    printf("|\n");

    return;
}