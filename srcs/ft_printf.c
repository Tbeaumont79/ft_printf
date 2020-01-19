/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:06:41 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/19 11:20:42 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

int		ft_printf(const char *s, ...)
{
	va_list ap;
	va_start(ap, s);
	t_struct datas;
	int size_buf;
	
	
    ft_bzero(datas.buf, 1);
	size_buf = ft_parse(ap, datas, s);
	va_end(ap);
	return (size_buf);
}

