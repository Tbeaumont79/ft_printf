/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:54:43 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/13 17:19:21 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFF_SIZE 4096

# include <unistd.h>
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
	neg,
	conv,
	star,
}					t_flags;

typedef	struct		s_struct
{
	size_t	arg_len;
	char	*str;
	char	buf[4096];
	int		buf_index;
	int		flag[9];
}					t_struct;

long				ft_abs(long nb);
int					ft_printf(const char *s, ...);
long				nb_len(long nb, int base);
int					ft_parse(va_list ap, t_struct datas, const char *s);
char				*string_lower(char *s);
char				*ft_itoa_base(t_struct datas, long nb, int base);
void				ft_display_buf(char *buf);
t_struct			fill_if_neg(t_struct datas, int sizes);
t_struct			fill_size_neg(t_struct datas, int len_arg);
t_struct			fill_if_neg(t_struct datas, int sizes);
t_struct			handle_neg(t_struct datas, long nb, int base);
t_struct			ft_buffer(char c, t_struct datas);
t_struct			ft_left_justify(t_struct datas, int len_arg);
t_struct			fill_right_justify_prec(t_struct datas, int len_arg, int p);
t_struct			ft_right_justify(t_struct datas, int len_arg, int prec_len);
t_struct			fill_if_prec(t_struct datas, int len_arg, int prec_len);
t_struct			ft_disp(va_list ap, t_struct datas, int i, const char *s);
t_struct			ft_width(va_list ap, t_struct datas, const char *s, int i);
t_struct			pf_d(va_list ap, t_struct datas, int i, const char *s);
t_struct			pf_s(va_list ap, t_struct datas, int i, const char *s);
t_struct			pf_xu(va_list ap, t_struct datas, int i, const char *s);
t_struct			pf_x(va_list ap, t_struct datas, int i, const char *s);
t_struct			pf_p(va_list ap, t_struct datas, int i, const char *s);
t_struct			pf_c(va_list ap, t_struct datas, int i, const char *s);
t_struct			pf_u(va_list ap, t_struct datas, int i, const char *s);
t_struct			pf_pct(va_list ap, t_struct datas, int i, const char *s);
t_struct			get_flag(va_list ap, t_struct datas, const char *s, int i);
t_struct			get_int(t_struct datas, int tmp, const char *s);
t_struct			fill_size(t_struct datas, int len_arg);
t_struct			handle(t_struct datas, int len, int prec_len, int val);
t_struct			display(t_struct datas, char *string_value, int len);
#endif
