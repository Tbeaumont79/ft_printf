/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:12 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/15 12:22:56 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int pf_u(va_list ap, t_struct datas, int i, const char *s)
{
    unsigned long long int nb;
    char *stringValue;
    int j;
	int prec_len;
    (void)s;

    j = 0;
    nb = va_arg(ap, unsigned long long int);
	stringValue = ft_itoa_base(nb, 10);
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
