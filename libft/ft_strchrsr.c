
#include "libft.h"

void	ft_strchrsr(char *str, char s, char r)
{
	size_t	i;

	i = 0;
	if (!str || !s || !r)
		ft_putstr_fd("One of occurence or more doesn't exist", 3);
	while (str[i])
	{
		if (str[i] == s)
			str[i] = r;
		i++;
	}
}
