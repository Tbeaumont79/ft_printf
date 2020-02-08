/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_XU.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:20 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/08 17:32:21 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct pf_XU(va_list ap, t_struct datas, int i, const char *s)
{
    int		val;
    int		j;
    int		prec_len;
    char	*stringValue;
    int		len;

    (void)s;
    j = 0;
    datas.flag[temp] = i;
    val = va_arg(ap, long long int);
    stringValue = ft_itoa_base(datas, val, 16);
    len = (val == 0 && (datas.flag[prec] == '.' &&
                datas.flag[size_prec] == 0) ? 0 : ft_strlen(stringValue));
    prec_len = datas.flag[size_prec] > len ? datas.flag[size_prec] - len : 0;
    if (val >= 0)
    {
        if ((!datas.flag[flags] && datas.flag[size] > 0) ||
                (!datas.flag[flags] && datas.flag[size_prec] > 0))
            datas = fill_size(datas, len);
        if (datas.flag[flags] == '0')
		{
			datas.flag[size_prec] = datas.flag[size_prec] < 0 &&
			   	datas.flag[prec] == '.' && val == 0 && datas.flag[size] <= 0 ?
			   	len : datas.flag[size_prec];
			datas.flag[size_prec] = datas.flag[size_prec] < 0 &&
			   	datas.flag[prec] == '.' && val == 0 && datas.flag[size] >= len ?
			   	datas.flag[size] : datas.flag[size_prec];
			datas.flag[size_prec] =
			  	datas.flag[size_prec] < 0 && datas.flag[prec] == '.' &&
			 datas.flag[size] > (len + (-datas.flag[size_prec])) &&
			 val > 0 ? datas.flag[size] - len : datas.flag[size_prec];
            datas = ft_left_justify(datas, len);
		}
        if (datas.flag[flags] == '-' && datas.flag[prec] == '.')
            datas = fill_right_justify_prec(datas, len, prec_len);
        while (stringValue[j] && len > 0)
            datas = ft_buffer(stringValue[j++], datas);
        if (datas.flag[flags] == '-')
            datas = ft_right_justify(datas, len, prec_len);
        free(stringValue);
    }
	else
		datas = handle_neg(datas, val, 16);
	return (datas);
}
