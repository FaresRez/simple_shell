# 0x16. C - Simple Shell

This repository contains the implementation of the simple shell group project for ALX africa.
The gates of shell is an end of trimester project that helps students understand and implement the advanced concepts behind the shell program including processes, system calls, bit manipulation, file management, error handling, ...
Shell is a simple UNIX command interpreter that replicates functionalities of the simple shell (sh).

This program was written entirely in C Language.

## AUTHORS

this project is created by Cohort 13 students :
- Zaineb Hammouda
- Fares1 Rezgui

## FEATURES

- Display a prompt and wait for the user to type a command.
- Handle errors.
- handle the “end of file” condition (Ctrl+D)
- handle the PATH
- implement built-ins
- handle commands with arguments
- Implement the exit built-in with and without status
- Implement the env built-in, that prints the current environment
- Implement the setenv and unsetenv builtin commands
- Implement the builtin command cd

## COMPILATION  

our shell will be compiled this way:
```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh ```

##TESTING

our shell works like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
