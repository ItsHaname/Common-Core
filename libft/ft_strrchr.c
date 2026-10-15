#include "libft.h"

char  *ft_strrchr(const char  *s, int c)
{
	int trouve;
	int len;
	int  i;

	len = ft_strlen(s);
	trouve  = 0;
	i = len;
	while (i > 0)
	{
		if (s[i] == (char)c)
		{
			trouve  =  1;
			break;
		}
		i--;
	}
	if (trouve  == 1)
			return (char*) &s[i];
	return NULL;

}
