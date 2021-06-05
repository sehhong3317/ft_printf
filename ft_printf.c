/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:01:52 by sehhong           #+#    #+#             */
/*   Updated: 2021/06/05 16:54:46 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format_optimizer(t_opts *opts, va_list ap, char c)
{
	int		ret;

	if (c == 's' || c == 'c' || c == '%')
		ret = arg_extracter_csp(opts, ap, c);
	else if (c == 'd' || c == 'i' || c == 'u')
		ret = arg_extracter_diu(opts, ap, c);
	else
		ret = arg_extracter_pxx(opts, ap, c);
	if (ret == -1)
		return (-1);
	ret = display_format(*opts);
	return (ret);
}

void	opts_priority(t_opts *opts)
{
	if (opts->width < 0)
	{
		opts->is_minus = 1;
		opts->width = -(opts->width);
	}
	if (opts->is_minus == 1)
		opts->is_zero = 0;
	if (opts->is_zero == 1 && opts->width > 0)
	{
		if (opts->is_prcs == 0)
		{
			opts->is_zero = 0;
			opts->prcs = opts->width;
			opts->width = 0;
		}
		if (opts->is_prcs == 1 && opts->prcs < 0)
		{
			opts->is_zero = 0;
			opts->change_flag = 1;
			opts->prcs = opts->width;
			opts->width = 0;
		}
	}
}

int		format_analyzer(va_list ap, char **str, int count)
{
	t_opts	opts;
	int		final_count;

	final_count = count;
	init_option(&opts);
	(*str)++;
	while (!type_check(**str))
	{
		flag_check(&opts, str);
		width_check(&opts, str, ap);
		precs_check(&opts, str, ap);
	}
	opts_priority(&opts);
	opts.type = **str;
	if (opts.type == 'n')
	{
		n_return(final_count, ap);
		return (0);
	}
	final_count = format_optimizer(&opts, ap, **str);
	return (final_count);
}

int		format_parser(char *str, va_list ap)
{
	int ret;
	int final_ret;

	ret = 0;
	final_ret = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if ((ret = format_analyzer(ap, &str, final_ret)) == -1)
				return (-1);
			else
				final_ret += ret;
			str++;
		}
		else
		{
			ft_putchar(*str++);
			final_ret++;
		}
	}
	return (final_ret);
}

int		ft_printf(const char *format, ...)
{
	char	*str;
	va_list	ap;
	int		final_ret;

	va_start(ap, format);
	str = (char*)format;
	final_ret = format_parser(str, ap);
	va_end(ap);
	return (final_ret);
}
