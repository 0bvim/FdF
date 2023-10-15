/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 00:49:43 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/14 20:36:50 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int32_t	ft_get(int32_t x, int32_t y, t_fdf *data)
{
	return (data->coords[y * data->map_width + x].height);
}

static void	ft_drawlines(int32_t x, int32_t y, t_fdf *data)
{
	if (x != data->map_width - 1)
		ft_draw_line(data->canvas, ft_project(x, y, ft_get(x, y, data), &data \
		->camera), ft_project(x + 1, y, ft_get(x + 1, y, data), &data->camera));
	if (y != data->map_height - 1)
		ft_draw_line(data->canvas, ft_project(x, y, ft_get(x, y, data), &data \
		->camera), ft_project(x, y + 1, ft_get(x, y + 1, data), &data->camera));
}

void	ft_draw(t_fdf *data)
{
	int32_t	x;
	int32_t	y;

	x = 0;
	y = 0;
	ft_bzero(data->canvas->pixels, WIDTH * HEIGHT * sizeof(int32_t));
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			ft_drawlines(x, y, data);
			x++;
		}
		y++;
	}
}
