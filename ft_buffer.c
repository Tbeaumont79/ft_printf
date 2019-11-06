/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bod <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:48:59 by bod               #+#    #+#             */
/*   Updated: 2019/11/06 15:57:34 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_start_to_end_len(t_struct *datas)
{
	int i;

	i = 0;
	while (datas->str[i])
		i++;
	i = i - datas->start;
	//printf("La size est de ! : %d \n", i);
	return (i);
}

int     ft_add_to_buffer(t_struct *datas)
{
	char *tmp;
	int len;
	
	len = ft_strlen(datas->str);
	if (!(tmp = ft_strcat(datas->buf, datas->str)))
		return (-1);
	ft_memcpy(datas->buf, tmp, len);
	return (1);	
}

int    ft_buffer(t_struct *datas)
{
    int i;

    i = 0;
    if (!(ft_add_to_buffer(datas)))
        return (-1);
    while (datas->buf[i])
    {
        if (datas->buf[i] == '\n')
            ft_putstr(datas->buf);
        i++;
    }
	printf("datas->buf : %s\n", datas->buf);
    return (1);
}
