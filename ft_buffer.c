/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bod <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:48:59 by bod               #+#    #+#             */
/*   Updated: 2019/11/07 14:30:44 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int     ft_add_to_buffer(t_struct *datas)
{
	int len;
	static int i = 0;
	char *tmp;
	char *str;

	len = ft_strlen(datas->str);
	if (!(tmp = ft_substr(datas->str, i, len)))
		return (-1);
	if (!(str = ft_strcat(datas->buf, tmp)))
		return (-1);
	i = datas->start;
	ft_bzero(tmp, ft_strlen(tmp));
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
			printf("%s", datas->buf);
        i++;
    }
    return (1);
}
