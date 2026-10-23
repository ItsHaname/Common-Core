*This project has been created as part of the 42 curriculum by haait-ba.*

# Libft

## Description

**Libft** is the first project of the 42 Common Core. The goal is to write again some
functions of the standard C library (`libc`) by myself. Then I add some extra useful
functions and some functions to work with linked lists.

The result is a static library, `libft.a`. I can use it again in the next projects
of the curriculum.

The project has three parts (all of them are mandatory, there is no bonus part):

| Part | What is inside |
|------|----------------|
| **Part 1** | My own version of some `libc` functions (same prototype and same behavior as the original) |
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
The library is made with `ar rcs`.

### How to use it

Add the header in your code:

```c
#include "libft.h"
```

Then build your program and link the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

## Library description

### Part 1 — libc functions

These functions work like the original ones (see `man 3 <name>`).
The only difference is the `ft_` at the start of the name.

#### Check a character

All these functions return **1** if the character is in the class, and **0** if not.

| Prototype | Behavior |
|-----------|----------|
| `int ft_isalpha(int c);` | `c` is a letter (`a-z` or `A-Z`) |
| `int ft_isdigit(int c);` | `c` is a digit (`0-9`) |
| `int ft_isalnum(int c);` | `c` is a letter or a digit |
| `int ft_isascii(int c);` | `c` is an ASCII value (`0` to `127`) |
| `int ft_isprint(int c);` | `c` is printable, space included (`32` to `126`) |

#### Convert

| Prototype | Behavior |
|-----------|----------|
| `int ft_toupper(int c);` | If `c` is a lowercase letter, returns the uppercase letter. Else returns `c` unchanged. |
| `int ft_tolower(int c);` | If `c` is an uppercase letter, returns the lowercase letter. Else returns `c` unchanged. |
| `int ft_atoi(const char *nptr);` | Changes the start of the string into an `int`. Skips white spaces (`' '`, `\t \n \v \f \r`), then reads one optional `+` or `-`, then reads digits. Stops at the first character that is not a digit. Returns `0` if there is no number. |

#### Strings

| Prototype | Behavior |
|-----------|----------|
| `size_t ft_strlen(const char *s);` | Returns the number of characters in `s`, without the final `'\0'`. |
| `char *ft_strchr(const char *s, int c);` | Returns a pointer to the **first** `c` in `s`, or `NULL` if not found. `c` is changed to `char`. It can find the final `'\0'`. |
| `char *ft_strrchr(const char *s, int c);` | Same as `ft_strchr`, but returns the **last** `c` in `s`. |
| `int ft_strncmp(const char *s1, const char *s2, size_t n);` | Compares at most `n` characters (as `unsigned char`). Stops at the first difference or at `'\0'`. Returns `0` if equal, a negative number if `s1 < s2`, a positive number if `s1 > s2`. |
| `char *ft_strnstr(const char *big, const char *little, size_t len);` | Looks for `little` in the first `len` characters of `big`. Returns a pointer to the start of `little` in `big`, or `NULL` if not found. If `little` is empty, returns `big`. Never reads more than `len` characters of `big`. |
| `size_t ft_strlcpy(char *dst, const char *src, size_t size);` | Copies `src` into `dst`, at most `size - 1` characters, and always ends `dst` with `'\0'` (if `size > 0`). Returns the length of `src`. If the return value is `>= size`, the string was cut. |
| `size_t ft_strlcat(char *dst, const char *src, size_t size);` | Adds `src` at the end of `dst`. `size` is the full size of the `dst` buffer. Ends `dst` with `'\0'` if there is space. Returns the length it tried to make: `strlen(dst) + strlen(src)`, or `size + strlen(src)` if `dst` was already `size` long or more. Never reads more than `size` bytes of `dst`. |

#### Memory

These functions work on bytes. They do not stop at `'\0'`.

| Prototype | Behavior |
|-----------|----------|
| `void *ft_memset(void *s, int c, size_t n);` | Fills the first `n` bytes of `s` with the byte `c` (changed to `unsigned char`). Returns `s`. |
| `void ft_bzero(void *s, size_t n);` | Puts `0` in the first `n` bytes of `s`. |
| `void *ft_memcpy(void *dest, const void *src, size_t n);` | Copies `n` bytes from `src` to `dest`. The two zones must not overlap. Returns `dest`. |
| `void *ft_memmove(void *dest, const void *src, size_t n);` | Copies `n` bytes from `src` to `dest`. Works even if the two zones overlap (copies from the end when `dest > src`). Returns `dest`. |
| `void *ft_memchr(const void *s, int c, size_t n);` | Looks for the byte `c` in the first `n` bytes of `s`. Returns a pointer to it, or `NULL`. |
| `int ft_memcmp(const void *s1, const void *s2, size_t n);` | Compares the first `n` bytes (as `unsigned char`). Returns `0` if equal, else the difference of the first different bytes. |

#### Allocation (with `malloc`)

