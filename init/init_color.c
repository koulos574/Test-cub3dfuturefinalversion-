#include "../cub3d.h"

static int ft_space(char *str, int i)
{
    while (ft_isdigit(str[i]))
        i++;
    while (str[i] == ' ')
        i++;
    while (str[i] == ',')
        i++;
    return (i);
}

static void ft_check_and_make_color(t_cub3d *cube, int r, int g, int b, int color)
{
    if ((r < 0 || 255 < r) || (g < 0 || 255 < g) || (b < 0 || 255 < b))
        ft_err(cube, "wrong data for colors");
    color = r;
	color = (color << 8) + g;
	color = (color << 8) + b;
}

void    init_color(t_cub3d *cube, char *line, t_color *color)
{
    int i;

    i = 1;
    while (line[i])
    {
        if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != ',')
        {
            ft_strdel_gnl(&line);
            ft_err(cube, "Color params wrong\n");
        }
        i++;
    }
    i = 1;
    i = ft_space(line, i);
    color->r = ft_atoi(&line[i]);
    i = ft_space(line, i);
    color->g = ft_atoi(&line[i]);
    i = ft_space(line, i);
    color->b = ft_atoi(&line[i]);
    ft_check_and_make_color(cube, color->r, color->g, color->b, color->color);
    (cube->map.all_param)++;
}
