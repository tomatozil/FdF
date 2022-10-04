#include "fdf.h"

void	re_init_data(t_data *data)
{
	data->zoom = ZOOM;
	data->zoom_is_double = FALSE;
	data->projection = ISOMETRIC;
	data->x_angle = 0;
	data->y_angle = 0;
	data->z_angle = 0;
	data->x_shift = 0;
	data->y_shift = 0;
}

void	key_translate(int keycode, t_data *data)
{
	if (keycode == 123)
		data->x_shift += 15;
	if (keycode == 124)
		data-> x_shift -= 15;
	if (keycode == 125)
		data->y_shift -= 15;
	if (keycode == 126)
		data->y_shift += 15;
}

void	key_zoom(int keycode, t_data *data)
{
	if (keycode == 27 && data->zoom_is_double == TRUE)
		data->zoom /= 1.1;
	if (keycode == 24 && data->zoom_is_double == TRUE)
	{
		data->zoom *= 1.1;
		if (data->zoom > 0.95)
			data->zoom = 1;
	}
	if (keycode == 24 && data->zoom_is_double == FALSE && data->zoom >= 1)
		data->zoom += 1;
	if (keycode == 27 && data->zoom_is_double == FALSE && data->zoom >= 1)
	{
		data->zoom -= 1;
		if (data->zoom < 1)
			data->zoom = 0.940319;
	}
}

void	key_rotate(int keycode, t_data *data)
{
	if (keycode == 14)
		data->x_angle -= 0.1;
	if (keycode == 15)
		data->x_angle += 0.1;
	if (keycode == 2)
		data->y_angle -= 0.1;
	if (keycode == 3)
		data->y_angle += 0.1;
	if (keycode == 8)
		data->z_angle -= 0.1;
	if (keycode == 9)
		data->z_angle += 0.1;
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 51)
		re_init_data(data);
	if (keycode == 35)
	{
		data->projection = PARALLEL;
		data->x_angle = 0;
		data->y_angle = 0;
		data->z_angle = 0;
	}
	if (keycode == 34)
		data->projection = ISOMETRIC;
	key_translate(keycode, data);
	key_rotate(keycode, data);
	key_zoom(keycode, data);
	draw_img(data, 0, 0);
	return (0);
}
