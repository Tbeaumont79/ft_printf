/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:17:27 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/13 16:53:05 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

static	t_struct	handle_star(t_struct datas, int val, const char *s, int i)
{
	if (val > 0)
	{
		if (i > 0 && s[i - 1] == '.')
			datas.flag[size_prec] = val;
		else
			datas.flag[size] = val;
	}
	if (val < 0)
	{
		if (i > 0 && s[i - 1] == '.')
		{
			datas.flag[star] = 1;
			datas.flag[size_prec] = val;
			datas.flag[temp]++;
			return (datas);
		}
		datas.flag[size] = -val;
		datas.flag[flags] = '-';
	}
	if (datas.flag[size_prec] || datas.flag[size])
		datas.flag[temp]++;
	return (datas);
}

t_struct			ft_width(va_list ap, t_struct datas, const char *s, int i)
{
	int val;
	int tmp;

	val = 0;
	tmp = 0;
	if ((tmp = va_arg(ap, int)) == 0)
	{
		if (i > 0 && s[i - 1] == '.')
			datas.flag[size_prec] = 0;
		else
			datas.flag[size] = 0;
		datas.flag[temp]++;
		return (datas);
	}
	if (s[i] == '*')
	{
		val = tmp != 0 ? tmp : 0;
		datas = handle_star(datas, val, s, i);
	}
	return (datas);
}
