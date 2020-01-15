/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_XU.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:20 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/15 12:18:06 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int pf_XU(va_list ap, t_struct datas, int i, const char *s)
{
    int val;
    int j;
	int prec_len;
    char *stringValue;
    (void)s;

    j = 0;
    val = va_arg(ap, int);
    stringValue = ft_itoa_base(val, 16);
	prec_len = datas.flag[size_prec] - (int)ft_strlen(stringValue);
    if (datas.flag[flags] == '0' && datas.flag[size] > 0)
        ft_left_justify(datas, ft_strlen(stringValue));
    if (datas.flag[flags] == '-' && datas.flag[prec] == '.')
        fill_right_justify_prec(datas, ft_strlen(stringValue), prec_len);
    while (stringValue[j])
        ft_buffer(stringValue[j++], datas);
    if (datas.flag[flags] == '-')
        ft_right_justify(datas, ft_strlen(stringValue), prec_len);
	return (i);
}
