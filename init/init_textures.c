#include "../cub3d.h"

void    init_texture(t_cub3d *cube, t_text *txt,char *line)
{
    int i;
    int width;
    int height;
    
    i = 2;
    while (line[i] == ' ')
        i++;
    if (!(txt->img = mlx_xpm_file_to_image(cube->mlx.ptr, &line[i], &width, &height)))
    {
        ft_strdel_gnl(&line);
        ft_err(cube, "Wrong path for textures");
    }
    txt->img_addr = mlx_get_data_addr(txt->img, &(txt->bpp), &(txt->length), &(txt->endian));
    (cube->map.all_param)++;
    printf("nice");
    cube->text[3].img = mlx_xpm_file_to_image(cube->mlx.ptr, "./images/yellow_bricks.xpm", &width, &height);
    cube->text[3].img_addr = mlx_get_data_addr(cube->text[3].img, &(cube->text[3].bpp), &(cube->text[3].length), &(cube->text[3].endian));
}