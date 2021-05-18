#include "../cub3d.h"

void    create_map(t_cub3d *cube)
{
    int i;
    char **tmp;

    i = 0;
    tmp = ft_split(cube->map.map_tmp, '\n');
    if (!(cube->map.the_map = (int **)malloc(sizeof(int *) * cube->map.nb_line)))
        ft_err(cube, "malloc failed");
    while (i < cube->map.nb_line)
    {
        cube->map.the_map[i] = make_row_int(tmp[i], cube, i);
        i++; 
    }
    free_split(tmp);
}

void    has_map_started(t_cub3d *cube, char *line)
{
    if (line[0] != '\0')
    {
        cube->map.map_start = 1; 
        get_map(cube, line);
    }
}

void    reset_map(t_cub3d *cube)
{
    int y;
    int x;

    y = 0;
    while (y < cube->map.nb_line)
    {
        x = 0;
        while (x < cube->map.longueur_max_ligne)
        {
            if (cube->map.the_map[y][x] == 6)
                cube->map.the_map[y][x] = 0;
            if (cube->map.the_map[y][x] == 5)
                cube->map.the_map[y][x] = 2;
            x++;
        }
        y++;
    }
}

void    flood_fill(t_cub3d *cube, int x, int y)
{
    if (x < 0 || x >= cube->map.longueur_max_ligne)
        ft_err(cube, "the map is not closed\n");
    else if (y < 0 || y >= cube->map.nb_line)
        ft_err(cube, "the map is not closed\n");
    else if (cube->map.the_map[y][x] == 1 || cube->map.the_map[y][x] == 5 || cube->map.the_map[y][x] == 6
               || (cube->map.the_map[y][x] != 0  && cube->map.the_map[y][x] != 2))
        return;
    if (cube->map.the_map[y][x] == 0)
        cube->map.the_map[y][x] = 6;
    else if (cube->map.the_map[y][x] == 2)
        cube->map.the_map[y][x] = 5;
    flood_fill(cube, x + 1, y);
    flood_fill(cube, x - 1, y);
    flood_fill(cube, x, y + 1);
    flood_fill(cube, x, y - 1);
}

void    check_map(t_cub3d *cube)
{
    is_map_valid(cube);
    if (cube->var.posX < 0 || cube->var.posX >= cube->map.longueur_max_ligne)
        ft_err(cube, "let's review the map, is there anything missing or wrong?\n");
    if (cube->var.posY < 0 || cube->var.posY >= cube->map.nb_line)
        ft_err(cube, "let's review the map, is there anything missing or wrong?\n");
    if (cube->map.longueur_max_ligne < 3 || cube->map.nb_line < 3)
        ft_err(cube, "I think the map is too small :/\n");
    flood_fill(cube, cube->var.posX, cube->var.posY);
    reset_map(cube);
}