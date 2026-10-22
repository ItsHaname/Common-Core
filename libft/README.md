*This project was made as part of the 42 curriculum by haait-ba.*

# Libft

## Description

**Libft** is the first project of the 42 Common Core. The goal is to write again some
functions of the standard C library (`libc`) by myself. Then I add some extra useful
functions and some functions to work with linked lists.

The result is a static library, `libft.a`. I can use it again in the next projects
of the curriculum.

The project has three parts:

| Part | What is inside |
|------|----------------|
| **Part 1** | My own version of some `libc` functions |
| **Part 2** | Extra functions (strings, memory allocation, printing) |
| **Part 3** | Linked list functions (`t_list`) |

## Instructions

### Build

```bash
make        # build the library libft.a
make clean  # remove the object files (.o)
make fclean # remove the .o files and libft.a
make re     # build everything again from zero
```

The project is built with `cc` and the flags `-Wall -Wextra -Werror`.

### How to use it

Add the header in your code:

```c
#include "libft.h"
```

Then build your program and link the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

## List of functions

### Part 1 — libc functions

| Type | Functions |
|------|-----------|
| Check a character | `ft_isalpha` `ft_isdigit` `ft_isalnum` `ft_isascii` `ft_isprint` |
| Convert | `ft_toupper` `ft_tolower` `ft_atoi` |
| Strings | `ft_strlen` `ft_strchr` `ft_strrchr` `ft_strncmp` `ft_strnstr` `ft_strlcpy` `ft_strlcat` |
| Memory | `ft_memset` `ft_bzero` `ft_memcpy` `ft_memmove` `ft_memchr` `ft_memcmp` |
| Allocation | `ft_calloc` `ft_strdup` |

### Part 2 — Extra functions

| Function | What it does |
|----------|--------------|
| `ft_substr`   | Takes a part of a string |
| `ft_strjoin`  | Puts two strings together in a new string |
| `ft_strtrim`  | Removes the characters of a set at the start and at the end |
| `ft_split`    | Cuts a string into words, using a separator |
| `ft_itoa`     | Changes an int into a string |
| `ft_strmapi`  | Uses a function on each character (gives a new string) |
| `ft_striteri` | Uses a function on each character (changes the same string) |
| `ft_putchar_fd` `ft_putstr_fd` `ft_putendl_fd` `ft_putnbr_fd` | Write to a file descriptor |

### Part 3 — Linked lists

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function | What it does |
|----------|--------------|
| `ft_lstnew`       | Makes a new node |
| `ft_lstadd_front` | Adds a node at the start |
| `ft_lstadd_back`  | Adds a node at the end |
| `ft_lstsize`      | Counts the nodes |
| `ft_lstlast`      | Gives the last node |
| `ft_lstdelone`    | Deletes one node |
| `ft_lstclear`     | Deletes the whole list |
| `ft_lstiter`      | Uses a function on each node |
| `ft_lstmap`       | Makes a new list by using a function on each node |

## Resources

- `man 3` pages of the libc functions (`man strlcpy`, `man memmove`, ...)
- [C documentation — cppreference](https://en.cppreference.com/w/c)
- [Linked lists in C — GeeksforGeeks](https://www.geeksforgeeks.org/linked-list-data-structure/)
