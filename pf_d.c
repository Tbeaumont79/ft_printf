/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:01 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/03 09:54:36 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int pf_d(va_list ap, t_struct datas, int i, const char *s)
{
    int val;
    int j;
    int tmp;
    char *stringValue;

    tmp = i + 1;
    j = 0;
    val = va_arg(ap, int);
    stringValue = ft_itoa_base(val, 10);
    datas = get_flag(datas, tmp, s);
    if (datas.flag[flags] == '0' || datas.flag[size] > 0)
        ft_left_justify(datas, ft_strlen(stringValue));
    while (stringValue[j])
        ft_buffer(stringValue[j++], datas);
    return (i);
}
