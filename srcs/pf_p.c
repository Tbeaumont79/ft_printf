/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:05 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/20 07:41:34 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct pf_p(va_list ap, t_struct datas, int i, const char *s)
{
    long long val;
    int j;
    char *stringValue;
    (void)s;

    j = 0;
	datas.flag[temp] = i;
    val = va_arg(ap, long long);
    if (!(stringValue = ft_itoa_base(datas,val, 16)))
        return (datas);
    stringValue = string_lower(stringValue);
	if ((!datas.flag[flags] && (!datas.flag[prec] || datas.flag[size_prec] == 0)
	 && datas.flag[size] > 0))
	 datas = fill_size(datas, (int)ft_strlen(stringValue));
    datas = ft_buffer('0', datas);
    datas = ft_buffer('x', datas);
    while (stringValue[j])
        datas = ft_buffer(stringValue[j++], datas);
    return (datas); 
}
