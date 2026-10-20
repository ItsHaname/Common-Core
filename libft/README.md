*Ce projet a été réalisé dans le cadre du cursus 42 par haait-ba.*

# Libft

## Description

**Libft** est le premier projet du Common Core de 42. Le but est de recoder une partie
des fonctions de la bibliothèque standard du C (`libc`), puis d'ajouter des fonctions
utilitaires et des fonctions de manipulation de listes chaînées.

Le résultat est une bibliothèque statique, `libft.a`, réutilisable dans les projets suivants
du cursus.

Le projet est découpé en trois parties :

| Partie | Contenu |
|--------|---------|
| **Partie 1** | Réimplémentation de fonctions de la libc |
| **Partie 2** | Fonctions utilitaires supplémentaires (chaînes, allocation, affichage) |
| **Bonus**    | Manipulation de listes chaînées (`t_list`) |

## Instructions

### Compilation

```bash
make        # compile la bibliothèque libft.a
make clean  # supprime les fichiers objets (.o)
make fclean # supprime les .o et libft.a
make re     # recompile tout depuis zéro
```

Le projet est compilé avec `cc` et les flags `-Wall -Wextra -Werror`.

### Utilisation

Inclure le header dans ton code :

```c
#include "libft.h"
```

Puis compiler en liant la bibliothèque :

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o programme
```

## Liste des fonctions

### Partie 1 — Fonctions de la libc

| Catégorie | Fonctions |
|-----------|-----------|
| Tests de caractères | `ft_isalpha` `ft_isdigit` `ft_isalnum` `ft_isascii` `ft_isprint` |
| Conversion | `ft_toupper` `ft_tolower` `ft_atoi` |
| Chaînes | `ft_strlen` `ft_strchr` `ft_strrchr` `ft_strncmp` `ft_strnstr` `ft_strlcpy` `ft_strlcat` |
| Mémoire | `ft_memset` `ft_bzero` `ft_memcpy` `ft_memmove` `ft_memchr` `ft_memcmp` |
| Allocation | `ft_calloc` `ft_strdup` |

### Partie 2 — Fonctions supplémentaires

| Fonction | Rôle |
|----------|------|
| `ft_substr`   | Extrait une sous-chaîne |
| `ft_strjoin`  | Concatène deux chaînes dans une nouvelle |
| `ft_strtrim`  | Retire les caractères d'un set au début et à la fin |
| `ft_split`    | Découpe une chaîne selon un séparateur |
| `ft_itoa`     | Convertit un entier en chaîne |
| `ft_strmapi`  | Applique une fonction à chaque caractère (nouvelle chaîne) |
| `ft_striteri` | Applique une fonction à chaque caractère (sur place) |
| `ft_putchar_fd` `ft_putstr_fd` `ft_putendl_fd` `ft_putnbr_fd` | Écriture sur un file descriptor |

### Bonus — Listes chaînées

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Fonction | Rôle |
|----------|------|
| `ft_lstnew`       | Crée un nouvel élément |
| `ft_lstadd_front` | Ajoute un élément au début |
| `ft_lstadd_back`  | Ajoute un élément à la fin |
| `ft_lstsize`      | Compte le nombre d'éléments |
| `ft_lstlast`      | Renvoie le dernier élément |
| `ft_lstdelone`    | Supprime un élément |
| `ft_lstclear`     | Supprime toute la liste |
| `ft_lstiter`      | Applique une fonction à chaque élément |
| `ft_lstmap`       | Crée une nouvelle liste en appliquant une fonction |

## Ressources

- `man 3` des fonctions de la libc (`man strlcpy`, `man memmove`, ...)
- [Documentation C — cppreference](https://en.cppreference.com/w/c)
- [Listes chaînées en C — GeeksforGeeks](https://www.geeksforgeeks.org/linked-list-data-structure/)
