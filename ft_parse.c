/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:33 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/11/08 14:08:37 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
// checker aussi la precision !

int ft_parse(va_list ap, t_struct datas, const char *s)
{
	int i;
	int val;

	i = 0;
	val = 0;
    ft_bzero(datas.buf, ft_strlen(s) + 1);
	while (s[i])
	{
		if (s[i] && s[i] != '%')
			ft_buffer(s[i], datas);
		if (s[i] == '%')
		{
			if (!(i = ft_get_flag(datas, s, i)))
				return (-1);
			if (!(i = ft_dispatcher(ap, datas, i - 1, s) + 1))
				return (-1);
		}
		i++;
	}
	return (i);
}
