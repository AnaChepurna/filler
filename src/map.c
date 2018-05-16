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

void	parse_size(t_map *map)
{
	char	*str;
	int		len;

	len = 8;
	if (get_next_line(1, &str) > 0 && ft_strnequ(str, "Plateau ", len))
	{
		map->y = ft_atoi(str + len);
		while (ft_isdigit(*(str + len)))
			len++;
		map->x = ft_atoi(str + len);
		free(str);
		if (get_next_line(1, &str) > 0)
			free(str);
		else
			map_error();
	}
	else
		map_error();
}

void	parse_map(t_map *map)
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
				map_error();
			res[i] = ft_strdup(str + 4);
			free(str);
		}
		res[i] = NULL;
	}
	map->map = res;
}

t_map	*get_map(void)
{
	t_map	*map;

	if ((map = new_map()))
	{
		parse_size(map);
		parse_map(map);
	}
	return (map);
}