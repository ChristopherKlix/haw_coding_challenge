# Exercise 03 - Brrrrr!!! It's cold outside! 🥶

![GitHub](https://img.shields.io/badge/Difficulty-Medium-yellow)

[Watch this video first!](https://youtu.be/placeholder) <- Click here or on the thumbnail below!

[![Watch this video first!](https://img.youtube.com/vi/placeholder/0.jpg)](https://www.youtube.com/watch?v=placeholder)

📖🕯 **Story time! There once was a man called Lord Kelvin...**

_...who said that it was impossible to measure the temperature of a body below absolute zero._

![Lord Kelvin Meme](res/exercise_03_meme_kelvin.png)

This is funny cause 20 degree Celsius is the same as 293.15 Kelvin and 293.15 is a preeeeettty high IQ, soooooo... yeah...

## The Task

In this exercise, you will write a program that **converts** a temperature, for exmaple, **Kelvin to Celsius**.

But first, you will need to **ask the user** for the temperature in Kelvin, via `stdin` _(standard input)_ or **command line argument** _(CLI arguments)_.

Then, you will need to **calculate** the temperature in the target temperature scale.

Finally, you will need to **print** the temperature in to the `stdout` _(standard out)_, i.e., the console.

**The goal is to write a complete and deployable program, i.e., CLI (Command Line Interface).**

### User input

The user will run the program in one of two ways:

- **CLI arguments** - The user will pass the temperature as well as the source and target scale as CLI arguments.
- **stdin/stdout** - The user will be prompted to enter the temperature and the source and target scale.

#### CLI arguments

There are many ways to structure your CLI arguments. But as always, there's an accepted standard way to do it: [standard CLI structure (dev.to post)](https://dev.to/paulasantamaria/command-line-interfaces-structure-syntax-2533).

Keep in mind that CLI argument parsing in `C` is a bit more complicated than in other languages, such as `Python` or `JavaScript`. But it's not impossible.

But here is my suggestion for a more or less standard way to structure your CLI arguments that is not too complicated:

```sh
# Call it like so:

# UNIX:
$ ./temp-conv 293.15 kelvin -t celsius

# example output:
293.15 Kelvin is 20.00 Celsius

# --------------------------------

# Windows:
$ temp-conv.exe 293.15 kelvin -t celsius

# example output:
293.15 Kelvin is 20.00 Celsius
```

You can obviously use any CLI argument structure you want, but the above is the one I will use in the video. Just make sure to adhere to the [standard CLI structure (dev.to post)](https://dev.to/paulasantamaria/command-line-interfaces-structure-syntax-2533), i.e., `./temp_conv <temperature> <source scale> -t <target scale>`.

#### Go beyond: CLI arguments with GNU getopt

If you want to go beyond, you can try the implementation suggested by [chatGPT](https://chat.openai.com/chat). It utilizes the [GNU getopt library](https://www.gnu.org/software/libc/manual/html_node/Getopt.html) to _parse_ the **CLI arguments** that are provided as so called `flags`.

```sh
# Call it like so:

# UNIX:
$ ./temp-convert -t 32 -u F -o C -r 2

# example output:
32.00 Fahrenheit is 0.00 Celsius
```

Where the `-t` flag is the temperature, `-u` is the source scale, `-o` is the target scale, and `-r` is the rounding precision.

**These elements are probably a good starting point for your program:**

- The name of the command, such as temp-convert.
- The option to specify the input temperature value and unit, such as -t or --temperature.
- The option to specify the input temperature unit, such as -u or --unit.
- The option to specify the output temperature unit, such as -o or --output-unit.
- An optional flag to specify whether the output should be rounded to a certain number of decimal places, such as -r or --round.

The CLI could also include a help option, such as `-h` or `--help`, to display usage information and a list of available options.

This would display a usage message explaining how to use the CLI, along with a list of available options and their descriptions.

```sh
# UNIX:
$ ./temp-convert --help
```

```sh
# example output:
Usage: temp-convert [options]

Options:
  -t, --temperature VALUE  The temperature value to convert
  -u, --unit UNIT         The input temperature unit (F, C, K)
  -o, --output-unit UNIT  The output temperature unit (F, C, K)
  -r, --round VALUE       The number of decimal places to round the output to
  -h, --help              Display this usage information
```

### Interactive mode (i.e., scanf's)

If the user does not provide any CLI arguments, the program should/could ask the user for the temperature and the source and target scale.

**! Important:** CLI's usually do not ask the user for input. But this is a learning exercise, so we will do it anyway. Usually, you would just print an error message or usage instructions and exit the program.

**Hint:** You can use `scanf` to read input from the user. But you can also use `getchar` and `fgets` to read input from the user. It's up to you.

<!-- ![Temperature Conversion Meme](res/exercise_03_meme_temps.png) -->

<img src="https://github.com/ChristopherKlix/haw_coding_challenge/blob/main/exercises/exercise_03/res/exercise_03_meme_temps.png" width="400" alt="Temperature Conversion Meme">

Come on, this is funny 😂

## Temperature conversion

Sooooo, how do you convert temperatures? Well, there are many ways to do it. You can check your calculation with the [RapidTables](https://www.rapidtables.com/convert/temperature/index.html) temperature converter.

### Conversion formulas

Your base unit should be `Kelvin`!

```py
# Celsius to Fahrenheit
F = (C * 9/5) + 32
```

```py
# Celsius to Kelvin
K = C + 273.15
```

```py
# Kelvin to Celsius
C = K - 273.15
```

```py
# Kelvin to Fahrenheit
F = (K - 273.15) * 9/5 + 32
```

```py
# Fahrenheit to Celsius
C = (F - 32) * 5/9
```

```py
# Fahrenheit to Kelvin
K = (F - 32) * 5/9 + 273.15
```

You might also implement other scales, such as [Rankine](https://en.wikipedia.org/wiki/Rankine_scale) or [Delisle](https://en.wikipedia.org/wiki/Delisle_scale)... for whatever reason. Like, why would you ever need to convert temperatures to the Delisle scale? 🤔

**Note:** It might be a good idea to store **constants** such as `9/5` and `32` in variables or even macros. This way, you can easily access them anywhere in your code without having to type them out again and again whilst also avoiding typos and the usage of **magic numbers**.

## Rounding

You can use the `round` function to round a number to a certain number of decimal places. But you can also use the `floor` function to round a number down to a certain number of decimal places.

**\*\*Spoiler alert:\*\***
```c
#include <math.h>

double rounded = round(3.14159265358979323846 * 100) / 100;
double floored = floor(3.14159265358979323846 * 100) / 100;
```

Watch the video first where I explain the task in detail.

## Why? Why should I do this?

Well, it simple: **_You should do this because it's fun!_**

And also, because it's a good exercise to get you started with C programming. It's a good way to get your hands dirty and to get a feel for the language. It's also a good way to get started with the command line and to learn how to use the terminal.

### The Real World

Converting temperatures involves some understanding of the C programming language, but it's not _too difficult_, as well as some basic understanding of _maths_. It builds an intuition for **Computer Science** and teaches the **applications** of the C programming language **in the real world**.

Most modern applications are written in a **high-level language**, such as `Python`, `JavaScript`, `Swift`, or alike. But the **operating system**, **CLI's**, and the **hardware** are written in a **low-level language**, such as `C`, `C++`, or `Assembly`.

## How to write a good CLI

- The CLI should be **easy to use**.
- The CLI should be **easy to understand**.
- The CLI should be **easy to maintain**.
- The CLI should be **easy to extend**.

### Looks and Feel

- The CLI does **not have a headline or a title**.
- The CLI does **not print unnecessary stuff**.
- The CLI does **provide status updates**.
- The CLI does **inform about errors or warnings**.
- The CLI does **utilize ASCII chars like `|`, `#`, `=`, etc., to format the `stdout`**.

### A good example

```sh
$ ./temp-convert -t 100 -u C -o F -r 3
----------------------------------------
Converting 100.00 Celcius to Fahrenheit...
(rounded to 3 decimal places)
----------------------------------------
100.00 °C = 212.000 °F
----------------------------------------
✅ Done!
```

This CLI:

- is easy to use
- is easy to understand
- says what is does before doing it
- is well formatted
- utilizes ASCII chars to format the `stdout`
- provides status updates `✅ Done!`
- informs about possible errors or warnings
- is not cluttered with unnecessary stuff

### A bad example

```sh
$ ./temp-convert
#### WELCOME TO THE TEMPERATURE CONVERTER ####
This program converts temperatures from one scale to another.
You can convert from Celsius, Fahrenheit, and Kelvin.
Only positive temperatures are supported.
Enter the temperature value to convert: 100
Enter the input temperature unit (F, C, K): C
Enter the output temperature unit (F, C, K): F
212.00F
```

This CLI:

- is cluttered
- does not say what it does before doing it
- is not well formatted
- does not provide status updates
- is confusing to read
- does provide too much information upfront instead of printing an error message for invalid inputs

### Happy coding!

And remember: **_Don't Panic!_**

## Where is the code?

### The template code

Click on the `src` folder above. Then, click on the `main.c` file. This will open the template code in your browser. You can then copy/paste the code into your IDE or download the file.

```sh
./src/main.c
```

### The solution code

The **solution code** is in the `solution` folder.

```sh
./solution/main.c
```

## Intro video

[Watch the video on YouTube](https://youtu.be/EMrc0KZJh54) <- Click here or on the thumbnail below!

[![Watch this video first!](https://img.youtube.com/vi/EMrc0KZJh54/0.jpg)](https://www.youtube.com/watch?v=EMrc0KZJh54)

## Solution video

Coming soon!

[Watch the video on YouTube](https://youtu.be/gIe5vTqdlLY) <- Click here or on the thumbnail below!

[![Watch this video first!](https://img.youtube.com/vi/gIe5vTqdlLY/0.jpg)](https://www.youtube.com/watch?v=gIe5vTqdlLY)
