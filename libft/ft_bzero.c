#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	unsigned char *h;
	size_t i ;

	h =(unsigned char*) s;
	i = 0;
	while (i < n)
		h[i++] = 0;


}
