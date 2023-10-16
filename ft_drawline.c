/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 00:58:16 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/15 09:45:59 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_set_pixel(mlx_image_t *canvas, t_point point, int32_t color)
{
	uint32_t	x;
	uint32_t	y;

	x = (uint32_t)point.x;
	y = (uint32_t)point.y;
	if (canvas && point.x > 0 && point.y > 0)
	{
		if ((x < canvas->width) && (y > 0 && y < canvas->height))
			mlx_put_pixel(canvas, point.x, point.y, color);
	}
}

static int32_t	ft_select(bool Val, int32_t a, int32_t b)
{
	if (Val)
		return (a);
	return (b);
}

static	void	ft_setup(t_point s, t_point e, t_point *delta, t_point *incr)
{
	delta->x = ft_abs(s.x - e.x);
	delta->y = ft_abs(s.y - e.y);
	incr->x = ft_select(e.x < s.x, 1, -1);
	incr->y = ft_select(e.y < s.y, 1, -1);
}

void	ft_draw_line(mlx_image_t *canvas, t_point s, t_point e)
{
	t_point	delta;
	t_point	incr;
	t_point	cur;
	int32_t	error;

	ft_setup(s, e, &delta, &incr);
	error = 2 * (delta.y - delta.x);
	cur = e;
	while (true)
	{
		ft_set_pixel(canvas, cur, 0xFFFFFF77);
		if (cur.x == s.x && cur.y == s.y)
			break ;
		if (error >= 0)
		{
			cur.y += incr.y;
			error -= 2 * delta.x;
		}
		if (error < 0)
		{
			cur.x += incr.x;
			error += 2 * delta.y;
		}
	}
}
