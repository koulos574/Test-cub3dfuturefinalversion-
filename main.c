#include "cub3d.h"


// void     check_info(t_cube *cube, char *str)
// {
//     if (str[0] == 'R')
//         init_resolution(cube, str);
//     if (str[0] == 'N' && str[1] == 'O')
//         init_texture(cube, &cube->txt_info.NO, str);
//     if (str[0] == 'W' && str[1] == 'E')
//         init_texture(cube, &cube->txt_info.WE, str);
//     if (str[0] == 'S' && str[1] == 'O')
//          init_texture(cube, &cube->txt_info.SO, str);
//     if (str[0] == 'E' && str[1] == 'A')
//         init_texture(cube, &cube->txt_info.EA, str);
//     if (str[0] == 'S' && str[1] != 'O')
//         init_texture(cube, &cube->txt_info.sprite, str);
//     if (str[0] == 'F')
//         init_color(cube, str, &cube->txt_info.col_floor);
//     if (str[0] == 'C')
//         init_color(cube, str, &cube->txt_info.col_ceil);
//     if (cube->all_param == 8)
//         init_map(cube, str);
// }

static void     game_start(t_cub3d *cube)
{
    mlx_hook(cube->mlx.win, 2, 0, key_press, cube);
    mlx_hook(cube->mlx.win, 3, 0, key_release, cube);
    mlx_hook(cube->mlx.win, 17, 0, free_all_and_exit, cube);
    mlx_loop_hook(cube->mlx.ptr, raycasting, cube);
    mlx_loop(cube->mlx.ptr);
}

static void     lets_go(t_cub3d *cube, char *map, int save)
{
    cube = (t_cub3d *)malloc(sizeof(t_cub3d));
    init_all_var(cube);
    read_map(cube, map);
    game_start(cube);
}

int             main(int ac, char **av)
{
    // gcc main.c ft_error.c  gnl/*.c init/*.c libft/*.c -L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit && ./a.out map.cub
    t_cub3d cube;


    //if (!(cube = (t_cub3d)malloc(sizeof(t_cub3d)))
    //    return(free_all_and_exit);
    //je peux pas apl ft_err car je free cube la dedans donc bon, je peux pas free qqch que j'ai pas malloc
    //if (ac < 2 || ac > 3)
    //exit le game et free le cube
    // else if (ac == 2 && !check les args le .cub)
    // else if (ac == 3 && !check les args le .cub et bmp)
    lets_go(&cube, av[1], 0);
    return (0);
}