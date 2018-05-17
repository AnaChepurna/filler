#include "../filler.h"

t_map	*new_map(void)
{
	t_map	*res;

	if ((res = (t_map *)malloc(sizeof(t_map))))
		res->map = NULL;
	return (res);
}

void	clear_map(t_map **map)
{
	if (*map && (*map)->map)
		ft_arrfree((&(*map)->map));
	if (*map)
		free(*map);
	*map = NULL;
}

void	parse_size(t_map *map, int *mode)
{
	char	*str;
	int		len;

	len = 8;
	*mode = PIECE;
	if (get_next_line(1, &str) > 0)
	{
		if (ft_strnequ(str, "Plateau ", 8))
			*mode = MAP;
		else if (ft_strnequ(str, "Piece ", 6))
			len = 6;
		map->y = ft_atoi(str + len);
		while (ft_isdigit(*(str + len)))
			len++;
		map->x = ft_atoi(str + len);
		free(str);
		if ( *mode == MAP && get_next_line(1, &str) > 0)
			free(str);
		else if (*mode == MAP)
			input_error();
	}
	else
		input_error();
}

void	parse_map(t_map *map, int mode)
{
	char	*str;
	char	**res;
	int		i;

	if ((res = (char **)malloc(sizeof(char *) * (map->y + 1))))
	{
		i = -1;
		while (++i < map->y)
		{
			if (get_next_line(1, &str) <= 0)
				input_error();
			res[i] = ft_strdup(str + mode);
			free(str);
		}
		res[i] = NULL;
	}
	map->map = res;
}

t_map	*get_map(void)
{
	t_map	*map;
	int		mode;

	if ((map = new_map()))
	{
		parse_size(map, &mode);
		parse_map(map, mode);
	}
	return (map);
}