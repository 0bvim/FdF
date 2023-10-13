/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 00:49:43 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/13 00:52:35 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
