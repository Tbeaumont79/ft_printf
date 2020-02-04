/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:15 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/04 11:29:01 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct pf_x(va_list ap, t_struct datas, int i, const char *s)
{
    int val;
    int j;
    int prec_len;
    char *stringValue;
    int len;

    (void)s;
    j = 0;
    datas.flag[temp] = i;
    val = va_arg(ap, long long int);
    stringValue = ft_itoa_base(datas, val, 16);
    stringValue = string_lower(stringValue); 
    len = (val == 0 && (datas.flag[prec] == '.' &&
                datas.flag[size_prec] == 0) ? 0 : ft_strlen(stringValue));
    prec_len = datas.flag[size_prec] - len;
    if (val >= 0)
    {
        if ((!datas.flag[flags] && datas.flag[size] > 0) ||
                (!datas.flag[flags] && datas.flag[size_prec] > 0))
            datas = fill_size(datas, len);
        if (datas.flag[flags] == '0')
            datas = ft_left_justify(datas, len);
        if (datas.flag[flags] == '-' && datas.flag[prec] == '.')
            datas = fill_right_justify_prec(datas, len, prec_len);
        while (stringValue[j] && len > 0)
            datas = ft_buffer(stringValue[j++], datas);
        if (datas.flag[flags] == '-')
            datas = ft_right_justify(datas, len, prec_len);
        free(stringValue);
    }
	else
		datas = handle_neg(datas, val, 16, prec_len);
    return (datas);
}
