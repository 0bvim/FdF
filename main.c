/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 06:17:26 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/12 11:08:47 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_new_camera(t_fdf *data);
void		ft_press(void *param);

int	main(int32_t argc, char **argv)
{
	mlx_t	*mlx;
	t_fdf	data;

	if (argc == 1 || argc > 2)
	{
		ft_putendl("USAGE: ./fdf <map_file>");
		exit(EXIT_SUCCESS);
	}
	data.coords = ft_parse_map(&data, argv[1]);
	// TODO: get colors while parse map
	mlx = mlx_init(WIDTH, HEIGHT, "Efi the Efi", true);
	if (mlx)
	{
		data.mlx = mlx;
		data.canvas = mlx_new_image(mlx, WIDTH, HEIGHT);
		mlx_image_to_window(mlx, data.canvas, 0, 0);
		ft_new_camera(&data);
		mlx_loop_hook(mlx, ft_press, &data);
		mlx_loop(mlx);
		mlx_terminate(mlx);
		exit(EXIT_SUCCESS);
	}
	ft_error("Error: Initialization failure!");
	return (EXIT_FAILURE);
}

static void	ft_new_camera(t_fdf *data)
{
	data->camera.pos.x = 0;
	data->camera.pos.y = -100;
	data->camera.x_rot = 0;
	data->camera.y_rot = 0;
	data->camera.z_rot = 0;
	data->camera.height = 50;
	data->camera.zoom = 20;
}

void	ft_press(void *param)
{
	t_fdf	*data;

	data = (t_fdf *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->mlx);
		return ;
	}
	ft_move(data);
	ft_rotate(data);
	ft_height(data);
	ft_zoom(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_0))
		ft_new_camera(data);
	ft_draw(data);
}
