/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:40:44 by sehhong           #+#    #+#             */
/*   Updated: 2021/06/05 16:55:39 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			type_check(char c)
{
	char	*specifier;

	specifier = "cspdiu%xXn";
	while (*specifier)
	{
		if (*specifier == c)
			return (1);
		specifier++;
	}
	return (0);
}

void		flag_check(t_opts *opts, char **str)
{
	while (**str)
	{
		if (**str == '-' || **str == '0')
		{
			if (**str == '-')
				opts->is_minus = 1;
			else
				opts->is_zero = 1;
			(*str)++;
		}
		else
			break ;
	}
}

void		width_check(t_opts *opts, char **str, va_list ap)
{
	if (**str >= '0' && **str <= '9')
		opts->width = ft_atoi(*str);
	else if (**str == '*')
	{
		opts->width = va_arg(ap, int);
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
		(*str)++;
}

void		precs_check(t_opts *opts, char **str, va_list ap)
{
	if (**str == '.')
	{
		opts->is_prcs = 1;
		(*str)++;
		if (**str >= '0' && **str <= '9')
			opts->prcs = ft_atoi(*str);
		else if (**str == '*')
		{
			opts->prcs = va_arg(ap, int);
			(*str)++;
		}
		while (**str >= '0' && **str <= '9')
			(*str)++;
	}
}
