/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:50:39 by sehhong           #+#    #+#             */
/*   Updated: 2021/06/03 11:00:42 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sp_end_index(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\r' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == ' ' || str[i] == '\n' || str[i] == '\f')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	ret;

	ret = 0;
	sign = 1;
	i = sp_end_index(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	if (ret >= 9223372036854775807 && sign > 0)
		return (-1);
	else if (ret >= 9223372036854775807 && sign < 0)
		return (0);
	return (sign * ret);
}
