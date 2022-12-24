# Exercise 01 - Ho ho ho!
[Watch this video first!](https://youtu.be/ClOBza7CfI0) <- Click here or on the thumbnail below!

[![Watch this video first!](https://img.youtube.com/vi/ClOBza7CfI0/0.jpg)](https://www.youtube.com/watch?v=ClOBza7CfI0)

🎄⛄️ **Ho ho ho! Merry Christmas!**

Today's exercise is very simple but fun.

All you have to do is to print a Christmas tree to the console.

...with a star on top!

...and a trunk!

But there is a catch... hehehe.

```c
// Example with height of 6

    *
    #
   ###
  #####
 #######
    |
```

## The rules

The rules are simple:

- The tree should be printed in 3 parts: star, tree, trunk.
- The height should be dynamic. **At least 4!**
- The star should be printed in the middle of the first line.
- The tree layers should be **centered/odd numbers** of `#` characters.
- The trunk should be printed in the middle of the last line.
- The last layer of the tree should have a margin of 1 space on each side.

The height should be given as an argument to the `print_christmas_tree()` function.

**Min value: 4**

**Only even numbers are allowed, e.g.: 4, 6, 8, 10, 12, etc.**

```c
// Example with height of 8

      *
      #
     ###
    #####
   #######
  #########
 ###########
      |
```

### Difficulty levels

You can complete the task in 3 different difficulty levels:

#### Easy

Just call the `print_christmas_tree()` function with **a fixed height** as an argument.

e.g.:

```c
print_christmas_tree(6);
```

You can also use the `#define` directive to define a constant.

Then, you may use a combination of `for-loops` and `printf()` to print the tree.

#### Medium

Call the `print_christmas_tree()` function with **a dynamic height** as an argument from the **Command Line**.

e.g.:

```sh
# UNIX
./main 6

# Windows
main.exe 6
```

You can use the `atoi()` function to convert the string to an integer or go beyond and use the `strtol()` function to convert the string to a long integer and do some **error checking**.

`strtol`: [https://devdocs.io/c/string/byte/strtol](https://devdocs.io/c/string/byte/strtol)

#### Hard

Everything from the Medium level, but also:

```c
void print_star(size_t height)
```

and

```c
void print_trunk(size_t height)
```

may **NOT** use a `for-loop`!

**You are only allowed to use 2 `for-loops` in total!**

**Hint:** _You can use the `printf()` function to print multiple characters at once._

`printf()`: [https://devdocs.io/c/io/fprintf](https://devdocs.io/c/io/fprintf)

Check out this if you have no idea how to do it:

[https://stackoverflow.com/...](https://stackoverflow.com/questions/7899119/what-does-s-mean-in-printf) <- solution here!!!

## The task

Watch the video first where I explain the task in detail.


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

Available on 24.12.2022.

## Solution video

Available on 25.12.2022.
