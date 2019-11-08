/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bod <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:48:59 by bod               #+#    #+#             */
/*   Updated: 2019/11/08 14:05:35 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int     ft_add_to_buffer(t_struct datas)
{
    size_t len;
    size_t i;
  
    i = datas.index_buf;
    printf("%lu\n", datas.start);
    len = datas.start + datas.arg_len;
    while (datas.start < len)
    {
        datas.buf[datas.index_buf] = datas.str[i];
        printf("%c%lu:%c%lu\n", datas.buf[datas.index_buf],datas.index_buf, datas.str[datas.start], datas.start);
        datas.index_buf++;
        datas.start++;
        i++;
    }
    datas.buf[datas.index_buf] = '\0';
    printf(" I EAT THE FISH %s\n",datas.buf);
	//printf("I = %d\n", i);
	//printf("%s\n",tmp);
	//printf("LA SIZE : %lu\n", ft_strlen(datas->str));
	return (1);	
}

void	ft_display_buf(t_struct datas)
{
	int i;

	i = 0;
	while (datas.buf[i])
	{
		if (i == BUFF_SIZE || datas.buf[i] == '\n')
        {
            datas.buf[i] = '\0';
			ft_putstr(datas.buf);
        }
		i++;
	}
}

int    ft_buffer(t_struct datas)
{
    int i;

    i = 0;
    ft_add_to_buffer(datas);
    return (1);
}
