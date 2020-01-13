/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:01 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/13 15:30:44 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int pf_d(va_list ap, t_struct datas, int i, const char *s)
{
    int val;
    int j;
    int prec_len;
    char *stringValue;
    int boolean;

    // need to check if it WORK 
    (void)s;
    j = 0;
    boolean = 0;
    val = va_arg(ap, int);
    stringValue = ft_itoa_base(val, 10);
	prec_len = datas.flag[size_prec] > (int)ft_strlen(stringValue) ? datas.flag[size_prec] - (int)ft_strlen(stringValue) : 0;
    if (datas.flag[flags] == '0' && datas.flag[size] > 0)
        ft_left_justify(datas, ft_strlen(stringValue));
    if (datas.flag[flags] == '-' && datas.flag[prec] == '.' && datas.flag[size_prec] > 0)
    {
        fill_if_prec(datas, ft_strlen(stringValue), prec_len);
        boolean = 1;
    }
    while (stringValue[j])
        ft_buffer(stringValue[j++], datas); 
	if (datas.flag[flags] == '-' && boolean == 0)
        ft_right_justify(datas, ft_strlen(stringValue));
    return (i);
}
