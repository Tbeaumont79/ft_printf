/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:54:43 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/11/08 13:59:36 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFF_SIZE 4096

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


typedef struct		s_struct
{
	char *str;
	char buf[4096];
    size_t arg_len;
}					t_struct;

int     ft_buffer(char c, t_struct datas);
int		nb_len(long nb, int base);
int		ft_parse(va_list ap, t_struct datas, const char *s);
int		ft_dispatcher(va_list ap, t_struct datas, int i, const char *s);
int		ft_abs(int nb);
int		ft_width(int val, char *str, int i, t_struct datas);
int 	pf_d(va_list ap, t_struct datas, int i);
int		pf_s(va_list ap, t_struct datas, int i);
int 	pf_XU(va_list ap, t_struct datas, int i);
int 	pf_x(va_list ap, t_struct datas, int i);
int		pf_p(va_list ap, t_struct datas, int i);
int 	pf_c(va_list ap, t_struct datas, int i);
int		pf_u(va_list ap, t_struct datas, int i);
char	*string_lower(char *s);
void	ft_display_buf(char *buf);
char	*ft_itoa_base(long long nb, int base);
#endif
