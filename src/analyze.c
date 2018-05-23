/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:28:22 by achepurn          #+#    #+#             */
/*   Updated: 2018/05/23 14:28:23 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int				check_place(t_map *m, t_map *p, t_board *b)
{
	int		x;
	int		y;
	int		n;

	if (b->y_place + p->y > m->y || b->x_place + p->x > m->x)
		return (0);
	n = 0;
	y = -1;
	while (++y < p->y)
	{
		x = -1;
		while (++x < p->x)
			if (p->map[y][x] == '*')
			{
				if (m->map[y + b->y_place][x + b->x_place] == b->player - 32
					|| m->map[y + b->y_place][x + b->x_place] == b->player)
					n++;
				if (m->map[y + b->y_place][x + b->x_place] ==
					(RIVAL(b->player)) - 32 || m->map[y + b->y_place]
					[x + b->x_place] == (RIVAL(b->player)))
					return (0);
			}
	}
	return (n == 1 ? 1 : 0);
}

static int		is_near_rival(int x, int y, t_map *map, char player)
{
	int		x1;
	int		y1;
	char	rival;

	rival = RIVAL(player);
	y1 = y - 1;
	while (y1 > -1 && y1 < map->y && y1 <= y + 1)
	{
		x1 = x - 1;
		while (x1 > -1 && x1 < map->x && x1 <= x + 1)
		{
			if (map->map[y1][x1] == rival || map->map[y1][x1] == rival - 32)
				return (1);
			x1++;
		}
		y1++;
	}
	return (0);
}

int				check_place_rival(t_map *map, t_map *piece, t_board *board)
{
	int x;
	int y;

	y = -1;
	while (++y < piece->y)
	{
		x = -1;
		while (++x < piece->x)
		{
			if (piece->map[y][x] == '*' && is_near_rival(x + board->x_place,
				y + board->y_place, map, board->player))
				return (1);
		}
	}
	return (0);
}

int				check_rival(t_map *map, char player)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if ((map->map[y][x] == player || map->map[y][x] == player - 32)
				&& is_near_rival(x, y, map, player))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void			get_start_positions(t_board *b, t_map *m)
{
	static int	n = 0;
	int			x;
	int			y;

	if (n++)
		return ;
	y = -1;
	while (++y < m->y)
	{
		x = -1;
		while (++x < m->x)
		{
			if (m->map[y][x] == b->player || m->map[y][x] == b->player - 32)
			{
				b->y_start_player = y;
				b->x_start_player = x;
			}
			if (m->map[y][x] == (RIVAL(b->player)) ||
				m->map[y][x] == (RIVAL(b->player) - 32))
			{
				b->y_start_rival = y;
				b->x_start_rival = x;
			}
		}
	}
}
