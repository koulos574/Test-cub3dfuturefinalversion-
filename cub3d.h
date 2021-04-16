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

#define WIDTH 1200
#define HEIGHT 800
#define mapWidth 24
#define mapHeight 24
#define texWidth 64
#define texHeight 64

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

typedef struct  s_map_info {
  int           widthscreen;
  int           heightscreen;
  t_color       color_floor;
  t_color       color_ceiling;
  int           all_param;
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
}               t_mlx_img;


typedef struct	s_mlx {
	void 		*ptr;
	void		*win;
	t_mlx_img		img;
}				        t_mlx;

typedef struct s_var {

    double  posX;
    double  posY;
    double  dirX;
    double  dirY;
    double  planeX;
    double  planeY;
    double  perpWallDist;
    double rayDirX;
    double rayDirY;
    int     key_forward;
    int     key_left;
    int     key_backward;
    int     key_right;
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
    //double movespeed;
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
}               t_text;

typedef struct s_sprite 
{
  double x;
  double y;
  int texture;
}               t_sprite;  

/*
** NO --> 0, WE --> 1, SO --> 2, EA --> 3, Sprite --> 4
*/

typedef struct 	s_cub3d {
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
void  free_all_and_exit(t_cub3d *cube);

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
void init_window(t_cub3d *cube);



#endif