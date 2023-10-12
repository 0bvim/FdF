/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:11:12 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/12 11:38:24 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move(t_fdf *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->camera.pos.y -= MOVE_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->camera.pos.y += MOVE_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->camera.pos.x -= MOVE_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->camera.pos.x += MOVE_SP;
}

void	ft_rotate(t_fdf *data)
{	
	if (mlx_is_key_down(data->mlx, MLX_KEY_Q))
		data->camera.z_rot += ROT_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_E))
		data->camera.z_rot -= ROT_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->camera.x_rot -= ROT_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->camera.x_rot += ROT_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->camera.y_rot -= ROT_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->camera.y_rot += ROT_SP;
}

void	ft_zoom(t_fdf *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_J))
		data->camera.zoom += ZOOM_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_K))
		data->camera.zoom -= ZOOM_SP;
	data->camera.zoom = ft_max(data->camera.zoom, 0);
	data->camera.zoom = ft_min(data->camera.zoom, I32_MAX);
}

void	ft_height(t_fdf *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_Y))
		data->camera.height -= HEIGHT_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_U))
		data->camera.height += HEIGHT_SP;
}
