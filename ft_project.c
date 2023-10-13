/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_project.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:54:36 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/13 03:15:14 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// TODO ft_isometric and rot_x, y and z
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
