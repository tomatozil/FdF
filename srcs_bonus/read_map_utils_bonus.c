/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:58:03 by jiyun             #+#    #+#             */
/*   Updated: 2022/10/05 10:58:07 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
		if (ret > 10000)
			exit (1);
		if ((cnt > 19 && sign == -1) || (ret < 0 && sign == -1))
			return ((int)(-9223372036854775807 - 1));
		else if ((cnt > 19 && sign == 1) || (ret < 0 && sign == 1))
			return ((int)9223372036854775807);
	}
	return ((int)ret * sign);
}
