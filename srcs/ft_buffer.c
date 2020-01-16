/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:17:48 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/16 16:06:40 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

// voire pour declare une statique et faire en sorte d'ajoute le char a la static
static char *ft_add_to_buffer(char c, t_struct datas)
{
	char *tmp;

	if (!(datas.str = (char *)malloc(sizeof(char) + (int)ft_strlen(datas.buf))))
		return (0);
	while (*datas.str)
	{
		*datas.str = c;
		datas.str++;
		break ;
	}
	if (!(tmp = ft_strjoin(datas.buf, datas.str)))
		return (0);
	datas.str = tmp;
	free(tmp);
    return (datas.str);
}

void ft_display_buf(char *buf)
{
    int i;
    int printable;

    i = 0;
    printable = 0;
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
    if (!(datas.str = ft_add_to_buffer(c, datas)))
		return (-1);
    ft_display_buf(datas.str);
    return (1);
}
