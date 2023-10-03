#include "fdf.h"

#define ESC 65307

static void	ft_hook(void *param);
void	key_press(mlx_key_data_t key, void *param);
void	ft_line(mlx_image_t *image, mlx_t *param, uint32_t color);

int	main(void)
{
	uint32_t	color = 0xFF0000FF;
	// Open window maximized
	mlx_set_setting(MLX_MAXIMIZED, false);

	// Set responsive
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	// Create a new MLX windows
	mlx_t	*mlx = mlx_init(WIDTH, HEIGHT, "FckDerFkr", true);

	// Get the window image
	mlx_image_t	*image = mlx_new_image(mlx, WIDTH, HEIGHT);
	//mlx_texture_t	*bg = mlx_load_png("big.png");
	// Set the line color, commented here, using in function ft_line.
	//mlx_put_pixel (image, 10, 10, color);
	
	// Display the image
	//image = mlx_texture_to_image(mlx, bg);
	mlx_image_to_window(mlx, image, 400, 300);

	// Destroy the window and wait for a key press
	mlx_key_hook(mlx, key_press, mlx);

	// loop to print line in the window
	ft_line(image, mlx, color);	
	//mlx_loop_hook(mlx, ft_hook, image);
	mlx_loop(mlx);
	//mlx_terminate(mlx);
}

//static void	ft_hook(void *param) // finish this function

void	key_press(mlx_key_data_t key, void *param)
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
};

void	ft_line(mlx_image_t *image, mlx_t *param, uint32_t color)
{
	t_xyz	start;
	t_xyz	end;

	start.x = 0;
	start.y = 0;
	start.z = 0;
	end.x = 150;
	end.y = 150;
	end.z = 0;
	
	uint32_t dx = end.x - start.x;
	uint32_t dy = end.y - start.y;

	while (dx)
		mlx_put_pixel(image, dx--, dy, color);
	while (dy)
		mlx_put_pixel(image, dx, dy--, color);

//	start.y = 0;
//	for( start.x = 0; start.x < 90; start.x++)
//	{
//		mlx_put_pixel(image, start.x, start.y, color);
//		start.y++;
//	}
//
//	start.y = 50;
//	for( start.x = 0; start.x < 50; start.x++)
//	{
//		mlx_put_pixel(image, start.x, start.y, color);
//	}
//
//	start.x = 0;
//	for( start.y = 0; start.y < 50; start.y++)
//	{
//		mlx_put_pixel(image, start.x, start.y, color);
//	}
//
//	start.x = 50;
//	for( start.y = 0; start.y < 50; start.y++)
//	{
//		mlx_put_pixel(image, start.x, start.y, color);
//	}
}
