#include "../cub3d.h"

void	pixel_put(t_cub3d *cube, int x, int y, int color)
{
	char	r;
	char	g;
	char	b;
	int		len;

	len = 4 * ((cube->map.widthscreen) * y + x); //axe x et y et vu que c'est un char la ligne deux commence a 680+680=1360 pui s + x pour etre sur ton axe x et 4 parce que 1 cqhqr c 4 bytes
	r = (int)((color & 16711680) >> 16);
	g = (int)((color & 65280) >> 8);
	b = (int)(color & 255);
	cube->mlx.img.addr[len] = b;
	cube->mlx.img.addr[len + 1] = g;
	cube->mlx.img.addr[len + 2] = r;
}