/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_project.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:54:36 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/13 06:25:14 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_isometric(int32_t *x, int32_t *y, int32_t z);
static void	ft_rot_x(int *y, int *z, double x_rot);
static void	ft_rot_y(int *x, int *z, double y_rot);
static void	ft_rot_z(int *x, int *y, double z_rot);

t_IVec2	ft_project(int32_t x, int32_t y, int32_t z, t_camera *camera)
{
	x *= camera->zoom;
	y *= camera->zoom;
	z *= (camera->height * camera->zoom) / 100.0f;
	ft_rot_x(&y, &z, camera->x_rot);
	ft_rot_y(&x, &z, camera->y_rot);
	ft_rot_z(&x, &y, camera->z_rot);
	ft_isometric(&x, &y, z);
	x += (WIDTH / 2) + camera->pos.x;
	y += (HEIGHT / 2) + camera->pos.y;
	return (ft_point(x, y));
}

static void	ft_isometric(int32_t *x, int32_t *y, int32_t z)
{
	int32_t	prev_x;
	int32_t	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.5235988);
	*y = -z + (prev_x + prev_y) * sin(0.5235988);
}

static void	ft_rot_x(int *y, int *z, double x_rot)
{
	int	previous_y;
	int	prev_z;

	previous_y = *y;
	prev_z = *z;
	*y = previous_y * cos(x_rot) + prev_z * sin(x_rot);
	*z = -previous_y * sin(x_rot) + prev_z * cos(x_rot);
}

static void	ft_rot_y(int *x, int *z, double y_rot)
{
	int	prev_x;
	int	prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = prev_x * cos(y_rot) + prev_z * sin(y_rot);
	*z = -prev_x * sin(y_rot) + prev_z * cos(y_rot);
}

static void	ft_rot_z(int *x, int *y, double z_rot)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(z_rot) - prev_y * sin(z_rot);
	*y = prev_x * sin(z_rot) + prev_y * cos(z_rot);
}
