/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:34:30 by sehhong           #+#    #+#             */
/*   Updated: 2021/05/30 16:19:13 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_option(t_opts *opts)
{
	opts->is_minus = 0;
	opts->width = -1;
	opts->precis = -1;
	opts->str = NULL;
}
