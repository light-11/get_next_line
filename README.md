*This project has been created as part of the 42 curriculum by ayanaga.*

# Get Next Line

## Description

Get Next Line (gnl) is a project from the 42 curriculum whose goal is to implement a function capable of reading a file descriptor line by line.

The function `get_next_line()` returns a single line from a file descriptor each time it is called. Successive calls allow the entire content of a file (or standard input) to be read one line at a time.

This project introduces several important concepts in C programming:

* File descriptors
* Static variables
* Dynamic memory allocation
* Buffer management
* Reading from files and standard input
* Memory leak prevention

The mandatory part supports reading from a single file descriptor, while the bonus part supports reading from multiple file descriptors simultaneously.

---

## Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters

* `fd`: File descriptor to read from.

### Return Value

* A line read from the file descriptor.
* `NULL` if there is nothing left to read or if an error occurs.

---

## Algorithm Explanation

### Overview

The function reads data from a file descriptor using `read()` and stores the unread portion in a static variable.

The process is:

1. Read data from the file descriptor into a temporary buffer.
2. Append the newly read data to the previously stored data.
3. Check whether a newline character (`\n`) exists.
4. If a complete line exists:

   * Extract the line.
   * Store the remaining characters for the next call.
5. Return the extracted line.
6. Repeat on subsequent calls.

### Why a Static Variable?

A local variable is destroyed when a function returns.

Because `get_next_line()` only returns one line at a time, any data located after the newline must be preserved for the next call.

Using a static variable allows the function to remember unread data between calls.

Example:

```text
hello
world
```

If the buffer reads:

```text
hello
wor
```

The function returns:

```text
hello
```

and stores:

```text
wor
```

for the next call.

### Bonus Algorithm

The bonus version stores a separate buffer for each file descriptor:

```c
static char *copy[OPEN_MAX];
```

Each file descriptor keeps its own unread data, allowing multiple files to be read independently.

---

## Instructions

### Compilation

Mandatory:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c
```

Bonus:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line_bonus.c get_next_line_utils_bonus.c
```

### Testing Example

```c
int fd = open("test.txt", O_RDONLY);

char *line;

while ((line = get_next_line(fd)))
{
	printf("%s", line);
	free(line);
}
```

### Standard Input

The function can also read from standard input:

```c
get_next_line(0);
```

---

## Technical Choices

### Dynamic Memory Allocation

Memory is allocated dynamically to:

* Store data read from the file descriptor
* Return a line of arbitrary length
* Preserve unread content between calls

### Buffer Size Independence

The implementation is designed to work with different values of:

```c
BUFFER_SIZE
```

including:

```text
1
42
9999
```

The function continues reading until a complete line is available.

---

## Resources

### Official Documentation

* Linux Manual Pages:

  * `man read`
  * `man open`
  * `man malloc`
  * `man free`

### References

* The C Programming Language (Kernighan & Ritchie)
* GNU C Library Documentation
* 42 Subject PDF

### Useful Articles

* Understanding File Descriptors
* Static Variables in C
* Dynamic Memory Allocation in C

---

## AI Usage

AI tools were used as a learning aid during the development of this project.

Usage included:

* Understanding project requirements
* Reviewing code structure
* Debugging compilation errors
* Explaining concepts such as:

  * static variables
  * file descriptors
  * memory allocation
  * pointer manipulation
* Reviewing edge cases and testing strategies

All design decisions, implementation, debugging, and final code were completed and verified by the author.