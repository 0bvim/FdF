/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 03:38:26 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/01 14:41:46 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "MLX42/include/MLX42/MLX42.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

# define WIDTH 800
# define HEIGHT 600

#define ESC 65307

typedef struct s_trid t_trid;
struct s_trid
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	z;
};

#endif
