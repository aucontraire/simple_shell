hella_shell

# Table of Contents

Description
Project Requirements
File Structure
Usage
Examples
Bugs
Authors
License


**Description**

hella_shell is a simple command line interpreter based on the Bash shell, written by Brian Fox in 1989. hella_shell is intentionally minimalistic and contains functionality for only the most basic shell tasks - accepting input, parsing the input into a command and its arguments, and executing that input. Error checking is simple and follows Bash conventions.

*Project Requirements*
	 * Must follow Betty style and document guidelines
	 * Compiled as follows:
	   	    gcc -Wall -Wextra -Werror -pedantic -o hsh
         * Other requirement
	 * Other requirement

*File Structure*

AUTHORS - list of contributors
check_helpers.c - simple check functions
		* exit_check -
		* blank_check -
		* env_check -

env_helpers.c - helper functions related to PATH and other environment variables
	      	* get_path_count -
		* get_path_array -
		* find_path -
		* print_env -

error_helpers.c - helper functions for error message printing
		* command_error -
		* exec_error -

fork_wait_exec.c - process and execution function

free_array.c - 2D array freeing function

man_1_simple_shell - manual page

parse_input.c - command and argument parsing function

shell.c - main function

shell.h - header file

string_helpers.c - helper functions pertaining to string handling
		 * _strlen - finds length of a string
		 * _strcat - concatenates two strings
		 * _strdup - duplicates two strings (including memory management)

## Compilation

GCC 4.8.6 or later

gcc -Wall -Wextra -Werror -pedantic *.c -o hsh

## Usage Examples

### Interactive Mode

'''c
~/user$ ./hsh
hella_shell$ echo and the bunnymen
hella_shell$ and the bunnymen
hella_shell$
hella_shell$
hella_shell$ exit
~/user$
'''

### Non-Interactive Mode

'''c
~/user$ cat "test.c" | ./hsh
hella_shell$ this is a test file
hella_shell$ isn't is nice
~/user$
'''

## Bugs

At this time, there are no known bugs.


*Authors*

Lizzie Turner | GitHub | Twitter
Omar Contreras | GitHub | Twitter

*License*

hella_shell is open source and free to download and use