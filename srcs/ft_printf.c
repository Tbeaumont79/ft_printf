/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:06:41 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/09 15:38:59 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	t_struct	datas;
	int			size_buf;

	datas.buf_index = 0;
	va_start(ap, s);
	ft_bzero(datas.buf, BUFF_SIZE);
	size_buf = ft_parse(ap, datas, s);
	va_end(ap);
	return (size_buf);
}
