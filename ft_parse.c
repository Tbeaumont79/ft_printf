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

// Coder un fonction getFlag qui applique le traitement adequat !
int ft_get_flag(t_struct datas, const char *s)
{
	static char flag[4] = {'-', '0', '.', '*'};
	int j;
	int i;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (flag[i])
		{
			if (s[j] == flag[i])
				return (j);
			i++;
		}
		j++:
	}
	return (4);
}

// checker aussi la precision !

int ft_parse(va_list ap, t_struct datas, const char *s)
{
	int i;

	i = 0;
    ft_bzero(datas.buf, ft_strlen(s) + 1);
	while (s[i])
	{
		if (s[i] && s[i] != '%')
			ft_buffer(s[i], datas);
		if (s[i] == '%')
			i = ft_dispatcher(ap, datas, i, s) + 1;
		i++;
	}

	return (i);
}
