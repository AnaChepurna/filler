/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:50:10 by achepurn          #+#    #+#             */
/*   Updated: 2018/03/21 21:50:11 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		depend_mask(char c, const char *mask)
{
	while (*mask)
	{
		if (c == *mask)
			return (1);
		mask++;
	}
	return (0);
}

static int		split_len(const char *str, const char *mask)
{
	int		i;
	char	c;

	i = -1;
	while (str[++i] && !depend_mask(str[i], mask))
	{
		if (str[i] == '"' || str[i] == '\'' || str[i] == '`')
		{
			c = str[i++];
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (i);
}

static int		recursive_count(const char *str, const char *mask)
{
	char	c;

	if (depend_mask(*str, mask))
		return (recursive_count(++str, mask));
	if (*str)
	{
		str--;
		while (*(++str) && !depend_mask(*str, mask))
		{
			if (*str == '"' || *str == '\'' || *str == '`')
			{
				c = *(str++);
				while (*str && *str != c)
					str++;
			}
		}
		return (1 + recursive_count(str, mask));
	}
	else
		return (0);
}

static int		recursive_split(char **dst, const char *str,
	const char *mask)
{
	int		i;
	char	c;

	if (depend_mask(*str, mask))
		return (recursive_split(dst, ++str, mask));
	if (*str)
	{
		if (!(*dst = ft_strnew(split_len(str--, mask))))
			return (0);
		i = 0;
		while (*(++str) && !depend_mask(*str, mask))
		{
			if (*str == '"' || *str == '\'' || *str == '`')
			{
				c = *str;
				while (*(++str) && *str != c)
					(*dst)[i++] = *str;
			}
			else
				(*dst)[i++] = *str;
		}
		return (recursive_split(++dst, str, mask));
	}
	*dst = NULL;
	return (1);
}

char			**ft_strsplitm(const char *s, const char *mask)
{
	int		len;
	char	**res;

	if (!s || !mask)
		return (NULL);
	len = recursive_count(s, mask);
	if ((res = (char **)malloc(sizeof(char *) * (len + 1))))
		if (!recursive_split(res, s, mask))
			ft_arrfree(&res);
	return (res);
}
