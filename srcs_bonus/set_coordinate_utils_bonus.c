//
// Created by jiyun on 2022/10/03.
//
#include "fdf_bonus.h"

void rot_x(int *y, int *z, double x_angle)
{
	int	temp_y;

	temp_y = *y;
	*y = temp_y * cos(x_angle) + *z * sin(x_angle);
	*z = -temp_y * sin(x_angle) + *z * cos(x_angle);
}

void rot_y(int *x, int *z, double y_angle)
{
	int	temp_x;

	temp_x = *x;
	*x = temp_x * cos(y_angle) + *z * sin(y_angle);
	*z = -temp_x * sin(y_angle) + *z * cos(y_angle);
}

void rot_z(int *x, int *y, double z_angle)
{
	int	temp_x;

	temp_x = *x;
	*x = temp_x * cos(z_angle) + *y * sin(z_angle);
	*y = -temp_x * sin(z_angle) + *y * cos(z_angle);
}

void isometric(int *x, int *y, int z)
{
	int	temp_x;
	int	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = (temp_x - temp_y) * cos(ANGLE);
	*y = (temp_x + temp_y) * sin(ANGLE) - z;
}