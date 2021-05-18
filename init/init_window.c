#include "../cub3d.h"

void		init_window(t_cub3d *cube)
{
  	cube->mlx.ptr = mlx_init();
	cube->mlx.win = mlx_new_window(cube->mlx.ptr, cube->map.widthscreen, cube->map.heightscreen, "CUB3D");
	cube->mlx.img.image = mlx_new_image(cube->mlx.ptr, cube->map.widthscreen, cube->map.heightscreen);
	cube->mlx.img.addr = mlx_get_data_addr(cube->mlx.img.image, &(cube->mlx.img.bpp), &(cube->mlx.img.line_length), &(cube->mlx.img.endian));
}