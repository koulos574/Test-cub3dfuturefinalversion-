#include "cub3d.h"

int     ft_err(t_cub3d *cube, char *error)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(error, 2);
    // free mon cube && destroy
    return (/*freemoncube*/0);
}

void    free_all_and_exit(t_cub3d *cube)
{
    exit(1); 
    /*
    ** exit(0) means a clean exit without an error
    **exit(1) means there was an error and that is the reason for the exit
    */
}