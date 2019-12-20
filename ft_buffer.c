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

static t_struct     ft_add_to_buffer(t_struct datas)
{
    int j;

    j = 0;
    ft_putstr(datas.str);
    ft_putchar('\n');
    ft_putstr(datas.buf);
    while (datas.str[j]) {
        datas.buf[j] = datas.str[j];
        j++;
    }
    datas.buf[j] = '\0';
    return (datas);
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
    datas = ft_add_to_buffer(datas);
    ft_display_buf(datas);
    return (1);
}
