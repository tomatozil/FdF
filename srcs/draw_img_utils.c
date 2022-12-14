/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:37:57 by jiyun             #+#    #+#             */
/*   Updated: 2022/10/05 10:38:25 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}

int	ft_compare(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cast_b;
	unsigned char	cast_c;

	cast_b = (unsigned char *)b;
	cast_c = (unsigned char)c;
	while (len--)
	{
		*cast_b = cast_c;
		cast_b++;
	}
	return (b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y)
{
	char	*dst;

	if (!(0 <= x && x < WIDTH && 0 <= y && \
				y < WIDTH * HEIGHT / (data->size_line / 4)))
		return ;
	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = 0xFFFFFF;
}
