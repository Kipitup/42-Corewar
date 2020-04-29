#include "libft.h"

t_bool	atoi_overflow(const char *str, int *result)
{
	int			prev;
	signed char	positive;
	t_bool		overflow;

	overflow = false;
	if (!str || !result)
		return (overflow);
	positive = 1;
	*result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			positive = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		prev = *result;
		*result = *result * 10 + (*(str++) - '0') * positive;
		if ((*result < prev && positive) || ((*result > prev && !positive)))
			overflow = true;
	}
	return (overflow);
}

/*
** Convert a number written in ascci to the pointed int in parameters.
** If the pointed value is overflowed the function return 1, else 0.
** <I> Before the number is stored, the value pointed is set to 0 but only
** if the string and pointer are not NULL.
*/