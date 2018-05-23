/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:29:10 by achepurn          #+#    #+#             */
/*   Updated: 2018/05/23 14:29:12 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static int		parse_results(char **str)
{
	if (ft_strnequ("==", *str, 2))
	{
		print_color(*str, RED, STR);
		get_next_line(0, str);
		print_color(*str, RED, STR);
		return (1);
	}
	return (0);
}

static void		print_size(char *str, int *y, int *x, int len)
{
	ft_putstr_fd(tgetstr("cl", NULL), 2);
	*y = ft_atoi(str + len);
	while (ft_isdigit(*(str + len)))
		len++;
	*x = ft_atoi(str + len);
	print_color(str, YELLOW, STR);
	get_next_line(0, &str);
	print_color(str, YELLOW, STR);
}

int				parse_size(int *x, int *y, int t)
{
	char	*str;
	int		len;

	len = 8;
	if (get_next_line(0, &str) > 0)
	{
		if (ft_strnequ(str, "Plateau ", len))
		{
			if (!t)
			{
				free(str);
				return (1);
			}
			print_size(str, y, x, len);
			return (1);
		}
		else if (!parse_results(&str))
		{
			free(str);
			return (parse_size(x, y, t));
		}
	}
	return (0);
}

static void		print_map(char *str, int x)
{
	int	j;

	j = -1;
	while (++j < 4)
		print_color(str + j, YELLOW, CHR);
	j = -1;
	while (++j < x)
	{
		if (str[4 + j] == 'O' || str[4 + j] == 'o')
			print_color(str + j + 4, MAGENTA, CHR);
		else if (str[4 + j] == 'x' || str[4 + j] == 'X')
			print_color(str + j + 4, CYAN, CHR);
		else
			ft_putchar_fd(str[4 + j], 2);
	}
	ft_putstr_fd("\n", 2);
}

int				parse_map(int x, int y, int t)
{
	char	*str;
	int		i;

	i = -1;
	while (++i < y)
	{
		if (get_next_line(0, &str) <= 0)
			return (0);
		if (!t)
		{
			free(str);
			return (1);
		}
		print_map(str, x);
		free(str);
	}
	return (1);
}
