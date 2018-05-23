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

int main(int c, char **v)
{
	int 	t;

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
	return 0;
}
