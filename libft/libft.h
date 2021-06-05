/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:37:53 by sehhong           #+#    #+#             */
/*   Updated: 2021/06/04 15:40:04 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int				ft_strlen(const char *s);
int				ft_atoi(const char *str);
void			ft_putnstr(char *str, int nbr);
void			ft_putchar(char c);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strncpy(char *dest, char *src, int n);
char			*ft_itoa(long n);

#endif
