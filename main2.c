#include "fdf.h"

#define ESC 65307

static void	ft_hook(void *param);
void	closew(mlx_key_data_t key, void *param);

int	main(void)
{
	// Open window maximized
	mlx_set_setting(MLX_MAXIMIZED, false);

	// Set responsive
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	// Create a new MLX windows
	mlx_t	*mlx = mlx_init(800, 600, "FckDerFkr", true);

	// Get the window image
	mlx_image_t	*image = mlx_new_image(mlx, WIDTH, HEIGHT);
	
	// Set the line color
	mlx_put_pixel (image, 10, 10, 0xFF0000FF);
	
	// Display the image
	mlx_image_to_window(mlx, image, 250, 250);

	// Wait for a key press
	mlx_key_hook(mlx, closew, mlx);

	//mlx_loop_hook(mlx, ft_hook, mlx);
	// Destroy the window
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

//static void	ft_hook(void *param)
//{
//	mlx_t	*mlx = param;
//
//	if (mlx_is_key_down(mlx, MLX_KEY_SPACE))
//		mlx_close_window(mlx);
//}

void	closew(mlx_key_data_t key, void *param)
{
	mlx_t	*mlx = param;

	if (key.key == MLX_KEY_ESCAPE)
		mlx_terminate(mlx);
}
