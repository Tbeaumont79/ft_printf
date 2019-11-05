/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bod <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:48:59 by bod               #+#    #+#             */
/*   Updated: 2019/11/05 18:44:47 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int     ft_add_to_buffer(t_struct *datas)
{
    if (!(ft_strjoin(datas->buf, datas->str)))
        return (-1);
    return (1);
}

int    ft_buffer(t_struct *datas)
{
    int i;

    i = 0;
    while (datas->buf[i])
    {
        if (datas->buf[i] == '\n')
            ft_putstr(datas->buf);
        if (!(ft_add_to_buffer(datas)))
            return (-1);
        i++;
    }
    return (1);
}
