/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:38:10 by jiyun             #+#    #+#             */
/*   Updated: 2022/10/05 11:47:02 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data(t_data *data)
{
	data->bits_per_pixel = 0;
	data->size_line = 0;
	data->endian = 0;
	data->height = 0;
	data->width = 0;
	data->color = 0xFFFFFF;
	data->zoom = ZOOM;
	data->zoom_is_double = 0;
	data->projection = ISOMETRIC;
	data->x_shift = 0;
	data->y_shift = 0;
}

int	red_button(int exitcode)
{
	exit(exitcode);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	init_data(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FDF");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &(data.bits_per_pixel), \
			&(data.size_line), &(data.endian));
	read_map(&data, av[1]);
	draw_img(&data, 0, 0);
	mlx_hook(data.win, 2, 0, key_press, &data);
	mlx_hook(data.win, 17, 0, red_button, 0);
	mlx_loop(data.mlx);
	exit (0);
}
