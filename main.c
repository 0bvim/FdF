/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 06:17:26 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/12 08:44:02 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	printf("\n H: %d\n W: %d\n X: %d\n Y: %d\n", data.map_height, data.map_width, data.coords->height, data.coords->color);
	// TODO: get colors while parse map
	mlx = mlx_init(WIDTH, HEIGHT, "Efi the Efi", true);

}
