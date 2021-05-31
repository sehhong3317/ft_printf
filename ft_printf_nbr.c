/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:01:52 by sehhong           #+#    #+#             */
/*   Updated: 2021/05/31 20:43:04 by sehhong          ###   ########.fr       */
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
	while (*str)
	{
		if (*str == '-' || *str == '0')
		{
			if (*str == '-')
				opts->is_minus = 1;
			else
				opts->is_zero = 1;
			str++;
		}
		else
			break ;
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

static char *hexa_converter(unsigned long long nb)
{
	unsigned long long 	nbr;
	int					malloc_cnt;
	char				*hexa_str;

	malloc_cnt = 0;
	nbr = nb;
	while (nbr)
	{
		nbr /= 10;
		malloc_cnt++;
	}
	hexa_str = (char*)malloc(sizeof(malloc_cnt + 1));
	// if (!hexa_str)
	// 	return (0);
	while (malloc_cnt)
	{
		hexa_str[]
	}
	
}

static int		arg_extracter(t_opts *opts, va_list ap, char c)
{
	char	*ptr_char;
	long	nb;
	unsigned long long ull;

	ptr_char = (char*)malloc(sizeof(char) * 2);
	if (!ptr_char)
		return (-1);
	ptr_char[1] = '\0';
	if (c == 'c' || c == '%')
	{
		if (c == 'c')
			ptr_char[0] = va_arg(ap, int);
		else
			ptr_char[0] = '%';
		opts->str = ptr_char;
	}
	else if (c == 's')
		opts->str = va_arg(ap, char *);
	else if (c == 'u')
	{
		opts->str = ft_itoa(va_arg(ap, unsigned int));
		opts->nbr_digit = ft_strlen(opts->str);
	}
	else if (c == 'd' || c == 'i')
	{
		nb = va_arg(ap, int);
		if (nb < 0)
		{
			opts->nbr_neg = 1;
			nb = -nb;
		}
		opts->str = ft_itoa(nb);
		opts->nbr_digit = ft_strlen(opts->str);
	}
	else if (c == 'p')
	{
		ull = va_arg(ap, unsigned long long);
		opts->str = hexa_converter(ull);
	}
	return (0);
}

static void		zero_insert(char *str, int start, int size)
{
	int	i;

	i = start;
	while (size)
	{
		str[start] = '0';
		start++;
		size--;
	}
}

static void		nbr_maker(t_opts opts, char *str, int str_num, int sp_num)
{
	int		zero_num;

	zero_num = str_num - opts.nbr_neg - opts.nbr_digit;
	if (opts.is_minus == 1)
	{
		if (opts.nbr_neg == 1)
			*str = '-';
		zero_insert(str, opts.nbr_neg, zero_num);
		ft_strncpy(str + zero_num + opts.nbr_neg, opts.str, opts.nbr_digit);
		sp_insert(str, str_num, sp_num);
	}
	else
	{
		sp_insert(str, 0, sp_num);
		if (opts.nbr_neg == 1)
			str[sp_num] = '-';
		zero_insert(str, sp_num + opts.nbr_neg, zero_num);
		ft_strncpy(str + sp_num + opts.nbr_neg + zero_num, opts.str, opts.nbr_digit);
	}
}

static int		display_nbr(t_opts opts, char c)
{
	int		str_num;
	int		sp_num;
	int		malloc_cnt;
	char	*opti_str;

	c = 'd';  // delete it later.
	if (opts.precis < opts.nbr_digit)
		str_num = opts.nbr_digit + opts.nbr_neg;
	else
		str_num = opts.precis + opts.nbr_neg;
	if ((sp_num = (opts.width - str_num)) < 0)
		sp_num = 0;
	malloc_cnt = (str_num > opts.width ? str_num : opts.width);
	if (!(opti_str = (char*)malloc(sizeof(char) * (malloc_cnt + 1))))
		return (-1);
	nbr_maker(opts, opti_str, str_num, sp_num);
	opti_str[malloc_cnt] = '\0';
	ft_putstr(opti_str);
	free(opti_str);
	free(opts.str);
	return (malloc_cnt);
}

static int		format_optimizer(t_opts *opts, va_list ap, char c)
{
	int		ret;
	int		(*fp)(t_opts, char);

	ret = arg_extracter(opts, ap, c);
	if (ret == -1)
		return (-1);
	if (c == 's' || c == 'c' || c == '%')
		fp = display_string;
	else if (c == 'd' || c == 'i' || c == 'u')
		fp = display_nbr;
	else
		fp = 0;
	ret = fp(*opts, c);
	return (ret);
}

static void		opts_priority(t_opts *opts)
{
	if (opts->is_minus == 1)
		opts->is_zero = 0;
	if (opts->is_zero == 1 && opts->width > 0 && opts->precis < 0)
	{
		opts->is_zero = 0;
		opts->precis = opts->width;
		opts->width = -1;
	}
}

static int 		format_analyzer(va_list ap, char *str)  //takes the string from 
{														//'%'&returns a number of 
	t_opts	opts;										//optimized characters 
	int		final_count;								//read so far
	
	init_option(&opts);
	str++;
	while (!type_check(*str))
	{
		str = flag_check(&opts, str);
		str = width_check(&opts, str, ap);
		str = precs_check(&opts, str, ap);
	}
	opts_priority(&opts);
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

	a = 7;
	b = 10;
	printf("my ft_printf:\n");
	ft_printf("%*.*u", 3, 4, 23452);
	printf("\noriginal printf:\n");
	printf("%*.*d", 3, 4, 23452);
	printf("\n---------\n");
}
