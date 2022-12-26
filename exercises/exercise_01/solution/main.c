// Allowed libraries are already included
// DO NOT MODIFY
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Protoypes
void print_int_array(int *arr, size_t arr_len);
int sum_int_array(int *arr, size_t arr_len);
double average_int_array(int *arr, size_t arr_len);

// IMPORTANT REQUIREMENTS/LIMITATIONS
//
// Read the requirements and limitations carefully.
// You can find them in the README.md file.

int main(int argc, char const *argv[])
{
    // Predefined length of int array
    size_t numbers_len = 50;

    // Predefined pointer to array
    int *numbers_arr = malloc(numbers_len * sizeof(*numbers_arr));

    // Check for failed memory allocation
    if (numbers_arr == NULL)
    {
        printf("Memory could not be allocated. Terminating program.\n");
        exit(EXIT_FAILURE);
    }

    // TODO: Write your code here

    // Step 0: Fill Array with Random Numbers
    //         Range: [0, 99] inclusive

    unsigned int seed = time(NULL);
    srand(seed);

    for (size_t i = 0; i < numbers_len; i++)
    {
        int random_number = rand() % 100;
        numbers_arr[i] = random_number;
    }

    // Step 1: Compute sum of the array

    int sum = sum_int_array(numbers_arr, numbers_len);

    // Step 2: Compute average of the array

    double average = average_int_array(numbers_arr, numbers_len);

    // Step 3: Print array with print_int_array()

    print_int_array(numbers_arr, numbers_len);

    // Step 4: Print sum of the array

    printf("Sum of the array: %d\n", sum);

    // Step 5: Print average of the array

    printf("Average of the array: %4.1lf\n", average);

    // Step 6: Free memory
    free(numbers_arr);

    return 0;
}

// Implement this function
void print_int_array(int *arr, size_t arr_len)
{
    for (size_t i = 0; i < arr_len; i++)
    {
        printf("%3d", arr[i]);
    }

    printf("\n");

    return;
}

// Implement this function
int sum_int_array(int *arr, size_t arr_len)
{
    int sum = 0;

    for (size_t i = 0; i < arr_len; i++)
    {
        sum += arr[i];
    }

    return sum;
}

// Implement this function
double average_int_array(int *arr, size_t arr_len)
{
    double average = 0;
    double sum = sum_int_array(arr, arr_len);

    average = sum / arr_len;

    return average;
}