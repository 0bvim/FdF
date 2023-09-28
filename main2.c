#include "fdf.h"

#define ESC 65307

static void	ft_hook(void *param);
void	closew(mlx_key_data_t key, void *param);
void	ft_line(mlx_image_t *image, mlx_t *param, uint32_t color);

int	main(void)
{
	uint32_t	color = 0x57328900;
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
	mlx_image_to_window(mlx, image, 0, 0);

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

void	ft_line(mlx_image_t *image, mlx_t *param, uint32_t color)
{
	for(int i = 0; i < 750; i++)
	{
		for(int j = 0; j < 550; j++)
			mlx_put_pixel(image, i, j, color++);
	}
}
