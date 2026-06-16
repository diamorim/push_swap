*This project has been created as part of the 42 curriculum by damorim-.*

# Libft

## Description

Libft is the first project in the 42 curriculum.

The objective of this project is to recreate a selection of standard C library functions and develop a deeper understanding of fundamental programming concepts such as memory management, pointers, strings, dynamic allocation, and linked lists.

By building this library from scratch, I created a reusable collection of functions that can be used throughout future 42 projects and personal C development.

---

## Instructions

### Compilation

Compile the library by running:

```bash
make
```

This generates the static library:

```bash
libft.a
```

### Cleaning

Remove object files:

```bash
make clean
```

Remove object files and the library:

```bash
make fclean
```

Rebuild everything:

```bash
make re
```

### Using the Library

Include the header file in your source code:

```c
#include "libft.h"
```

Compile your project while linking against the library:

```bash
cc main.c libft.a
```

---

## Library Description

The library is divided into three main sections:

1. Reimplementation of standard libc functions
2. Additional utility functions
3. Bonus linked list functions

All function prototypes are available in `libft.h`.

---

# Part 1 - Libc Functions

The first section consists of recreating commonly used functions from the standard C library while preserving their original behavior whenever possible.

### Character Classification

* `ft_isalpha`
* `ft_isdigit`
* `ft_isalnum`
* `ft_isascii`
* `ft_isprint`

These functions return:

* `1` if the condition is true
* `0` if the condition is false

### String Functions

* `ft_strlen`
* `ft_strlcpy`
* `ft_strlcat`
* `ft_strchr`
* `ft_strrchr`
* `ft_strncmp`
* `ft_strnstr`
* `ft_strdup`

### Memory Functions

* `ft_memset`
* `ft_bzero`
* `ft_memcpy`
* `ft_memmove`
* `ft_memchr`
* `ft_memcmp`
* `ft_calloc`

### Character Conversion

* `ft_toupper`
* `ft_tolower`

### Conversion

* `ft_atoi`

### Notes

Some functions intentionally preserve the behavior and limitations of the original libc implementation. For example, `ft_memcpy` should not be used when memory regions overlap.

For `ft_calloc`, when either `nmemb` or `size` is zero, the function returns a unique pointer that can safely be passed to `free()`.

---

# Part 2 - Additional Functions

The second section contains utility functions that are not part of the standard C library but are frequently useful in future projects.

## String Manipulation

### ft_substr

Allocates and returns a substring from a given string.

### ft_strjoin

Allocates and returns a new string resulting from the concatenation of two strings.

### ft_strtrim

Allocates and returns a copy of a string with specified characters removed from both ends.

### ft_split

Splits a string using a delimiter character and returns an array of newly allocated strings.

## String Iteration

### ft_striteri

Applies a function to each character of a string.

### ft_strmapi

Creates a new string by applying a function to every character of the original string.

## Conversion

### ft_itoa

Converts an integer into its string representation.

## File Descriptor Output

### ft_putchar_fd

Outputs a character to a file descriptor.

### ft_putstr_fd

Outputs a string to a file descriptor.

### ft_putendl_fd

Outputs a string followed by a newline to a file descriptor.

### ft_putnbr_fd

Outputs an integer to a file descriptor.

---

# Part 3 - Bonus: Linked Lists

The bonus section introduces singly linked lists and dynamic data structures.

## Node Creation

### ft_lstnew

Allocates and returns a new list node. The content is initialized with the provided parameter and the next pointer is set to `NULL`.

---

## List Operations

### ft_lstadd_front

Adds a node to the beginning of a list.

### ft_lstadd_back

Adds a node to the end of a list.

### ft_lstlast

Returns the last node of a list.

### ft_lstsize

Returns the total number of nodes in a list.

---

## Memory Management

### ft_lstdelone

Deletes a single node using a specified delete function and frees the node itself.

### ft_lstclear

Deletes and frees an entire list and sets the list pointer to `NULL`.

---

## Iteration and Mapping

### ft_lstiter

Iterates through a list and applies a function to each node's content.

### ft_lstmap

Creates a new list by applying a function to every node's content while preserving the original list.

---

## Features

* Reimplementation of standard libc functions
* Dynamic memory allocation utilities
* String manipulation helpers
* Integer/string conversion functions
* File descriptor output functions
* Linked list implementation
* Static library generation through Makefile
* Reusable codebase for future 42 projects

---

## Testing

The library was tested through:

* Custom test programs
* Comparison with the behavior of the original libc functions
* Edge case validation
* Manual debugging
* Memory leak checking using Valgrind

---

## Resources

The following resources were helpful during the development of this project:

* The C Programming Language — Brian W. Kernighan & Dennis M. Ritchie
* 42 School documentation and subject PDF
* Linux manual pages (`man`)
* GeeksforGeeks
* Stack Overflow
* Various educational YouTube channels
* Discussions with classmates and fellow developers

---

## AI Usage

Artificial Intelligence was only used to help write and format this README file.

The project implementation was completed by the author.

## Learning Outcomes

Through this project I gained practical experience with:

* Memory management
* Pointer arithmetic
* String manipulation
* Dynamic allocation
* Static libraries
* Makefiles
* Linked lists
* Modular programming
* Defensive coding practices

Libft serves as the foundation for future projects in the 42 curriculum and provides a personal standard library that can be reused and expanded over time.
