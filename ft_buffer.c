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

static t_struct ft_add_to_buffer(char c, t_struct datas)
{
    static int j = 0;

    datas.buf[j] = c;
    return (datas);
}

void ft_display_buf(char *buf)
{
    int i;
    int printable;

    i = 0;
    printable = 0;
    ft_putstr(buf);
    while (buf[i])
    {
        if (i == BUFF_SIZE || buf[i] == '\n')
        {
            printable = 1;
            break;
        }
        i++;
    }
    if (printable == 1)
        ft_putstr(buf);

}

int ft_buffer(char c, t_struct datas)
{
    datas = ft_add_to_buffer(c, datas);
    ft_display_buf(datas.buf);
    return (1);
}
