#include "../cub3d.h"

static void init_player_var2(t_cub3d *cube)
{
    cube->var.posZ = 0;
    cube->var.rowDistance = 0;
    cube->var.floorStepX = 0;
    cube->var.floorStepY = 0;
    cube->var.floorX = 0;
    cube->var.floorY = 0;
    cube->var.perpWallDist = 0;
    cube->var.rayDirX = 0;
    cube->var.rayDirY = 0;
    cube->var.movespeed = 0.25;
    cube->var.rotspeed = 0.05;
    cube->var.hit = 0;
    cube->var.cameraX = 0;
    cube->var.mapX = 0;
    cube->var.mapY = 0;
    cube->var.sideDistX = 0;
    cube->var.sideDistY = 0;
    cube->var.deltaDistX = 0;
    cube->var.deltaDistY = 0;
    cube->var.stepX = 0;
    cube->var.stepY = 0;
    cube->var.drawstart = 0;
    cube->var.drawend = 0;
}

void    init_player_var(t_cub3d *cube)
{
    cube->var.posX = 0.5;
    cube->var.posY = 0.5;
    cube->var.dirX = 0;
    cube->var.dirY = 0;
    cube->var.dir = '0';
    cube->var.planeX = 0;
    cube->var.planeY = 0;
    cube->var.key_forward = 0;
    cube->var.key_left = 0;
    cube->var.key_backward = 0;
    cube->var.key_right = 0;
    cube->var.key_rot_right = 0;
    cube->var.key_rot_left = 0;
    cube->var.side = 0;
    cube->var.lineheight = 0;
    cube->var.text_num = 0;
    cube->var.rayDirX0 = 0;
    cube->var.rayDirY0 = 0;
    cube->var.rayDirX1 = 0;
    cube->var.rayDirY1 = 0;
    cube->var.p = 0;
    init_player_var2(cube);
}

void    init_color_f_and_c(t_color *color)
{
    color->r = 0;
    color->g = 0;
    color->b = 0;
    color->color = 0;
}

void    init_map_and_img_var(t_cub3d *cube)
{
    cube->map.all_param = 0;
    cube->map.map_start = 0;
    cube->map.map_end = 0;
    cube->map.nb_line = 0;
    cube->map.longueur_max_ligne = 0;
    cube->map.map_tmp = NULL;
    cube->map.the_map = NULL;
    cube->map.widthscreen = 0;
    cube->map.heightscreen = 0;
    init_color_f_and_c(&cube->map.color_ceiling);
    init_color_f_and_c(&cube->map.color_floor);
    cube->mlx.img.image = NULL; 
    cube->mlx.img.ptr = NULL;
    cube->mlx.img.addr = NULL;
    cube->mlx.img.bpp = 0;
    cube->mlx.img.line_length = 0;
    cube->mlx.img.endian = 0;
	cube->mlx.img.width = 0;
  	cube->mlx.img.height = 0;
    cube->mlx.ptr = NULL;
    cube->mlx.win = NULL;
}

void    init_all_var(t_cub3d *cube)
{
    init_player_var(cube);
    init_map_and_img_var(cube);
    init_var_texture(cube);
}