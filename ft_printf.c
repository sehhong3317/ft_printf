/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:32:18 by sehhong           #+#    #+#             */
/*   Updated: 2021/05/28 20:36:22 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	str_maker(t_opts opts, char *str, int str_num, int sp_num)
{
	if (opts.is_minus == 1)
	{
		ft_strncpy(str, opts.str, str_num);
		sp_insert(str, str_num, sp_num);
	}
	else
	{
		sp_insert(str, 0, sp_num);
		ft_strncpy(str + sp_num, opts.str, str_num);
	}
}

static	void	display_str(t_opts opts)
{
	int		str_num;
	int		sp_num;
	int		malloc_cnt;
	char	*opti_str;

	if (opts.precis < ft_strlen(opts.str))
		str_num = opts.precis;
	else
		str_num = ft_strlen(opts.str);
	sp_num = opts.width - str_num;
	if (sp_num < 0)
		sp_num = 0;
	malloc_cnt = (str_num > opts.width ? str_num : opts.width);
	opti_str = (char*)malloc(sizeof(char) * (malloc_cnt + 1));
	// if (!opti_str)
	// 	return (-1);
	str_maker(opts, opti_str, str_num, sp_num);
	opti_str[malloc_cnt] = '\0';
	ft_putstr(opti_str);
	free(opti_str);
}

static char		*flag_check(t_opts *opts, char *str)
{
	if (*str == '-')
	{
		opts->is_minus = 1;
		str++;
	}
	return (str);
}

static char		*width_check(t_opts *opts, char *str, va_list ap)
{
	if (*str >= '0' && *str <= '9')
		opts->width = ft_atoi(str);
	else if (*str == '*')
	{
		opts->width = va_arg(ap, int);
		str++;
	}
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}

static char		*precs_check(t_opts *opts, char *str, va_list ap)
{
	if (*str == '.')
	{
		str++;
		if (*str >= '0' && *str <= '9')
			opts->precis = ft_atoi(str);
		else if (*str == '*')
		{
			opts->precis = va_arg(ap, int);
			str++;
		}
		while (*str >= '0' && *str <= '9')
			str++;
	}
	return (str);
}

static char		*format_analyzer(va_list ap, char *str)
{
	t_opts	opts;

	init_option(&opts);
	str++;
	while (*str != 's')
	{
		str = flag_check(&opts, str);
		str = width_check(&opts, str, ap);
		str = precs_check(&opts, str, ap);
	}
	opts.str = va_arg(ap, char *);
	str++;
	display_str(opts);
	return (str);
}

int				ft_printf(const char *format, ...)
{
	char	*str;
	va_list	ap;

	va_start(ap, format);
	str = (char *)format;
	while (*str)
	{
		if (*str == '%')
			str = format_analyzer(ap, str);
		else
			ft_putchar(*str++);
	}
	va_end(ap);
	return (0);
}

int		main()
{
	ft_printf("str:%-*.*s", 3, 4, "abcde");  //abcde
}
