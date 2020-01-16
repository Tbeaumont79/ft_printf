/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:17:27 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/16 15:38:42 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"


t_struct	ft_width(va_list ap, t_struct datas, const char *s, int i)
{
	int val;
	if (s[i] == '*')
	{
		val = va_arg(ap, int);
		if (i > 0 && s[i - 1] == '.')
			datas.flag[size_prec] = val;
		else
			datas.flag[size] = val;
	}
	if (datas.flag[size_prec] || datas.flag[size])
		datas.flag[temp]++;
	return (datas);
}
