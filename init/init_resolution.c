#include "../cub3d.h"

static void check_correct_size_window(t_cub3d *cube, int i, char *line)
{
    if (line[i])
    {    
        ft_strdel_gnl(&line);
        ft_err(cube, "Too much params, resolution only need 2\n");
    }
    if (cube->map.widthscreen <= 0 || cube->map.heightscreen <= 0)
        ft_err(cube, "Resolution need to have a positive W and H");
    if (cube->map.widthscreen < 480)
        cube->map.widthscreen = 480;
    if (cube->map.heightscreen < 320)
        cube->map.heightscreen = 320;
    if (cube->map.widthscreen >= 2560)
        cube->map.widthscreen = 2560;
    if (cube->map.heightscreen >= 1440)
        cube->map.heightscreen = 1440;
    //init_window(cube);
    (cube->map.all_param)++;
    printf("%d%d", cube->map.widthscreen, cube->map.heightscreen);
}

void    init_resolution(t_cub3d *cube, char *line)
{
    int i;

    i = 1;
    while(line[i])
    {
        if (!ft_isdigit(line [i]) && line[i] != ' ')
        {
            ft_strdel_gnl(&line);
            ft_err(cube, "Resolutions params are false \n");
        }
        i++;
    }
    i = 1;
    while (line[i] == ' ')
        i++;
    cube->map.widthscreen = ft_atoi(&line[i]);
    while (ft_isdigit(line[i]))
        i++;
    while (line[i] == ' ')
        i++;
    cube->map.heightscreen = ft_atoi(&line[i]);
    while (ft_isdigit(line[i]))
        i++;
    check_correct_size_window(cube, i, line);
}