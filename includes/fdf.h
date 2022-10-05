/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:01:26 by jiyun             #+#    #+#             */
/*   Updated: 2022/10/05 12:35:34 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define TRUE 1
# define FALSE 0
# define WIDTH 1600
# define HEIGHT 900
# define BACKGROUND 0x222222
# define ANGLE 0.52
# define ZOOM 10
# define PARALLEL 0
# define ISOMETRIC 1

# include "mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		**map;
	int		height;
	int		width;
	int		color;
	double	zoom;
	int		zoom_is_double;
	int		start_x;
	int		start_y;
	int		start_z;
	int		end_x;
	int		end_y;
	int		end_z;
	int		cur_x;
	int		cur_y;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	int		x_shift;
	int		y_shift;
	int		projection;
}	t_data;

/* read_map.c */
void	read_map(t_data *data, char *file);

/* read_map_utils.c */
int		ft_atoi(const char *str);

/* draw_img.c */
void	draw_img(t_data *data, int x, int y);

/* draw_img_utils.c */
int		ft_abs(int a);
int		ft_compare(int a, int b);
void	*ft_memset(void *b, int c, size_t len);
void	my_mlx_pixel_put(t_data *data, int x, int y);

/* set_coordinate.c */
void	set_start(t_data *data, int x, int y);
void	set_end(t_data *data, int x, int y);

/* set_coordinate_utils.c */
void	rot_x(int *y, int *z, double x_angle);
void	rot_y(int *x, int *z, double y_angle);
void	rot_z(int *x, int *y, double z_angle);
void	isometric(int *x, int *y, int z);

/* input_handler.c */
int		key_press(int keycode, t_data *data);

/* get_next_line.c */
char	*get_next_line(int fd);

/* split.c */
size_t	cnt_strs(char const *str, char c);
char	**ft_split(char const *s, char c);

#endif
