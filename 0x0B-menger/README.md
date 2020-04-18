# 0x0B. Menger sponge
## Specializations - Interview Preparation ― Algorithms

![Menger](https://i.imgur.com/wIFLtnU.png)
## Tasks

Write a function that draws a 2D Menger Sponge

Prototype: void menger(int level);
Where level is the level of the Menger Sponge to draw
If level is lower than 0, your function must do nothing
You’re allowed to use the math library. Your program will be compiled using the ld flag -lm
Format:

First, read Menger sponge
Here, we will only draw a 2D version of the Menger sponge, but the principle is the same
A level N sponge is a 3x3 square of level N-1 sponges, except for the center one, which is left empty
A level 0 sponge is represented by the # character
Examples:
A level 0 sponge is a simple 1x1 square
A level 1 sponge is a 3x3 square of level 0 sponges, except for the center one, which is left empty
A level 2 sponge is a 3x3 square of level 1 sponges, except for the center one, which is left empty
…
TIP: The size of a level N Menger sponge is calculated as follows: 3^N


## General requirements
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 14.04 LTS
* Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All your files should end with a new line
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* You are not allowed to use global variables
* No more than 5 functions per file
* In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
* The prototypes of all your functions should be included in your header file called menger.h
* Don’t forget to push your header file
* All your header files should be include guarded

## Installation
In your terminal, git clone the directory with the following command:
```
git clone https://github.com/rodrigocruz13/holbertonschool-interview_prep
cd 0x05-menger
```

Compile the files using:

```
gcc -Wall -Wextra -Werror -pedantic -o 0-menger -g 0-menger.c 0-main.c -lm
```

## Usage

Run the program using

```
./0-menger
```
