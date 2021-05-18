#include "../cub3d.h"

void    check_info(t_cub3d *cube, char *str)
{
    if (str[0] == 'R')
        init_resolution(cube, str);
    if (str[0] == 'N' && str[1] == 'O')
        init_texture(cube, &cube->text[0], str);
    if (str[0] == 'W' && str[1] == 'E')
        init_texture(cube, &cube->text[1], str);
    if (str[0] == 'S' && str[1] == 'O')
         init_texture(cube, &cube->text[2], str);
    if (str[0] == 'E' && str[1] == 'A')
        init_texture(cube, &cube->text[3], str);
    if (str[0] == 'S' && str[1] == ' ')
        init_texture(cube, &cube->text[4], str);
    if (str[0] == 'F')
        init_color(cube, str, &cube->map.color_floor);
    if (str[0] == 'C')
        init_color(cube, str, &cube->map.color_ceiling);
}

int     *make_row_int(char *str, t_cub3d *cube, int current_row)
{
    int *row;
    int i;
    
    i = 0;
    if (!(row = (int *)malloc(sizeof(int) * cube->map.longueur_max_ligne)))
        ft_err(cube, "malloc failed");
    while (i < cube->map.longueur_max_ligne)
    {
        
        while (str[i])
        {
            if (ft_dir(str[i]))
            {
                set_position(cube, i, current_row);
                row[i] = 0;
            }
            else
            {
                if (ft_isdigit(str[i]))
                    row[i] = str[i] - '0';
                else
                    row[i] = 0;
            }
            i++;
        }
        while (i < cube->map.longueur_max_ligne)
            row[i++] = 0;
    }
    return (row);
}

void    get_map(t_cub3d *cube, char *line)
{
    int i;

    i = 0;
    cube->map.nb_line++;
    if (ft_strlen(line) > cube->map.longueur_max_ligne)
        cube->map.longueur_max_ligne = ft_strlen(line);
    cube->map.map_tmp = ft_strjoin_and_free(cube->map.map_tmp, line);
    cube->map.map_tmp = ft_strjoin_and_free(cube->map.map_tmp, "\n");
    while (line[i])
    {
        if (ft_dir(line[i]))
        {
            if (cube->var.dir == '0')
            {
                cube->var.dir = line[i];
                init_player_1(cube);
            }
        }
        i++;
    }
}

void    get_cub_info(t_cub3d *cube, char *line)
{
    if (cube->map.map_start)
    {
        if (cube->map.map_end && !ft_endmap(line))
            ft_err(cube, "Could you please change the format of the map?\n");
        else
        {
            if (ft_endmap(line))
                cube->map.map_end = 1;
            else if (ft_is_in_map(line))
                get_map(cube, line);            
            else if (cube->map.map_start)
                ft_err(cube, "Could you please change the format of the map?\n");
        }
    }
    else
    {
        if (ft_is_in_map(line) && cube->map.all_param == 8)
            has_map_started(cube, line);
        else
            check_info(cube, line);
    }
}

void        read_map(t_cub3d *cube, char *file)
{
    int fd;
    char *line;
    int ret;

    fd = 0;
    //cube->map.all_param = 0;
    //cube->map.map_start = 0;
    //cube->map.map_end = 0;
    //cube->map.nb_line = 0;
    //cube->map.longueur_max_ligne = 0;
    //cube->map.map_tmp = NULL;
    //cube->var.dir = '0';
    if ((fd = open(file, O_RDONLY)) == -1)
        ft_err(cube, "File does not exist\n");
    else 
    {
        while (get_next_line(fd, &line))
        {
            get_cub_info(cube, line);
            //printf("%s\n",line);
            ft_strdel_gnl(&line);
        }
        is_map_valid(cube);
        if (cube->map.all_param == 8)
            create_map(cube);
        else
            ft_err(cube, "we don't have 8 parameters please check \n");
        check_map(cube);
        close(fd);
    }
}