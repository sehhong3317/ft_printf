/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:32:18 by sehhong           #+#    #+#             */
/*   Updated: 2021/05/30 19:16:23 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				type_check(char c)
{
	char	*specifier;

	specifier = "cspdiu%xX";

	while (*specifier)
	{
		if (*specifier == c)
			return (1);
		specifier++;
	}
	return (0);
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

static int	display_string(t_opts opts, char c)
{
	int		str_num;
	int		sp_num;
	int		malloc_cnt;
	char	*opti_str;

	if (c == 's')
	{
		if (opts.precis < ft_strlen(opts.str))
			str_num = opts.precis;
		else
			str_num = ft_strlen(opts.str);
	}
	else
		str_num = 1;
	if ((sp_num = (opts.width - str_num)) < 0)
		sp_num = 0;
	malloc_cnt = (str_num > opts.width ? str_num : opts.width);
	if (!(opti_str = (char*)malloc(sizeof(char) * (malloc_cnt + 1))))
		return (-1);
	str_maker(opts, opti_str, str_num, sp_num);
	opti_str[malloc_cnt] = '\0';
	ft_putstr(opti_str);
	free(opti_str);
	free(opts.str);   // not sure if this has to be address or use pointer?
	return (malloc_cnt);
}

static int		arg_extracter(t_opts *opts, va_list ap, char c)
{
	char	*ptr_char;

	ptr_char = (char*)malloc(sizeof(char) * 2);
	if (!ptr_char)
		return (-1);
	ptr_char[1] = '\0';
	if (c == 'c')
	{
		ptr_char[0] = va_arg(ap, int);
		opts->str = ptr_char;
	}
	else if (c == '%')
	{
		ptr_char[0] = '%';
		opts->str = ptr_char;
	}
	else if (c == 's')
		opts->str = va_arg(ap, char *);
	return (0);
}

static	int		format_optimizer(t_opts *opts, va_list ap, char c)
{
	int		ret;
	int		(*fp)(t_opts, char);

	ret = arg_extracter(opts, ap, c);
	if (ret == -1)
		return (-1);
	if (c == 's' || c == 'c' || c == '%')
		fp = display_string;
	else
		fp = 0;
	ret = fp(*opts, c);
	return (ret);
}

static int		format_analyzer(va_list ap, char *str)
{
	t_opts	opts;
	int		final_count;

	init_option(&opts);
	str++;
	while (!type_check(*str))
	{
		str = flag_check(&opts, str);
		str = width_check(&opts, str, ap);
		str = precs_check(&opts, str, ap);
	}
	final_count = format_optimizer(&opts, ap, *str);
	str++;
	return (final_count);
}

int				ft_printf(const char *format, ...)
{
	char	*str;
	va_list	ap;
	int		final_ret;
	int		ret;

	va_start(ap, format);
	str = (char *)format;
	ret = 0;
	final_ret = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if ((ret = format_analyzer(ap, str)) == -1)
				return (-1);
			else
			{
				final_ret += ret;
				str++;
				while (!type_check(*str))
					str++;
			}
			str++;
		}
		else
		{
			ft_putchar(*str++);
			final_ret++;
		}
	}
	va_end(ap);
	return (final_ret);
}

int		main(void)
{
	int	a,b;
	int	ret;

	a = 7;
	b = 10;
	ret = printf("%p", &a);
	printf("\n---------\n");
	printf("%p", &b);
	printf("\n---------\n");
	printf("ret: %d", ret);
}
