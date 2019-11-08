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
	char str[BUFF_SIZE];
	char buf[BUFF_SIZE];
	size_t start;
    size_t index_buf;
    size_t arg_len;
}					t_struct;

int     ft_buffer(t_struct datas);
int		ft_parse(va_list ap, t_struct datas, const char *s);
int		ft_dispatcher(va_list ap, t_struct datas);
int		pf_c(va_list ap, t_struct datas);
int		pf_s(va_list ap, t_struct datas);
void	ft_display_buf(t_struct datas);
#endif
