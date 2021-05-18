#include "../cub3d.h"

void    init_player_1(t_cub3d *cube)
{
    if (cube->var.dir == 'N' || cube->var.dir == 'S')
	{
		cube->var.dirX = 0;
		cube->var.planeY = 0;
	}
	else if (cube->var.dir == 'W' || cube->var.dir == 'E')
	{
		cube->var.dirY = 0;
		cube->var.planeX = 0;
	}
    init_player_2(cube);
}

void    init_player_2(t_cub3d *cube)
{
    if (cube->var.dir == 'N' || cube->var.dir == 'S')
	{
        if (cube->var.dir == 'N')
		{    
            cube->var.dirY = -1;
            cube->var.planeX = 0.66;
        }

        else
        {
            cube->var.dirY = 1;
            cube->var.planeX = -0.66;
        }
	}
	else if (cube->var.dir == 'W' || cube->var.dir == 'E')
	{
        if (cube->var.dir == 'W')
        {
            cube->var.dirX = -1;
            cube->var.planeY = -0.66; 
        }
        else
        {
            cube->var.dirX = 1;
            cube->var.planeY = 0.66; 
        }
	}
}

void    set_position(t_cub3d *cube, double posX, double posY)
{
    cube->var.posX = cube->var.posX + posX;
    cube->var.posY = cube->var.posY + posY;
}