/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:15 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/15 11:06:37 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int pf_x(va_list ap, t_struct datas, int i, const char *s)
{
    int val;
    int j;
    char *stringValue;
	int prec_len;
    (void)s;

    j = 0;
    val = va_arg(ap, int);
    stringValue = ft_itoa_base(val, 16);
	prec_len = datas.flag[size_prec] - (int)ft_strlen(stringValue);
    string_lower(stringValue);
    while (stringValue[j])
        ft_buffer(stringValue[j++], datas);
    return (i);
}
