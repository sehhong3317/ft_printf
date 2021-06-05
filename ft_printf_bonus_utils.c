/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 13:35:13 by sehhong           #+#    #+#             */
/*   Updated: 2021/06/05 14:50:25 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	n_return(int final_ret, va_list ap)
{
	int	*ptr_int;

	ptr_int = va_arg(ap, int*);
	*ptr_int = final_ret;
}
