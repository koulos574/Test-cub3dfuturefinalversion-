# include "../cub3d.h"

static void     set_var_textures(t_text *text)
{
  text->relative_path = NULL;
  text->img = NULL;
  text->img_width = 0;
  text->img_height = 0;
  text->img_addr = NULL;
  text->bpp = 0;
  text->length = 0;
  text->endian = 0;
}

void            init_var_texture(t_cub3d *cube)
{
    int i;

    i = 0;
    while (i < 5)
        set_var_textures(&cube->text[i++]);
    printf("init sprite in file init_var_2\n");
}