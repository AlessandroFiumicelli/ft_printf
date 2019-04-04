
#include <string.h>
#include <stdio.h>

int	main()
{
	int		idx;
	int		isconv;
	char		conversion;
	char		*str="%+2.2ld\n";

	idx = 1;
	isconv = 1;
	while (str[idx] && !strchr("%sSpdDioOuUxXcC", str[idx]))
	{
		if (!strchr("#0-+ *.%sSpdDioOuUxXcChljz0123456789", str[idx]) && !(isconv = 0))
			break ;
		idx++;
	}
	conversion = str[idx];
	printf("%c", conversion);
	return (0);
}
