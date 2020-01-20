/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:54:43 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/20 10:09:02 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFF_SIZE 4096

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef enum		e_flags
{
	flags,
	width,
	size,
    size_prec,
    prec,
	temp,
}					t_flags;

typedef struct		s_struct
{
	char *str;
	char buf[4096];
	int buf_index;
	int flag[6];
    size_t arg_len;
}					t_struct;

int		ft_printf(const char *s, ...);
t_struct	fill_if_neg(t_struct datas, int sizes);
t_struct	handle_neg(t_struct datas, long long nb, int base, int prec_len);
t_struct     ft_buffer(char c, t_struct datas);
t_struct	ft_left_justify(t_struct datas, int len_arg);
t_struct	fill_right_justify_prec(t_struct datas, int len_arg, int prec_len);
t_struct	ft_right_justify(t_struct datas, int len_arg, int prec_len);
t_struct     fill_if_prec(t_struct datas, int len_arg, int prec_len);
int		nb_len(long nb, int base);
int		ft_parse(va_list ap, t_struct datas, const char *s);
t_struct		ft_dispatcher(va_list ap, t_struct datas, int i, const char *s);
int		ft_abs(int nb);
t_struct		ft_width(va_list ap, t_struct datas, const char *s, int i);
t_struct 	pf_d(va_list ap, t_struct datas, int i, const char *s);
t_struct		pf_s(va_list ap, t_struct datas, int i, const char *s);
t_struct 	pf_XU(va_list ap, t_struct datas, int i, const char *s);
t_struct	pf_x(va_list ap, t_struct datas, int i, const char *s);
t_struct		pf_p(va_list ap, t_struct datas, int i, const char *s);
t_struct	pf_c(va_list ap, t_struct datas, int i, const char *s);
t_struct	pf_u(va_list ap, t_struct datas, int i, const char *s);
t_struct	get_flag(va_list ap, t_struct datas, const char *s, int i);
t_struct get_int(t_struct datas, int tmp, const char *s);
char	*string_lower(char *s);
void	ft_display_buf(char *buf);
char	*ft_itoa_base(t_struct datas, long long nb, int base);
t_struct	fill_size(t_struct datas, int len_arg);
#endif
