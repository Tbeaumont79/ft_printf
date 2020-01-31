/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:05 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/31 09:41:30 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct pf_p(va_list ap, t_struct datas, int i, const char *s)
{
	int val;
	int j;
	int prec_len;
	char *stringValue;
	int len;

	(void)s;
	j = 0;
	datas.flag[temp] = i;
	val = va_arg(ap, long long);
	stringValue = ft_itoa_base(datas, val, 16);
	stringValue = string_lower(stringValue);
	len = (val == 0 && (datas.flag[prec] == '.' &&
				datas.flag[size_prec] == 0) ? 0 : ft_strlen(stringValue));
	prec_len = datas.flag[size_prec] - len;
	if (val >= 0)
	{
		datas.flag[size] -= datas.flag[size] ? 2 : 0;
		if (datas.flag[flags] == '0')
		{
			datas = ft_buffer('0', datas);
			datas = ft_buffer('x', datas);	
			datas = ft_left_justify(datas, len);
		}
		else
		{
			if (datas.flag[size_prec] && datas.flag[size] == 0)
			{
				datas = ft_buffer('0', datas);
				datas = ft_buffer('x', datas);
			}
			datas = fill_size(datas, len);
			if (!datas.flag[size_prec])
			{
				datas = ft_buffer('0', datas);
				datas = ft_buffer('x', datas);
			}
		}
		while (stringValue[j] && len > 0)
			datas = ft_buffer(stringValue[j++], datas);
		free(stringValue);
	}
	return (datas);
}
