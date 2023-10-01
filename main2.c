#include "fdf.h"


static void	ft_hook(void *param);
void	keys(mlx_key_data_t key, void *param);
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
	mlx_key_hook(mlx, keys, mlx);

	// loop to print line in the window
	ft_line(image, mlx, color);
	//mlx_loop_hook(mlx, ft_hook, image);
	mlx_loop(mlx);
	//mlx_terminate(mlx);
}

//static void	ft_hook(void *param) // finish this function

void	keys(mlx_key_data_t key, void *param)
{
	mlx_t	*mlx = param;

	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(mlx);
	else if (key.key == MLX_KEY_END)
		mlx_close_window(mlx);
}

void	ft_line(mlx_image_t *image, mlx_t *param, uint32_t color)
{
	uint32_t	dx;
	uint32_t	dy;
	t_trid	p1;
	t_trid	p2;

	p1.x = 80;
	p1.y = 0;
	p1.z = 0;
	p2.x = 100;
	p2.y = 0;
	p2.z = 0;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	
	while (dx)
		mlx_put_pixel(image, dx, dy, color);

	dy = 50;
	for(dx = 0; dx < 50; dx++)
		mlx_put_pixel(image, dx, dy, color);

	dx = 0;
	for(dy = 0; dy < 50; dy++)
		mlx_put_pixel(image, dx, dy, color);

	dx = 50;
	for(dy = 0; dy < 50; dy++)
		mlx_put_pixel(image, dx, dy, color);
}
