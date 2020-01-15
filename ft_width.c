/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:17:27 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/15 11:06:35 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

t_struct	ft_width(va_list ap, t_struct datas, const char *s, int i)
{
	int val;
	if (s[i] == '.' && s[i + 1] == '*')
	{
		val = va_arg(ap, int);
		datas.flag[size_prec] = val;
	}
	if (s[i - 1] == datas.flag[flags] && s[i] == '*')
	{
		val = va_arg(ap, int);
		datas.flag[size] = val;
	}
	return (datas);
}
