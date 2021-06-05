/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:44:34 by sehhong           #+#    #+#             */
/*   Updated: 2021/06/05 11:15:09 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_opts
{
	int		is_minus;
	int		is_zero;
	int		width;
	int		is_prcs;
	int		prcs;
	char	*str;
	int		str_len;
	int		sign;
	char	type;
	int		change_flag;
}				t_opts;

int				ft_strlen(const char *s);
void			ft_putchar(char c);
void			ft_putnstr(char *str, int nbr);
int				ft_atoi(const char *str);
char			*ft_itoa(long n);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strncpy(char *dest, char *src, int n);

int				type_check(char c);
void			flag_check(t_opts *opts, char **str);
void			width_check(t_opts *opts, char **str, va_list ap);
void			precs_check(t_opts *opts, char **str, va_list ap);

void			init_option(t_opts *opts);
int				malloc_counter(unsigned long long nb, char c);
char			*hexa_converter(unsigned long long nb, char c);
void			zero_insert(char *str, int start, int size);
void			sp_insert(char *str, int start, int size);

void			format_filler(t_opts opts, char *str, int str_num, int sp_num);
int				str_counter_cs(t_opts opts);
int				str_counter_ppxxdiu(t_opts opts);
int				display_format(t_opts opts);

int				type_check(char c);
void			flag_check(t_opts *opts, char **str);
void			width_check(t_opts *opts, char **str, va_list ap);
void			precs_check(t_opts *opts, char **str, va_list ap);

int				arg_extracter_csp(t_opts *opts, va_list ap, char c);
int				arg_extracter_diu(t_opts *opts, va_list ap, char c);
int				arg_extracter_pxx(t_opts *opts, va_list ap, char c);

int				format_optimizer(t_opts *opts, va_list ap, char c);
void			opts_priority(t_opts *opts);
int				format_analyzer(va_list ap, char **str);
int				format_parser(char *str, va_list ap);
int				ft_printf(const char *format, ...);

#endif
