#include "fdf.h"

#define ESC 65307

static void	ft_hook(void *param);
void	closew(mlx_key_data_t key, void *param);
void	ft_line(mlx_image_t *image, mlx_t *param, uint32_t color);

int	main(void)
{
	uint32_t	color = 0xFF0000FF;
	// Open window maximized
	mlx_set_setting(MLX_MAXIMIZED, false);

	// Set responsive
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	// Create a new MLX windows
	mlx_t	*mlx = mlx_init(800, 600, "FckDerFkr", true);

	// Get the window image
	mlx_image_t	*image = mlx_new_image(mlx, WIDTH, HEIGHT);
	
	// Set the line color, commented here, using in function ft_line.
	//mlx_put_pixel (image, 10, 10, color);
	
	// Display the image
	mlx_image_to_window(mlx, image, 10, 10);

	// Destroy the window and wait for a key press
	mlx_key_hook(mlx, closew, mlx);

	// loop to print line in the window
	ft_line(image, mlx, color);	
	//mlx_loop_hook(mlx, ft_hook, image);
	mlx_loop(mlx);
	//mlx_terminate(mlx);
}

//static void	ft_hook(void *param) // finish this function

void	closew(mlx_key_data_t key, void *param)
{
	mlx_t	*mlx = param;

	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(mlx);
	}
}

typedef struct s_xyz t_xyz;
struct s_xyz
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	z;
	t_xyz		*next;
};

void	ft_line(mlx_image_t *image, mlx_t *param, uint32_t color)
{
	t_xyz	map;

	map.x = 0;
	map.y = 0;
	map.z = 0;
	map.next = NULL;
	for(map.x = 0; map.x < 50; map.x++)
	{
		mlx_put_pixel(image, map.x, map.y, color);
	}

	map.y = 50;
	for( map.x = 0; map.x < 50; map.x++)
	{
		mlx_put_pixel(image, map.x, map.y, color);
	}

	map.x = 0;
	for( map.y = 0; map.y < 50; map.y++)
	{
		mlx_put_pixel(image, map.x, map.y, color);
	}

	map.x = 50;
	for( map.y = 0; map.y < 50; map.y++)
	{
		mlx_put_pixel(image, map.x, map.y, color);
	}
}
