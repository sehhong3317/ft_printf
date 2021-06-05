/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:36:35 by sehhong           #+#    #+#             */
/*   Updated: 2021/06/05 12:03:42 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_filler(t_opts opts, char *str, int str_num, int sp_num)
{
	int		zero_num;

	zero_num = str_num - opts.sign - opts.str_len;
	if (zero_num < 0)
		zero_num = 0;
	if (opts.is_minus == 1)
	{
		if (opts.sign == 1)
			*str = '-';
		zero_insert(str, opts.sign, zero_num);
		ft_strncpy(str + zero_num + opts.sign, opts.str, opts.str_len);
		sp_insert(str, str_num, sp_num);
	}
	else
	{
		sp_insert(str, 0, sp_num);
		if (opts.sign == 1)
			str[sp_num] = '-';
		zero_insert(str, sp_num + opts.sign, zero_num);
		ft_strncpy(str + sp_num + opts.sign + zero_num, opts.str, opts.str_len);
	}
}

int			str_counter_cs(t_opts opts)
{
	int	str_num;

	if (opts.type == 's' && opts.is_prcs == 1 && opts.prcs >= 0)
		str_num = (opts.prcs < opts.str_len ? opts.prcs : opts.str_len);
	else if (opts.type == 'c' || opts.type == '%')
		str_num = 1;
	else
		str_num = opts.str_len;
	return (str_num);
}

int			str_counter_ppxxdiu(t_opts opts)
{
	int	str_num;

	if (opts.is_prcs == 1 && opts.change_flag == 0)
	{
		if (opts.prcs < opts.str_len)
			str_num = opts.str_len + opts.sign;
		else
			str_num = opts.prcs + opts.sign;
	}
	else
	{
		if (opts.prcs < opts.str_len + opts.sign)
			str_num = opts.str_len + opts.sign;
		else
			str_num = opts.prcs;
	}
	if (opts.is_prcs == 1 && opts.prcs == 0)
	{
		if (opts.type == 'p' && opts.str[2] == '0')
			str_num--;
		else if (opts.type != 'p' && opts.str[0] == '0')
			str_num--;
	}
	return (str_num);
}

int			display_format(t_opts opts)
{
	int		str_num;
	int		sp_num;
	int		malloc_cnt;
	char	*opti_str;

	if (opts.type == 'c' || opts.type == 's')
		str_num = str_counter_cs(opts);
	else
		str_num = str_counter_ppxxdiu(opts);
	if ((sp_num = (opts.width - str_num)) < 0)
		sp_num = 0;
	malloc_cnt = (str_num > opts.width ? str_num : opts.width);
	if (!(opti_str = (char*)malloc(sizeof(char) * (malloc_cnt + 1))))
		return (-1);
	format_filler(opts, opti_str, str_num, sp_num);
	opti_str[malloc_cnt] = '\0';
	ft_putnstr(opti_str, malloc_cnt);
	free(opti_str);
	if (opts.type != 's')
		free(opts.str);
	return (malloc_cnt);
}
