#include "../cub3d.h"

static int	ft_is_char_valid(char c)
{
	if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
		return (1);
	else if (c == '0' || c == '1' || c == '2' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

void    is_map_valid(t_cub3d *cube)
{
    int i;

    if (!cube->map.map_tmp)
        ft_err(cube, "map doesn't exists\n");
    else
    {
        i = 0;
        while (cube->map.map_tmp[i])
        {
            if (!ft_is_char_valid(cube->map.map_tmp[i]))
                ft_err(cube, "wrong char in the map\n");
            i++;
        }
        if (cube->var.dir == '0')
            ft_err(cube, "need a start position for the player\n");
    }
}