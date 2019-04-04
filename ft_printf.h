#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# define FT_PRINTF_TYPE "%cCdDiIefgGoOsSuUxXpPbrkm"
# define FT_PRINTF_CONVERSION "#0-+ *.%cCdDiIefgGoOsSuUxXpPbrkmhlL0123456789"

int		ft_printf(const char *format, ...);

typedef struct	s_arg
{
	char		flag;
	int		width;
	int		prec;
	enum
	{
		none,
		hh,
		h,
		l,
		ll
	}		lenth_mod;
	char		type;
	int		size;
}		t_arg
#endif
