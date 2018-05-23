/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:29:03 by achepurn          #+#    #+#             */
/*   Updated: 2018/05/23 14:29:05 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void				print_color(char *str, char *color, int mode)
{
	ft_putstr_fd(color, 2);
	if (mode == STR)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
		free(str);
	}
	else if (mode == CHR)
		ft_putchar_fd(*str, 2);
	ft_putstr_fd(RESET, 2);
}

static int			get_map(int t)
{
	int		x;
	int		y;

	if (parse_size(&x, &y, t) && parse_map(x, y, t))
		return (1);
	return (0);
}

int					main(int c, char **v)
{
	int	t;

	t = 1;
	if (c > 1 && ft_strequ(v[1], "-t"))
		t = 0;
	if (t)
	{
		manage_term(INIT);
		manage_term(SET);
	}
	else
		ft_putstr_fd("fighting...\n", 2);
	start_signal_handling();
	while (get_map(t))
	{
		if (t)
			usleep(50000);
	}
	if (t)
	{
		sleep(20);
		manage_term(RE_SET);
	}
	return (0);
}
