/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:54:17 by jiyun             #+#    #+#             */
/*   Updated: 2022/10/05 12:27:25 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_line(t_data *data, int step_x, int step_y)
{
	int	delta_x;
	int	delta_y;
	int	discriminant;

	delta_x = ft_abs(data->end_x - data->start_x);
	delta_y = ft_abs(data->end_y - data->start_y);
	step_x = ft_compare(data->start_x, data->end_x);
	step_y = ft_compare(data->start_y, data->end_y);
	discriminant = delta_x - delta_y;
	while (data->cur_x != data->end_x || data->cur_y != data->end_y)
	{
		my_mlx_pixel_put(data, data->cur_x, data->cur_y);
		if (2 * discriminant + delta_y > 0)
		{
			discriminant -= delta_y;
			data->cur_x += step_x;
		}
		if (data->cur_x == data->end_x && data->cur_y == data->end_y)
			break ;
		if (2 * discriminant - delta_x < 0)
		{
			discriminant += delta_x;
			data->cur_y += step_y;
		}
	}
}

void	draw_background(t_data *data)
{
	int	i;
	int	*img;
	int	tmp;

	tmp = WIDTH * HEIGHT;
	ft_memset(data->addr, 0, tmp * (data->bits_per_pixel / 8));
	img = (int *)(data->addr);
	i = 0;
	while (i < tmp)
	{
		img[i] = BACKGROUND;
		i++;
	}
}

void	draw_img(t_data *data, int x, int y)
{
	draw_background(data);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				set_start(data, x, y);
				set_end(data, x + 1, y);
				draw_line(data, 0, 0);
			}
			if (y < data->height - 1)
			{
				set_start(data, x, y);
				set_end(data, x, y + 1);
				draw_line(data, 0, 0);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
