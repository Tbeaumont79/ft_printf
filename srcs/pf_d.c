/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:01 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/16 15:15:48 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

void fill_right_justify_prec(t_struct datas, int len_arg, int prec_len)
{
	(void)len_arg;
	while (prec_len > 0)
	{
		ft_buffer('0', datas);
		prec_len--;
	}
}

int pf_d(va_list ap, t_struct datas, int i, const char *s)
{
    int val;
    int j;
    int prec_len;
    char *stringValue;

    // need to check if it WORK 
    (void)s;
    j = 0;
    val = va_arg(ap, int);
    stringValue = ft_itoa_base(val, 10);
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
