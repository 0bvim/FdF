#include "fdf.h"

//static void	ft_hook(void *param);
void	key_press(mlx_key_data_t key, void *param);
void	ft_line(t_fdf fdf, t_drawu *pixel, t_point start, t_point end);

int	main(void)
{
	t_drawu	*pixel;
	t_fdf	fdf;
	t_point	one;
	t_point	two;
	
	one.x = 100;
	one.y =	100;
	two.x = 300;
	two.y = 300;
	one.z = 0;
	two.z = 10;
	pixel = malloc(sizeof(t_drawu));
	pixel->color = 0x0F44F5FF;
	pixel->wid = 500;
	pixel->height = 400;

	// Open window maximized
	mlx_set_setting(MLX_MAXIMIZED, false);
	// Set responsive
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	// Create a new MLX windows
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "FckDerFkr", true);
	// Get the window image
	fdf.image = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);

	mlx_image_to_window(fdf.mlx, fdf.image, pixel->wid, pixel->height);

	// Destroy the window and wait for a key press
	mlx_key_hook(fdf.mlx, key_press, fdf.mlx);

	// loop to print line in the window
	ft_line(fdf, pixel, one, two);
	//mlx_loop_hook(mlx, ft_hook, image);
	mlx_loop(fdf.mlx);
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

void	ft_line(t_fdf fdf, t_drawu *pixel, t_point start, t_point end)
{
	float	slopeX;
	float	slopeY;
	float	distance;
	float	intensity;
	int	x;
	int	y;
	int	z;
	t_point	*temp;
	temp = &start;
	
	z = start.z;
	while (temp->x != end.x || temp->y != end.y)
	{
		mlx_put_pixel(fdf.image, x, y, pixel->color);
		if (!end.z)
			slopeX = (end.x - start.x);
		else
			slopeX = (end.x - start.x) / (end.z - start.z);
		if (!end.z)
			slopeY = (end.y - start.y);
		else
		slopeY = (end.y - start.y) / (end.z - start.z);
		x = (int)(start.x + slopeX * (z - start.z));
		y = (int)(start.y + slopeY * (z - start.z));
		distance = fabs(y - (start.y + slopeY * (z - start.z)));
		intensity = 0.5 - fabs(distance);
		start.x++;
		mlx_put_pixel(fdf.image, x, y, pixel->color);
		start.y++;

	}
}
