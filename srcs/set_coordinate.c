/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:40:52 by jiyun             #+#    #+#             */
/*   Updated: 2022/10/05 10:41:50 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_zoom(t_data *data)
{
	double	zoom;

	if (data->zoom >= 1)
	{
		zoom = (int)data->zoom;
		data->zoom_is_double = FALSE;
	}
	else
	{
		zoom = data->zoom;
		data->zoom_is_double = TRUE;
	}
	return (zoom);
}

void	set_start(t_data *data, int x, int y)
{
	double	zoom;

	zoom = get_zoom(data);
	data->start_x = x * zoom;
	data->start_y = y * zoom;
	data->start_z = data->map[y][x] * zoom;
	rot_x(&data->start_y, &data->start_z, data->x_angle);
	rot_y(&data->start_x, &data->start_z, data->y_angle);
	rot_z(&data->start_x, &data->start_y, data->z_angle);
	if (data->projection == ISOMETRIC)
		isometric(&data->start_x, &data->start_y, data->start_z);
	data->start_x += WIDTH / 2 + data->x_shift;
	data->start_y += HEIGHT / 2 + data->y_shift;
	data->cur_x = data->start_x;
	data->cur_y = data->start_y;
}

void	set_end(t_data *data, int x, int y)
{
	double	zoom;

	zoom = get_zoom(data);
	data->end_x = x * zoom;
	data->end_y = y * zoom;
	data->end_z = data->map[y][x] * zoom;
	rot_x(&data->end_y, &data->end_z, data->x_angle);
	rot_y(&data->end_x, &data->end_z, data->y_angle);
	rot_z(&data->end_x, &data->end_y, data->z_angle);
	if (data->projection == ISOMETRIC)
		isometric(&data->end_x, &data->end_y, data->end_z);
	data->end_x += WIDTH / 2 + data->x_shift;
	data->end_y += HEIGHT / 2 + data->y_shift;
}
