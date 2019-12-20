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

size_t     ft_add_to_buffer(t_struct datas)
{
    int j;

    j = 0;
    while (datas.str[j]) {
        datas.buf[j] = datas.str[j];
        j++;
    }
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
    printf("%s\n", datas.buf);
}

int    ft_buffer(t_struct datas)
{
    ft_add_to_buffer(datas);
    return (1);
}
