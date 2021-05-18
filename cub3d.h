/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai <vifontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:28:34 by vifontai          #+#    #+#             */
/*   Updated: 2021/04/16 18:06:57 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "gnl/get_next_line.h"
#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00



typedef struct  s_color {
  int           r;
  int           g;
  int           b;
  int           color;
}               t_color;
//al_var_init

typedef struct  s_map_info {
  int           widthscreen;
  int           heightscreen;
  t_color       color_floor;
  t_color       color_ceiling;
  int           all_param;
  int           map_start;
  int           map_end;
  char          *map_tmp;
  int           nb_line;
  int           longueur_max_ligne;
  int           **the_map;
  //var above init
}               t_map_info;


typedef struct  s_mlx_img {
   void         *image;
	 void	  	    *ptr;
   char         *addr;
   int          bpp;
   int          line_length;
   int          endian;
	 int    	 	  width;
   int     	    height;
   //var above init
}               t_mlx_img;


typedef struct	s_mlx {
	void 		*ptr;
	void		*win;
	t_mlx_img		img;
  //var above init
}				        t_mlx;

typedef struct s_var {

    double  posX;
    double  posY;
    double  dirX;
    double  dirY;
    char    dir;
    double  planeX;
    double  planeY;
    int     key_forward;
    int     key_left;
    int     key_backward;
    int     key_right;
    int     key_rot_right;
    int     key_rot_left;
    int     color;
    int     side;
    int     lineheight;
    int     text_num;
    float   rayDirX0;
    float   rayDirY0;
    float   rayDirX1;
    float   rayDirY1;
    int     p;
    float   posZ;
    float   rowDistance;
    float floorStepX;
    float floorStepY;
    float floorX;
    float floorY;
    double  perpWallDist;
    double rayDirX;
    double rayDirY;
    double movespeed;
    double  rotspeed;
    // var above init
    double cameraX;
    int     mapX;
    int     mapY;
    double sideDistX;
    double sideDistY;
    double deltaDistX;
    double deltaDistY;
    int stepX;
    int stepY;
    int hit;
    int drawstart;
    int drawend;
}               t_var;

typedef struct s_text {
  char *relative_path;
  void  *img;
  int   img_width;
  int   img_height;
  char *img_addr;
  int   bpp;
  int   length;
  int   endian;
  // var above init
}               t_text;

typedef struct s_sprite 
{
  //var above init
  double x;
  double y;
  int texture;
}               t_sprite;  

/*
** NO --> 0, WE --> 1, SO --> 2, EA --> 3, Sprite --> 4
*/

typedef struct 	s_cub3d {
  //struct above init
	t_mlx		    mlx;
  t_map_info  map;	
  t_var       var;	
  t_sprite    spr;
  t_text      text[5]; //nombre de texture que tu as 
}				        t_cub3d;

/*
** ft_error
*/
int   ft_err(t_cub3d *cub, char *error);
int   free_all_and_exit(t_cub3d *cube);

/*
** init_resolution
*/
void  init_resolution(t_cub3d *cube, char *str);

/*
** init_textures
*/
void  init_texture(t_cub3d *cube, t_text *txt, char * str);

/*
** init_color
*/
void  init_color(t_cub3d *cube, char *line, t_color *color);

/*
** main
*/

/*
** init_window
*/
void init_window(t_cub3d *cube);

/*
** init_map
*/
void    read_map(t_cub3d *cube, char *file);
void    check_info(t_cub3d *cube, char *str);
void    get_cub_info(t_cub3d *cube, char *line);
void    get_map(t_cub3d *cube, char *line);
int     *make_row_int(char *str, t_cub3d *cube, int current_row);

/*
** create_map
*/
void    create_map(t_cub3d *cube);
void    check_map(t_cub3d *cube);
void    flood_fill(t_cub3d *cube, int x, int y);
void    reset_map(t_cub3d *cube);
void    has_map_started(t_cub3d *cube, char *line);

/*
** utils
*/
int     ft_is_in_map(char *line);
int     ft_dir(char z);
int     ft_endmap(char *line);
char	  *ft_strjoin_and_free(char *s1, char *s2);
void    free_split(char **str);

/*
** init_player_and_var
*/
void    init_player_1(t_cub3d *cube);
void    init_player_2(t_cub3d *cube);
void    set_position(t_cub3d *cube, double posX, double posY);

/*
** utils2
*/
void	pixel_put(t_cub3d *cube, int x, int y, int color);

/*
** is_map_valid
*/
void    is_map_valid(t_cub3d *cube);

/*
** init_var
*/
void    init_player_var(t_cub3d *cube);
void    init_all_var(t_cub3d *cube);
void    init_map_and_img_var(t_cub3d *cube);
void    init_color_f_and_c(t_color *color);

/*
** init_var2
*/
void            init_var_texture(t_cub3d *cube);

/*
** sky_floor_texture
*/
void    drawy(int column, int y, int end, t_cub3d *cube);
void	put_wall_texture(t_cub3d *cube, int column, int y, int end);
void    my_floor(t_cub3d *cube, int column, int y);
void    sky(t_cub3d *cube, int column, int y);

/*
** key_manager
*/
int   key_release(int key, t_cub3d *cube);
int   key_press(int key, t_cub3d *cube);
void  key_manager(t_cub3d *cube);

/*
** raycasting
*/
int            raycasting(t_cub3d *cube);

#endif