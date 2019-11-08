/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:33 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/11/08 14:08:37 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
//faire un truck qui ajoute dans un tableau de tableau chaque valeur des
//argument puis remplacer les %s 
int		ft_parse(va_list ap, t_struct datas, const char *s)
{
	datas.start = 0;
    datas.index_buf = 0;
    ft_memcpy(datas.str, s, ft_strlen(s));
	while (datas.str[datas.start])
	{
		if (datas.str[datas.start] == '%')
        {
			datas.index_buf = datas.index_buf + ft_dispatcher(ap, datas);
            datas.start = datas.start + 1;
        }
        else
            datas.buf[datas.index_buf] = datas.str[datas.start];
		datas.start++;
        datas.index_buf++;
        printf("\n\nDATA BUF : %s buf.size : %lu et datas.str: %s et str.size : %lu \n\n",datas.buf, datas.index_buf,datas.str, datas.start);
	}
	ft_display_buf(datas);
	return (0);
}
