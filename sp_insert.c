/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:33:43 by sehhong           #+#    #+#             */
/*   Updated: 2021/05/28 20:33:22 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sp_insert(char *str, int start, int size)
{
	int	i;

	i = start;
	while (size)
	{
		str[start] = ' ';
		start++;
		size--;
	}
}