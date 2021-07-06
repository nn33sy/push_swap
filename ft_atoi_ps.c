#include "pushswap.h"
int	ft_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r'
		|| c == '\n' || c == ' ' || c == ',' || c == '.')
		return (1);
	return (0);
}

static void	ft_initialize(int *sign, double *res)
{
	*sign = 1;
	*res = 0;
}

double	ft_atoi_ps(const char *str)
{
	int			sign;
	double		res;

	ft_initialize(&sign, &res);
	while (*str && ft_space(*str) == 1)
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str && ft_space(*str) == 0)
	{
		if (ft_isdigit(*str) == 0)
			{
                ft_error();
                return (0);
            }
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}