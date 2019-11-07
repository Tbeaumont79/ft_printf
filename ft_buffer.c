/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bod <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:48:59 by bod               #+#    #+#             */
/*   Updated: 2019/11/07 16:01:26 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int     ft_add_to_buffer(t_struct *datas)
{
	int len;
	static int i = -1;
	char *tmp;
	char *str;

	len = ft_strlen(datas->str);
	//printf("I = %d\n", i);
	if (!(tmp = ft_substr(datas->str, i + 1, len)))
		return (-1);
	//printf("%s\n",tmp);
	//printf("LA SIZE : %lu\n", ft_strlen(datas->str));
	if (!(str = ft_strcat(datas->buf, tmp)))
		return (-1);
	i = datas->start + 1;
	ft_bzero(tmp, ft_strlen(tmp));
	return (1);	
}

void	ft_display_buf(t_struct *datas)
{
	int i;

	i = 0;
	while (datas->buf[i])
	{
		if (i == BUFF_SIZE || datas->buf[i] == '\n')
			ft_putstr(datas->buf);
		i++;
	}
}

int    ft_buffer(t_struct *datas)
{
    int i;

    i = 0;
    if (!(ft_add_to_buffer(datas)))
        return (-1);
    return (1);
}
