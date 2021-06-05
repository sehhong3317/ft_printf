/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:50:08 by sehhong           #+#    #+#             */
/*   Updated: 2021/06/04 15:00:04 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_option(t_opts *opts)
{
	opts->is_minus = 0;
	opts->is_zero = 0;
	opts->width = 0;
	opts->prcs = 0;
	opts->is_prcs = 0;
	opts->str = NULL;
	opts->str_len = 0;
	opts->sign = 0;
	opts->type = '\0';
	opts->change_flag = 0;
}

int		malloc_counter(unsigned long long nb, char c)
{
	int		malloc_cnt;

	malloc_cnt = 0;
	if (nb == 0)
		malloc_cnt = 1;
	while (nb)
	{
		nb /= 16;
		malloc_cnt++;
	}
	if (c == 'p')
		malloc_cnt += 2;
	return (malloc_cnt);
}

char	*hexa_converter(unsigned long long nb, char c)
{
	int					malloc_cnt;
	char				*hexa_str;

	malloc_cnt = malloc_counter(nb, c);
	hexa_str = (char*)malloc(sizeof(char) * (malloc_cnt + 1));
	if (!hexa_str)
		return (0);
	if (c == 'p')
	{
		hexa_str[0] = '0';
		hexa_str[1] = 'x';
	}
	hexa_str[malloc_cnt] = '\0';
	if (nb == 0)
		hexa_str[malloc_cnt - 1] = '0';
	while (nb)
	{
		if (c == 'X')
			hexa_str[malloc_cnt - 1] = "0123456789ABCDEF"[nb % 16];
		else
			hexa_str[malloc_cnt - 1] = "0123456789abcdef"[nb % 16];
		malloc_cnt--;
		nb /= 16;
	}
	return (hexa_str);
}

void	zero_insert(char *str, int start, int size)
{
	int	i;

	i = start;
	while (size > 0)
	{
		str[start] = '0';
		start++;
		size--;
	}
}

void	sp_insert(char *str, int start, int size)
{
	int	i;

	i = start;
	while (size > 0)
	{
		str[start] = ' ';
		start++;
		size--;
	}
}