| Prototype | Behavior |
|-----------|----------|
| `void *ft_calloc(size_t nmemb, size_t size);` | Allocates an array of `nmemb` elements of `size` bytes, all set to `0`. If `nmemb` or `size` is `0`, returns a unique pointer that can be given to `free()`. Returns `NULL` if `nmemb * size` is too big (overflow) or if `malloc` fails. |
| `char *ft_strdup(const char *s);` | Returns a new copy of `s`, allocated with `malloc`. Returns `NULL` if `malloc` fails. |

### Part 2 — Extra functions

The functions that return a new string use `malloc`. They return `NULL` if `malloc`
fails, or if a string parameter is `NULL` (except `ft_split`).

| Prototype | Behavior |
|-----------|----------|
| `char *ft_substr(char const *s, unsigned int start, size_t len);` | Returns a new string: the part of `s` that starts at index `start`, with at most `len` characters. If `start` is after the end of `s`, returns an empty string `""`. |
| `char *ft_strjoin(char const *s1, char const *s2);` | Returns a new string: `s1` followed by `s2`. |
| `char *ft_strtrim(char const *s1, char const *set);` | Returns a copy of `s1` without the characters of `set` at the start and at the end. Characters in the middle are kept. |
| `char **ft_split(char const *s, char c);` | Cuts `s` into words, using `c` as separator. Returns a new array of new strings, ended by `NULL`. Empty words are not kept. If one `malloc` fails, frees everything already allocated and returns `NULL`. To free the result: `free()` each string, then `free()` the array. |
| `char *ft_itoa(int n);` | Returns a new string with the number `n` written in base 10. Works with negative numbers and with `INT_MIN`. |
| `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Returns a new string. Each character is the result of `f(index, character)`. `s` is not changed. |
| `void ft_striteri(char *s, void (*f)(unsigned int, char *));` | Calls `f(index, &character)` on each character of `s`. `f` gets the address, so it can change `s` directly. Does nothing if `s` or `f` is `NULL`. |
| `void ft_putchar_fd(char c, int fd);` | Writes the character `c` on the file descriptor `fd`. |
| `void ft_putstr_fd(char *s, int fd);` | Writes the string `s` on `fd`. |
| `void ft_putendl_fd(char *s, int fd);` | Writes the string `s` on `fd`, then a newline `'\n'`. |
| `void ft_putnbr_fd(int n, int fd);` | Writes the number `n` on `fd`. Works with negative numbers and with `INT_MIN`. |

The `_fd` functions do nothing if `fd < 0` or if the string is `NULL`.

### Part 3 — Linked lists

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

- `content`: the data of the node (`void *`, so it can be any type).
- `next`: the address of the next node, or `NULL` for the last node.

| Prototype | Behavior |
|-----------|----------|
| `t_list *ft_lstnew(void *content);` | Allocates a new node with `malloc`. `content` is set to the parameter, `next` is set to `NULL`. Returns the node, or `NULL` if `malloc` fails. |
| `void ft_lstadd_front(t_list **lst, t_list *new);` | Adds the node `new` at the start of the list. `*lst` now points to `new`. |
| `void ft_lstadd_back(t_list **lst, t_list *new);` | Adds the node `new` at the end of the list. If the list is empty, `*lst` becomes `new`. |
| `int ft_lstsize(t_list *lst);` | Returns the number of nodes in the list (`0` if `lst` is `NULL`). |
| `t_list *ft_lstlast(t_list *lst);` | Returns the last node of the list (`NULL` if `lst` is `NULL`). |
| `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Frees the `content` of one node with `del`, then frees the node. Does **not** free the next nodes. |
| `void ft_lstclear(t_list **lst, void (*del)(void *));` | Frees the node `*lst` and all the nodes after it (with `del` and `free`). Then sets `*lst` to `NULL`. |
| `void ft_lstiter(t_list *lst, void (*f)(void *));` | Calls `f` on the `content` of each node. |
| `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` | Makes a new list: each new node has the content `f(old content)`. The old list is not changed. If one `malloc` fails, frees the new list with `del` and returns `NULL`. |

## Resources

- `man 3` pages of the libc functions (`man strlcpy`, `man memmove`, ...)
- [C documentation — cppreference](https://en.cppreference.com/w/c)
- [Linked lists in C — GeeksforGeeks](https://www.geeksforgeeks.org/linked-list-data-structure/)

### How AI was used

- **To understand concepts**: I asked AI to explain some ideas, like memory overlap in
  `memmove`, `strlcpy`/`strlcat` sizes, file descriptors and linked lists.
- **To test**: AI helped me write test programs that compare my functions with the
  real `libc` functions (normal cases, `NULL` cases, memory leaks, `malloc` failure).
  These tests are not in the repository.
- **To review**: AI pointed out some differences with `libc` (`ft_strlcat` and
  `ft_strnstr` with `size`/`len` equal to `0`) and helped me write this README.

All the code of the library was written by me, and I can explain each line.
