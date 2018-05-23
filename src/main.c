/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:28:32 by achepurn          #+#    #+#             */
/*   Updated: 2018/05/23 14:28:34 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static void		send_coords(t_board *board)
{
	ft_putnbr(board->y_place);
	ft_putchar(' ');
	ft_putnbr(board->x_place);
	ft_putchar('\n');
}

static t_board	*game(t_map *map, t_map *piece, char player)
{
	static t_board	*board = NULL;
	int				status;

	if (!board)
		board = new_board();
	board->player = player;
	get_start_positions(board, map);
	if (map->x * map->y > 400)
	{
		status = algorythm2(map, piece, board);
		if (!status)
			status = algorythm1(map, piece, board);
	}
	else
		status = algorythm1(map, piece, board);
	if (!status)
		area_4(map, piece, board);
	send_coords(board);
	board->y_start_player = board->y_place;
	board->x_start_player = board->x_place;
	return (board);
}

int				main(int c, char **v)
{
	t_map	*map;
	t_map	*piece;
	char	player;
	t_board	*board;

	(void)c;
	player = get_player(v[0]);
	while (42)
	{
		map = get_map();
		piece = get_map();
		if (!map || !piece)
			break ;
		board = game(map, piece, player);
		clear_map(&map);
		clear_map(&piece);
	}
	clear_board(&board);
	return (0);
}
