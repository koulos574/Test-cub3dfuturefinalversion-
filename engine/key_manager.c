#include "../cub3d.h"

int   key_release(int key, t_cub3d *cube)
{
  if (key == 53)
  {
    free_all_and_exit(cube);
    return (0);
  }
  if (key == 13)
    cube->var.key_forward = 0;
  if (key == 14)
    cube->var.key_rot_right = 0;
  if (key == 1)
    cube->var.key_backward = 0;
  if (key == 12)
    cube->var.key_rot_left = 0;
    if (key == 123)
    cube->var.key_left = 0;
  if (key == 124)
    cube->var.key_right = 0;
  return (0);
  
}

int   key_press(int key, t_cub3d *cube)
{
  if (key == 13)
    cube->var.key_forward = 1;
  if (key == 14)
    cube->var.key_rot_right = 1;
  if (key == 1)
    cube->var.key_backward = 1;
  if (key == 12)
    cube->var.key_rot_left = 1;
  if (key == 123)
    cube->var.key_left = 1;
  if (key == 124)
    cube->var.key_right = 1;
  return (0);
}