#include "../cub3d.h"

static void     move_forward_and_backward(t_cub3d *cube)
{
    if (cube->var.key_backward == 1)
    {
      if(cube->map.the_map[(int)(cube->var.posX - cube->var.dirX * cube->var.movespeed)][(int)(cube->var.posY)] == 0) 
        cube->var.posX -= cube->var.dirX * cube->var.movespeed;
      if(cube->map.the_map[(int)(cube->var.posX)][(int)(cube->var.posY - cube->var.dirY * cube->var.movespeed)] == 0) 
        cube->var.posY -= cube->var.dirY * cube->var.movespeed;
    }
    if (cube->var.key_forward == 1)
      {
        if(cube->map.the_map[(int)(cube->var.posX + cube->var.dirX * cube->var.movespeed)][(int)cube->var.posY] == 0) 
          cube->var.posX += cube->var.dirX * cube->var.movespeed;
        if(cube->map.the_map[(int)cube->var.posX][(int)(cube->var.posY + cube->var.dirY * cube->var.movespeed)] == 0) 
          cube->var.posY += cube->var.dirY * cube->var.movespeed;
      }
}

static void     move_left_and_right(t_cub3d *cube)
{
    if (cube->var.key_left == 1)
    {
      if (cube->map.the_map[(int)(cube->var.posX)][(int)(cube->var.posY + cube->var.dirX * cube->var.movespeed)] == 0)
        cube->var.posY += cube->var.dirX * cube->var.movespeed * 0.5;
      if (cube->map.the_map[(int)(cube->var.posX - cube->var.dirY * cube->var.movespeed)][(int)(cube->var.posY)] == 0)
        cube->var.posX -= cube->var.dirY * cube->var.movespeed * 0.5;
    }
    if (cube->var.key_right == 1)
    {
      if (cube->map.the_map[(int)(cube->var.posX)][(int)(cube->var.posY - cube->var.dirX * cube->var.movespeed)] == 0)
        cube->var.posY -= cube->var.dirX * cube->var.movespeed;
      if (cube->map.the_map[(int)(cube->var.posX + cube->var.dirY * cube->var.movespeed)][(int)(cube->var.posY)] == 0)
        cube->var.posX += cube->var.dirY * cube->var.movespeed;
    }
}

static void     rotate_left_right(t_cub3d *cube)
{
    double oldDirX;
    double oldPlaneX;

    if (cube->var.key_rot_left == 1) //rotation gauche a
      {
        oldDirX = cube->var.dirX;
        cube->var.dirX = cube->var.dirX * cos(cube->var.rotspeed) - cube->var.dirY * sin(cube->var.rotspeed);
        cube->var.dirY = oldDirX * sin(cube->var.rotspeed) + cube->var.dirY * cos(cube->var.rotspeed);
        oldPlaneX = cube->var.planeX;
        cube->var.planeX = cube->var.planeX * cos(cube->var.rotspeed) - cube->var.planeY * sin(cube->var.rotspeed);
        cube->var.planeY = oldPlaneX * sin(cube->var.rotspeed) + cube->var.planeY * cos(cube->var.rotspeed);
      }
    
    if (cube->var.key_rot_right == 1) // rotation droite e
    {
      oldDirX = cube->var.dirX;
      cube->var.dirX = cube->var.dirX * cos(-cube->var.rotspeed) - cube->var.dirY * sin(-cube->var.rotspeed);
      cube->var.dirY = oldDirX * sin(-cube->var.rotspeed) + cube->var.dirY * cos(-cube->var.rotspeed);
      oldPlaneX = cube->var.planeX;
      cube->var.planeX = cube->var.planeX * cos(-cube->var.rotspeed) - cube->var.planeY * sin(-cube->var.rotspeed);
      cube->var.planeY = oldPlaneX * sin(-cube->var.rotspeed) + cube->var.planeY * cos(-cube->var.rotspeed);
    }
}

void    move_player(t_cub3d *cube)
{
    move_forward_and_backward(cube);
    move_left_and_right(cube);
    rotate_left_right(cube);
}