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
        ft_err(cube, "textures could not load 1\n");
    }
    if (!(txt->img_addr = mlx_get_data_addr(txt->img, &(txt->bpp), &(txt->length), &(txt->endian))))
    {
        ft_strdel_gnl(&line);
        ft_err(cube, "textures could not load 2\n");
    }
    (cube->map.all_param)++;
}