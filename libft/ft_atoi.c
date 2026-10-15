#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int signe;
	int resultat;
	int  i;
	signe = 1;
	resultat = 0;
	i = 0;
	while (nptr[i] ==  ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;

	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		resultat  = resultat * 10 + (nptr[i] - '0');
		i++;
	}
	return (signe  * resultat );
}
