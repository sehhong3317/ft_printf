/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:44:34 by sehhong           #+#    #+#             */
/*   Updated: 2021/05/31 17:11:27 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h> 

typedef struct	s_opts
{
	int		is_minus;
	int		is_zero;
	int		width;
	int		precis;
	char	*str;
	int		nbr_digit;
	int		nbr_neg;
}				t_opts;

int		ft_strlen(const char *s);
void	ft_putchar(char c);
void	init_option(t_opts *options);
//void	display_str(t_opts options);
void	ft_putstr(char *str);
//char	*format_analyzer(va_list ap, char *str);
int		ft_atoi(const char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_printf(const char *format, ...);
char	*ft_strncpy(char *dest, char *src, int n);
void	sp_insert(char *str, int start, int size);
char	*ft_itoa(long n);

# endif