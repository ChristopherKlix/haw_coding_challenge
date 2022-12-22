# HAW Coding Challenge 2022

🏆💻 Welcome to the **HAW Coding Challenge 2022**!

This repository contains the exercises for the **HAW Coding Challenge 2022**.

Each day a _new exercise_ will be published. Do your best to complete the exercise and **follow the instructions**.

At the end of the day, the **best solution** will be selected and the winner will be announced.
...wait, there is no prize. 🤔

Anyway, you can learn **a lot** by doing this challenge.

And it's Eger-approved! 🤓

And at the end of each day a solution together with a **detailed explanation video/tutorial** will be published to the folder of the exercise.

## Questions

If you have questions, feel free to ask them in the group chat or hit me up on WhatsApp.

**This challenge is open to everyone. You can participate individually or in a team.**

### Happy coding!

And remember: **_Don't Panic!_**

## How to participate

Go into the folder of the exercise and read the `README.md` file (it is automatically shown on GitHub when you click on the folder above).

The `README.md` file contains the instructions for the exercise.

The `main.c` file contains the template code for the exercise. You **MUST NOT** modify the template code.

Download or copy/paste the template code into your IDE and start coding.

## Template Code

Each exercise has a template code.

The template code is a **starting point** for the exercise.

The template code **MUST NOT** be modified.

The predefined parameter, variables,
and function names **MAY NOT** be modified.
You may also **NOT** _add/remove_ parameters

### Parameters

```c
// Template code:
int print_int_array(int *arr, size_t arr_len)
{
    // ...

    return 0;
}

// DO NOT MODIFY LIKE THIS:
// i.e., changed parameter name
//       change parameter type
int print_int_array(int *array, int count)
{
    // ...

    return 0;
}
```

### Headers & Libraries

You may use any of the given libraries. Unless explicitly stated you MAY NOT include any other libraries.

```c
// Template code:
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // compute string length
    // size_t str_len = ...

    return 0;
}

// DO NOT MODIFY LIKE THIS:
// i.e., added library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>    // <-- DO NOT ADD THIS

int main(int argc, char const *argv[])
{
    // compute string length
    size_t str_len = strlen("Hello World");    // <-- TO USE strlen() HERE

    return 0;
}
```

## Important Requirements/Limitations

The code should respect certain requirements and limitations to be considered a "correct" solution to the problem.

The code _should_ be OS-independent.
It **HAS** to be compatible with UNIX.
i.e., Ubuntu, Linux, macOS, etc.

### OS-dependent headers

This means that the following libraries should not be used:

```c
// Only on Windows
#include <windows.h>

// Only on UNIX
#include <unistd.h>
#include <pthreads.h>
```

or be integrated via OS-dependent code with the preprocessor:

```c
#ifdef _WIN32
    // Windows code
    #include <windows.h>
#else
    // UNIX code
    #include <unistd.h>
    #include <pthreads.h>
#endif
```

### Clear screen via `system()`

Another example is the use of the `system()` function.
The passed parameter is OS-dependent. Therefore, it should be implemented via a preprocessor directive.

```c
#ifdef _WIN32
// Windows implementation
void clear_screen(void)
{
    system("cls");

    return;
}
#else
// UNIX implementation
void clear_screen(void)
{
    system("clear");

    return;
}
#endif

// Call it as usual
int main(int argc, char const *argv[])
{
    clear_screen();

    return 0;
}
```

### Console I/O

All _stdin/stdout_ (standard in/standard out) is only allowed in `main()`
or **dedicated print functions**.

i.e., `printf()`, `fprintf()`, `scanf()`, etc.

For example: `print_int_array()`.

Keep your code clean and make sure that it is obvious where the _input/output_ is happening.

### File I/O

All _file I/O_ is only allowed in **dedicated file I/O functions**.

i.e., `fopen()`, `fclose()`, `fread()`, `fwrite()`, etc.

For example: `read_file()`, `write_file()`.

Keep your code clean and make sure that it is obvious where the _file I/O_ is happening.

### Error handling

The following error checking should be done:

- NULL ptr checking
- Value conversion/casting (e.g., double -> int)
- Memory leaks (e.g., free memory, etc.)
- User input (e.g., scanf, etc.)
- File I/O (e.g., file exists, file is readable, etc.)
- Command line arguments (e.g., argc, argv, etc.)

Errors should be handle in **one of two ways**:

- exit program, if not executable otherwise

    ```c
    exit(EXIT_FAILURE);

    // or

    exit(1);
    ```

- return a safe value for continued execution if it makes sense

    ```c
    return 0;
    ```
