/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:28:53 by achepurn          #+#    #+#             */
/*   Updated: 2018/05/23 14:28:54 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

char			get_player(char *name)
{
	char	*str;

	if (get_next_line(0, &str) > 0)
	{
		if (ft_strstr(str, name))
		{
			if (ft_strstr(str, "p1"))
			{
				free(str);
				return (P1);
			}
			if (ft_strstr(str, "p2"))
			{
				free(str);
				return (P2);
			}
		}
		free(str);
	}
	return (0);
}

static int		parse_size(t_map *map, int *mode)
{
	char	*str;
	int		len;

	len = 8;
	*mode = PIECE;
	if (get_next_line(0, &str) > 0)
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
		if (*mode == MAP && get_next_line(0, &str) > 0)
			free(str);
		return (1);
	}
	return (0);
}

static void		parse_map(t_map *map, int mode)
{
	char	*str;
	char	**res;
	int		i;

	if ((res = (char **)malloc(sizeof(char *) * (map->y + 1))))
	{
		i = -1;
		while (++i < map->y)
		{
			if (get_next_line(0, &str) > 0)
			{
				res[i] = ft_strdup(str + mode);
				free(str);
			}
		}
		res[i] = NULL;
	}
	map->map = res;
}

t_map			*get_map(void)
{
	t_map	*map;
	int		mode;

	if ((map = new_map()))
	{
		if (!parse_size(map, &mode))
		{
			clear_map(&map);
			return (NULL);
		}
		parse_map(map, mode);
	}
	return (map);
}
