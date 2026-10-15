#ifndef LIBFT_H
#define LIBFT_H
#include<stddef.h>
#include<stdlib.h>
/*Manipulation des chars*/
int isalpha(int c);
int isdigit(int c);
int isalnum(int c);
/*Manipulation des string*/
size_t	ft_strlen(const char *s);
void	*memset(void *s, int c, size_t n);
#endif
