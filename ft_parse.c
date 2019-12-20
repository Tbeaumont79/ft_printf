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

int		ft_parse(va_list ap, t_struct datas, const char *s)
{
	size_t i;

	i = 0;
	if (!(datas.str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
		{
			ft_dispatcher(ap, datas, i);
			i = i + 1;
		}
		else
			datas.str[i] = s[i];
		i++;
	}
	if (s[i] == '\0')
	{
		ft_buffer(datas);
	}
	return (0);
}
