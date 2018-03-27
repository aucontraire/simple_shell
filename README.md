![hella shell](https://s31.postimg.org/403ix8w7f/j1_IPt_Uu_IS51_N62_LB5z9_Qhg_r.jpg)


## Table of Contents

* [Description](#description)
* [Project Requirements](#project-requirements)
* [File Structure](#file-structure)
* [Usage](#usage)
* [Examples](#examples)
* [Bugs](#bugs)
* [Authors](#authors)
* [License](#license)


## Description

**hella_shell** is a simple command line interpreter based on the Bash shell, written by Brian Fox in 1989. **hella_shell** is intentionally minimalistic and contains functionality for only the most basic shell tasks - accepting input, parsing the input into a command and its arguments, and executing that input. Error checking is simple and follows Bash conventions.

## Project Requirements

* Must follow Betty [style](https://github.com/holbertonschool/Betty/wiki#1-coding-style) and document guidelines
* Compiled as follows:
`gcc -Wall -Wextra -Werror -pedantic -o hsh`
* Other requirement
* Other requirement

## File Structure

[AUTHORS](https://github.com/aucontraire/simple_shell/blob/docs/AUTHORS) - list of contributors  

[check_helpers.c](https://github.com/aucontraire/simple_shell/blob/docs/check_helpers.c) - simple check functions  
		* exit_check -  
		* blank_check -  
		* env_check -  

[env_helpers.c](env_helpers.c) - helper functions related to PATH and other environment variables
	      	* get_path_count -  
		* get_path_array -  
		* find_path -  
		* print_env -   

[error_helpers.c](error_helpers.c) - helper functions for error message printing
		* command_error -  
		* exec_error -  

[fork_wait_exec.c](fork_wait_exec.c) - process and execution function

[free_array.c](free_array.c) - 2D array freeing function

[man_1_simple_shell](man_1_simple_shell) - manual page

[parse_input.c](parse_input.c) - command and argument parsing function

[shell.c](shell.c) - main function

[shell.h](shell.h) - header file

[string_helpers.c](string_helpers.c) - helper functions pertaining to string handling
		 * _strlen - finds length of a string
		 * _strcat - concatenates two strings
		 * _strdup - duplicates two strings (including memory management)

## Compilation

```gcc -Wall -Wextra -Werror -pedantic *.c -o hsh```

## Usage Examples

### Interactive Mode

```c
~/me$ ./hsh
hella_shell$ echo and the bunnymen
and the bunnymen
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

Lizzie Turner | [GitHub](github.com/lizzieturner) | [Twitter](twitter.com/_lizzieturner_)

Omar Contreras | GitHub | Twitter

## License

hella_shell is open source and free to download and use