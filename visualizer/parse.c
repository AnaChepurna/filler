#include "visualizer.h"

static void		print_color(char *str, char *color, int mode)
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

static int		parse_results(char **str)
{
	// ft_putendl_fd(str, 2);
	// usleep(10000);
	if (ft_strnequ("==", *str, 2))
	{
		print_color(*str, RED, STR);
		get_next_line(0, str);
		print_color(*str, RED, STR);
		//sleep(10);
		return (1);
	}
	return (0);
}

static int		parse_size(int *x, int *y)
{
	char	*str;
	int		len;

	len = 8;
	if (get_next_line(0, &str) > 0)
	{
		if (ft_strnequ(str, "Plateau ", len))
		{
			ft_putstr_fd(tgetstr("cl", NULL), 2);
			*y = ft_atoi(str + len);
			while (ft_isdigit(*(str + len)))
				len++;
			*x = ft_atoi(str + len);
			print_color(str, YELLOW, STR);
			get_next_line(0, &str);
			print_color(str, YELLOW, STR);
			return (1);
		}
		else if (!parse_results(&str))
		{
			free(str);
			return (parse_size(x, y));
		}
	}
	return (0);
}

static int		parse_map(int x, int y)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	while (++i < y)
	{
		if (get_next_line(0, &str) <= 0)
			return (0);
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
		free(str);
	}
	return (1);
}

int			get_map(void)
{
	int		x;
	int		y;

	if (parse_size(&x, &y) && parse_map(x, y))
	{
		return (1);
	}
	else
	{

		return (0);
	}
}