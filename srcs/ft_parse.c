/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:33 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/13 17:18:32 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct	is_conv(t_struct datas, int i, const char *s)
{
	static char conve[8] = {'x', 'X', 'd', 'i', 'c', 's', '%', 'u'};
	int			j;
	int			len;

	len = ft_strlen(conve);
	while (s[i])
	{
		j = 0;
		while (j < len)
		{
			if (conve[j] == s[i])
			{
				datas.flag[conv] = conve[j];
				break ;
			}
			j++;
		}
		i++;
	}
	return (datas);
}

int			ft_parse(va_list ap, t_struct datas, const char *s)
{
	int i;
	int val;
	int j;
	int tmp;

	j = 0;
	i = 0;
	val = 0;
	while (s[i])
	{
		if (s[i] && s[i] != '%')
			datas = ft_buffer(s[i], datas);
		if (s[i] == '%')
		{
			tmp = i + 1;
			datas = is_conv(datas, tmp, s);
			datas.flag[temp] = i;
			datas.flag[star] = 0;
			datas = get_flag(ap, datas, s, i);
			i = s[datas.flag[temp]] ? datas.flag[temp] : i;
			datas = ft_disp(ap, datas, i, s);
		}
		i++;
	}
	return (datas.buf_index);
}
