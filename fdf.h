/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 03:38:26 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/12 07:44:34 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define WIDTH 1900
# define HEIGHT 1080
# define ROT_SP 0.05
# define MOVE_SP 5
# define ZOOM_SP 1
# define HEIGHT_SP 1

/* Types */
/**
 * @param x The x point
 * @param y The y point
 * @param raw The colors RGB
 */
typedef struct s_IVec2
{
	struct
	{
		int32_t	x;
		int32_t	y;
	};
	int32_t	raw[2];
}	t_IVec2;

typedef t_IVec2	t_point;

/**
 * @param x_rot The X rotation.
 * @param y_rot The Y rotation.
 * @param z_rot The Z rotation.
 * @param pos2d The 2D camera position.
 * @param zoom The zoom amount.
 * @param height The height modification.
 */
typedef struct s_camera
{
	double	x_rot;
	double	y_rot;
	double	z_rot;
	t_IVec2	pos;
	int32_t	zoom;
	int32_t	height;
}	t_camera;

typedef struct s_coords
{
	int32_t	height;
	int32_t	color;
}	t_coords;

/**
 * Struct wrapping up our mlx instance and main drawing canvas.
 * @param instance The MLX instance.
 * @param canvas The main canvas buffer.
 * @param map_height The num of coordinates in the height.
 * @param map_width The num of coordinates in the width.
 */
typedef struct s_fdf
{
	mlx_t		*mlx;
	t_camera	camera;
	mlx_image_t	*canvas;
	int32_t		map_height;
	int32_t		map_width;
	t_coords	*coords;
}	t_fdf;

/*	Functions */

void		ft_move(t_fdf *data);
void		ft_height(t_fdf *data);
void		ft_rotate(t_fdf *data);
void		ft_zoom(t_fdf *data);
t_IVec2		ft_point(int32_t x, int32_t y);
void		ft_draw_line(mlx_image_t *canvas, t_point s, t_point e);

/**
 * Project a vector3 to the screen with respects to the camera states.
 * That is, it converts a 3D coordinate to 2D Screen space.
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @param z The z coordinate.
 * @param camera The camera.
 */
t_IVec2		ft_project(int32_t x, int32_t y, int32_t z, t_camera *camera);

/**
 * Draws the canvas to the screen
 * @param data The FDF instance.
 */
void		ft_draw(t_fdf *data);

/**
 * Parses the given map into a 1d coordinate array.
 * Also populates the data ptr with important info (map, width, height, ...)
 * @param data The fdf data ptr.
 * @param map_path The file path to the map to open.
 * @return A 1d coordinate array.
 */
t_coords	*ft_parse_map(t_fdf *data, char *map_path);

/**
 * Assertion method, if called will quit/exit the program.
 *
 * @param s The error message.
 */
void		ft_error(char *s);
#endif
