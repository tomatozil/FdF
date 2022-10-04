//
// Created by jiyun on 2022/09/24.
//
#include "fdf.h"

int	ft_atoi(const char *str)
{
	int		cnt;
	int		sign;
	long	ret;

	cnt = 0;
	sign = 1;
	ret = 0;
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while ('0' <= *str && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		cnt++;
		str++;
		if ((cnt > 19 && sign == -1) || (ret < 0 && sign == -1))
			return ((int)(-9223372036854775807 - 1));
		else if ((cnt > 19 && sign == 1) || (ret < 0 && sign == 1))
			return ((int)9223372036854775807);
	}
	return ((int)ret * sign);
}