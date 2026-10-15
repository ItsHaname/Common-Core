#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	int trouve;

	trouve  = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			trouve  = 1;
			break;
		}
		i++;
	}
	if((char)c == '\0')
		return (char*) &s[i];

	if (trouve == 1)
		return (char *)&s[i];
	else
		return NULL;
}

