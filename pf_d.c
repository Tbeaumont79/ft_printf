/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:01 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/13 13:36:31 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int pf_d(va_list ap, t_struct datas, int i, const char *s)
{
    int val;
    int j;
    char *stringValue;

    (void)s;
    j = 0;
    val = va_arg(ap, int);
    stringValue = ft_itoa_base(val, 10);
    if (datas.flag[flags] == '0' && datas.flag[size] > 0)
        ft_left_justify(datas, ft_strlen(stringValue));
    while (stringValue[j])
        ft_buffer(stringValue[j++], datas);
	if (datas.flag[flags] == '-')
		ft_right_justify(datas, ft_strlen(stringValue));
    return (i);
}
