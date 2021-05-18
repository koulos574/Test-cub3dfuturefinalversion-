#include "../cub3d.h"

int     ft_dir(char z)
{
    if (z == 'S' || z == 'E' || z == 'N' || z == 'W')
        return (1);
    return (0);
}

int     ft_endmap(char *line)
{
    int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\n'
			&& line[i] != '\t' && line[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int     ft_is_in_map(char *line)
{
    int i;

    i = 0;
    if (line)
    {
        while (line[i])
        {
            if (!ft_isdigit(line[i]) && !ft_dir(line[i]) && line[i] != ' ')
                return (0);
            i++;
        }
        return (1);
    }
    else
        return (0);
}

char	*ft_strjoin_and_free(char *map, char *line)
{
	char *tmp;

	if (map == NULL)
		map = ft_strdup(line);
	else if (*map == '\0')
	{
		free(map);
		map = ft_strdup(line);
	}
	else
	{
		tmp = ft_strdup(map);
		free(map);
		map = ft_strjoin(tmp, line);
		free(tmp);
	}
	return (map);
}

void	free_split(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}