/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:57:54 by jiyun             #+#    #+#             */
/*   Updated: 2022/10/05 10:57:59 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	get_height_width(t_data *data, int fd)
{
	char	*line;
	int		width;

	line = get_next_line(fd);
	while (line)
	{
		line[ft_strlen(line) - 1] = '\0';
		width = cnt_strs(line, ' ');
		if (data->width == 0)
			data->width = width;
		if (data->width != 0 && width != data->width)
			exit(1);
		data->height++;
		if (line)
			free(line);
		line = get_next_line(fd);
	}
}

void	clear_all(char *line, char **strs, int i)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	while (strs && strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	if (strs)
	{
		free(strs);
		strs = NULL;
	}
}

void	fill_map(t_data *data, int **arr, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**splited_chars;

	i = 0;
	line = get_next_line(fd);
	while (line && i < data->height)
	{
		line[ft_strlen(line) - 1] = '\0';
		splited_chars = ft_split(line, ' ');
		arr[i] = malloc(sizeof(arr[i]) * (data->width));
		if (!arr[i])
			exit(1);
		j = 0;
		while (splited_chars[j])
		{
			arr[i][j] = ft_atoi(splited_chars[j]);
			j++;
		}
		clear_all(line, splited_chars, i);
		line = get_next_line(fd);
		i++;
	}
	data->map = arr;
}

void	read_map(t_data *data, char *file)
{
	int	fd;
	int	**map;
	int	i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(1);
	get_height_width(data, fd);
	close(fd);
	map = malloc(sizeof(map) * (data->height));
	if (!map)
		exit(1);
	i = 0;
	while (i < data->height)
	{
		map[i] = NULL;
		i++;
	}
	fd = open(file, O_RDONLY);
	fill_map(data, map, fd);
	close(fd);
}
