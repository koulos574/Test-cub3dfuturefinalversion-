#include "../cub3d.h"

static  void    first_step_ray_y(t_cub3d *cube)
{
    int j;

    j = 0;
    while (j < cube->map.heightscreen)
    {
      cube->var.rayDirX0 = cube->var.dirX - cube->var.planeX;
      cube->var.rayDirY0 = cube->var.dirY - cube->var.planeY;
      cube->var.rayDirX1 = cube->var.dirX + cube->var.planeX;
      cube->var.rayDirY1 = cube->var.dirY + cube->var.planeY;

      cube->var.p = j - cube->map.heightscreen / 2;
      
      cube->var.posZ = 0.5 * cube->map.heightscreen;

      cube->var.rowDistance = cube->var.posZ/cube->var.p;

      cube->var.floorStepX = cube->var.rowDistance * (cube->var.rayDirX1 - cube->var.rayDirX0)/cube->map.widthscreen;
      cube->var.floorStepY = cube->var.rowDistance * (cube->var.rayDirY1 - cube->var.rayDirY0)/cube->map.widthscreen;
      
      cube->var.floorX = cube->var.posX + cube->var.rowDistance * cube->var.rayDirX0;
      cube->var.floorY = cube->var.posY + cube->var.rowDistance * cube->var.rayDirY0;
      j++;
    }
}

static void     first_step_ray_x(t_cub3d *cube, int i)
{
    cube->var.cameraX = 2 * i / (double)cube->map.widthscreen - 1; //x-coordinate in camera space
    cube->var.rayDirX = cube->var.dirX + cube->var.planeX * cube->var.cameraX;
    cube->var.rayDirY = cube->var.dirY + cube->var.planeY * cube->var.cameraX;
    cube->var.mapX = (int)cube->var.posX;
    cube->var.mapY = (int)cube->var.posY; 
    cube->var.deltaDistX = fabs(1 / cube->var.rayDirX);
    cube->var.deltaDistY = fabs(1 / cube->var.rayDirY);
    if(cube->var.rayDirX < 0)
    {
        cube->var.stepX = -1;
        cube->var.sideDistX = (cube->var.posX - cube->var.mapX) * cube->var.deltaDistX;
    }
    else
    {
        cube->var.stepX = 1;
        cube->var.sideDistX = (cube->var.mapX + 1.0 - cube->var.posX) * cube->var.deltaDistX;
    }
    if(cube->var.rayDirY < 0)
    {
        cube->var.stepY = -1;
        cube->var.sideDistY = (cube->var.posY - cube->var.mapY) * cube->var.deltaDistY;
    }
    else
    {
        cube->var.stepY = 1;
        cube->var.sideDistY = (cube->var.mapY + 1.0 - cube->var.posY) * cube->var.deltaDistY;
    }
}

static void     second_step_ray_x(t_cub3d *cube, int i)
{
    while (cube->var.hit == 0)
      {
        if(cube->var.sideDistX < cube->var.sideDistY)
        {
          cube->var.sideDistX += cube->var.deltaDistX;
          cube->var.mapX += cube->var.stepX;
          cube->var.side = 0;
        }
        else
        {
          cube->var.sideDistY += cube->var.deltaDistY;
          cube->var.mapY += cube->var.stepY;
          cube->var.side = 1;
        }
        if(cube->map.the_map[cube->var.mapX][cube->var.mapY] > 0)
            cube->var.hit = 1;
      }
    if(cube->var.side == 0) 
        cube->var.perpWallDist = (cube->var.mapX - cube->var.posX + (1 - cube->var.stepX) / 2) / cube->var.rayDirX;
    else          
        cube->var.perpWallDist = (cube->var.mapY - cube->var.posY + (1 - cube->var.stepY) / 2) / cube->var.rayDirY;
    cube->var.lineheight = (int)(cube->map.heightscreen / cube->var.perpWallDist);
}

static void     set_textures(t_cub3d *cube, int i)
{
    cube->var.drawstart = -(cube->var.lineheight) / 2 + cube->map.heightscreen / 2;
    if(cube->var.drawstart < 0)
      cube->var.drawstart = 0;
    cube->var.drawend = cube->var.lineheight / 2 + cube->map.heightscreen / 2;
    if(cube->var.drawend >= cube->map.heightscreen)
      cube->var.drawend = cube->map.heightscreen - 1;
    cube->var.text_num = 0;
    if ((cube->var.stepX == 1) && ((cube->var.stepY == -1) || cube->var.stepY == 1))
      cube->var.text_num = 1;
    if (cube->var.side == 1)
	{
        cube->var.text_num = 2;
        if ((cube->var.stepY == 1) && ((cube->var.stepX == -1) || cube->var.stepX == 1))
            cube->var.text_num = 3;
    }
    printf("%d", cube->var.text_num);
    drawy(i, cube->var.drawstart, cube->var.drawend, cube); 
}

int            raycasting(t_cub3d *cube)
{
    int i;

    i = 0;
    first_step_ray_y(cube);
    while (i < cube->map.widthscreen)
    {
        first_step_ray_x(cube, i);
        second_step_ray_x(cube, i);
        set_textures(cube, i);
        //sprite
        i++;
    }
    mlx_put_image_to_window(cube->mlx.ptr, cube->mlx.win, cube->mlx.img.image, 0, 0);
    return (0);
}