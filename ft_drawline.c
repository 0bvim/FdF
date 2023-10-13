/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 00:58:16 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/13 01:37:46 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_setup(t_point s, t_point e, t_point *delta, t_point *incr);

void	ft_draw_line(mlx_image_t *canvas, t_point s, t_point e)
{
	t_point	delta;
	t_point	incr
	t_point	cur
	int32_t	error;
}

static void	ft_setup(t_point s, t_point e, t_point *delta, t_point *incr)
{
	delta->x = ft_abs(s.x - e.x);
	delta->y = ft_abs(s.y - e.y);
	incr->x = ft_abs(e.x - s.x, 1, -1);
	incr->y = ft_abs(e.y - s.y, 1, -1);
}
