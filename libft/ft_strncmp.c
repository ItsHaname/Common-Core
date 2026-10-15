#include "libft.h"

int	ft_strncmp(const char* s1, const char  *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i >= n && s1[i])
	{
		return(s2[i] - s1[i]);
		i++;
	}
}
#include<stdio.h>
int main()
{
	const char *s1 = "hanane";
	const char *s3 = "hanane";
	size_t n = 4;
	printf ("%d",ft_strncmp(s1,s3,n));
	return 0;
}
