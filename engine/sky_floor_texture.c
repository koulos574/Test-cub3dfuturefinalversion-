#include "../cub3d.h"

void	put_wall_texture(t_cub3d *cube, int column, int y, int end)
{
	int		len;
	int		y_text;
	double	x_text;
	int		img_size;

	img_size = 200;
	if (cube->var.side == 0)
		x_text = cube->var.posY + cube->var.perpWallDist * cube->var.rayDirY;
	else
		x_text = cube->var.posX + cube->var.perpWallDist * cube->var.rayDirX;
	x_text = x_text * (double)(img_size);
	if (cube->var.side == 0 && cube->var.dirX > 0)
		x_text = fabs(img_size - x_text - 1);
	if (cube->var.side == 1 && cube->var.dirY < 0)
		x_text = fabs(img_size - x_text - 1);
	while (y < end)
	{
		len = 4 * ((cube->map.widthscreen) * y + column);
		y_text = abs((((y * 256 - cube->map.heightscreen * 128 + cube->var.lineheight * 128) * img_size) / cube->var.lineheight) / 256); // 128 et 256 to avoid float
        ft_memcpy(&cube->mlx.img.addr[len], &cube->text[cube->var.text_num].img_addr[y_text % img_size * cube->text[cube->var.text_num].length + 
        (int)x_text % img_size * (cube->text[cube->var.text_num].bpp / 8)], sizeof(int));
        y++;
	}
}

void    sky(t_cub3d *cube, int column, int y)
{
    int i;

    i = 0;
    while (i < y)
    {
        pixel_put(cube, column, i, 0x00FFFF);
        i++;
    }
}

void    my_floor(t_cub3d *cube, int column, int y)
{
    int i;

    i = y;
    while (i < cube->map.heightscreen)
    {
        pixel_put(cube, column, i, 0x919191);
        i++;
    }
}

void    drawy(int column, int y, int end, t_cub3d *cube)
{
    sky(cube, column, y);
    my_floor(cube, column, end);
    put_wall_texture(cube, column, y, end);
}