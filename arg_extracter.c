/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_extracter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:44:12 by sehhong           #+#    #+#             */
/*   Updated: 2021/06/05 14:59:51 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		arg_extracter_csp(t_opts *opts, va_list ap, char c)
{
	char				*ptr_char;
	char				*tmp;

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
		opts->str_len = 1;
	}
	else
	{
		if ((tmp = va_arg(ap, char *)) == NULL)
			opts->str = "(null)";
		else
			opts->str = tmp;
		opts->str_len = ft_strlen(opts->str);
	}
	return (0);
}

int		arg_extracter_diu(t_opts *opts, va_list ap, char c)
{
	long				nb;

	if (c == 'u')
	{
		opts->str = ft_itoa(va_arg(ap, unsigned int));
		opts->str_len = ft_strlen(opts->str);
	}
	else
	{
		nb = va_arg(ap, int);
		if (nb < 0)
		{
			opts->sign = 1;
			nb = -nb;
		}
		opts->str = ft_itoa(nb);
		opts->str_len = ft_strlen(opts->str);
	}
	return (0);
}

int		arg_extracter_pxx(t_opts *opts, va_list ap, char c)
{
	unsigned long long	ull;

	if (c == 'p')
	{
		ull = va_arg(ap, unsigned long long);
		opts->str = hexa_converter(ull, 'p');
		opts->str_len = ft_strlen(opts->str);
		if (opts->str == NULL)
			return (-1);
	}
	else
	{
		ull = va_arg(ap, unsigned int);
		opts->str = hexa_converter(ull, c);
		opts->str_len = ft_strlen(opts->str);
		if (opts->str == NULL)
			return (-1);
	}
	return (0);
}
