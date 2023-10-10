/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 03:38:26 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/10 09:25:09 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "MLX42/include/MLX42/MLX42.h"
#include "lib/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

# define WIDTH 1900
# define HEIGHT 1200


typedef struct s_point t_point;
struct s_point
{
	float	x;
	float	y;
	float	z;
};

#endif

typedef struct s_drawu t_drawu;
struct s_drawu
{
	float		x0;
	float		x1;
	float		y0;
	float		y1;
	float		wid;
	float		height;
	uint32_t	color;
	unsigned char	*buffer;
};

typedef struct s_fdf t_fdf;
struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*image;
};
