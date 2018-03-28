# hella_shell

![hella shell](https://s31.postimg.org/403ix8w7f/j1_IPt_Uu_IS51_N62_LB5z9_Qhg_r.jpg)


## Table of Contents

* [Description](#description)
* [Purpose](#purpose)
* [Requirements](#requirements)
* [File Structure](#file-structure)
* [Usage](#usage)
* [Examples](#examples)
* [Bugs](#bugs)
* [Authors](#authors)
* [License](#license)


## Description

**hella_shell** is a simple command line interpreter based on the Bash shell, written by Brian Fox in 1989. **hella_shell** is intentionally minimalistic and contains functionality for only the most basic shell tasks - accepting input, parsing the input into a command and its arguments, and executing that input. Error checking is simple and follows Bash conventions.

## Purpose

The purpose of the simple shell project is to understand:
* how a shell works
* PID and PPIDs
* how processes are created
* the three prototypes of `main`
* how the shell uses the `PATH` to find and execute programs
* the `EOF`/"end-of-file" condition

## Requirements

* Must follow [Betty](https://github.com/holbertonschool/Betty/wiki) style and document guidelines
* Allowed editors: `vi`, `vim`, `emacs`
* Must have a `README.md` file
* All header files must be include guarded
* No more than 5 functions per files

## File Structure

* [AUTHORS](https://github.com/aucontraire/simple_shell/blob/docs/AUTHORS) - list of contributors
* [check_helpers.c](https://github.com/aucontraire/simple_shell/blob/docs/check_helpers.c) - helper functions that check for builtins
  * `exit_check` - checks if user_input is `exit`
  * `blank_check` - checks if user_input is `\n`
  * `env_check` - checks if user_input is `env`
* [env_helpers.c](env_helpers.c) - helper functions related to PATH and other environment variables
  * `get_path_count` - gets count of path parts
  * `get_path_array` - tokenizes path to 2d array
  * `find_path` - finds and checks path for given command
  * `print_env` - shell builtin that prints current environment
* [error_helpers.c](error_helpers.c) - helper functions that print appropriate error messages
  * `command_error` - command not found error
  * `exec_error` - command could not execute error
  * `access_error` - user does not have permission to execute command
* [fork_wait_exec.c](fork_wait_exec.c) - process and execution function
* [memory_helpers.c](memory_helpers.c) - helper functions related to memory management
  * `_realloc` - memory reallocation function
  * `free_array` - 2D array freeing function
* [man_1_simple_shell](man_1_simple_shell) - manual page
* [parse_input.c](parse_input.c) - command and argument parsing function
* [shell.c](shell.c) - main function
* [shell.h](shell.h) - header file
* [string_helpers.c](string_helpers.c) - helper functions pertaining to string handling
  * `_strlen` - finds length of a string
  * `_strcmp` - compares two strings
  * `_strdup` - duplicates two strings (including memory management)

## Compilation

```gcc -Wall -Wextra -Werror -pedantic *.c -o hsh```

*GCC 4.8.4 or later only*

## Usage Examples

### Interactive Mode

```c
~/me$ ./hsh
hella_shell$ echo & the bunnymen
& the bunnymen
hella_shell$ pwd
/home/me/hella_shell
hella_shell$
hella_shell$ exit
~/me$
```

### Non-Interactive Mode

```c
~/me$ cat hella_shell.txt | ./hsh
got me feelin' hella shell so let's just keep on codin'
~/me$
```

## Bugs

At this time, there are no known bugs.


## Authors

Lizzie Turner | [GitHub](https://github.com/lizzieturner) | [Twitter](https://twitter.com/_lizzieturner_)  
Omar Contreras | [GitHub](https://github.com/aucontraire) | [Twitter](https://twitter.com/_au_contraire)

## License

**hella_shell** is open source and free to download and use