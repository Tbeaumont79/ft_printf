/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:17:48 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/17 13:18:11 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

// voire pour declare une statique et faire en sorte d'ajoute le char a la static
/*
static t_struct ft_add_to_buffer(char c, t_struct datas)
{
	int j;
	
	j = 0;
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
}
*/
int ft_buffer(char c, t_struct datas)
{
	(void)datas;
	ft_putchar(c);	
    return (1);
}
