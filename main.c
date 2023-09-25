/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 03:37:50 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/25 05:54:29 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

# define WIDTH 800
# define HEIGHT 600

/* exit the program as failure.*/
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit (EXIT_FAILURE);
}

/* print the window width and height. */
static void	ft_hook(void *param)
{
	const mlx_t	*mlx = param;
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(void)
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx_t	*mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!mlx)
		ft_error();
	mlx_image_t	*img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	for(int i = 0; i < 99; i++)
	{
		for(int j = 0; j < 99; j++)
			mlx_put_pixel(img, i, j, 0xFF0000FF);
	}
	
	//mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

