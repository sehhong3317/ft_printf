/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:34:30 by sehhong           #+#    #+#             */
/*   Updated: 2021/05/31 15:57:37 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_option(t_opts *opts)
{
	opts->is_minus = 0;
	opts->is_zero = 0;
	opts->width = -1;
	opts->precis = -1;
	opts->str = NULL;
	opts->nbr_digit = -1;
	opts->nbr_neg = 0;
}
