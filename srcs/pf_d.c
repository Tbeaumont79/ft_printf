/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:01 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/06 16:31:55 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct fill_right_justify_prec(t_struct datas, int len_arg, int prec_len)
{
    prec_len = datas.flag[size_prec] > len_arg ? datas.flag[size_prec] : len_arg;
    prec_len += datas.flag[neg] == 1 && prec_len > len_arg + 1;
    prec_len -= datas.flag[conv] == 'x' || datas.flag[conv] == 'X';
    if (datas.flag[prec] == '.' && prec_len > len_arg)
    {
        while (prec_len > len_arg)
        {
            datas = ft_buffer('0', datas);
            prec_len--;
        }
    }
    
    return (datas);
}

t_struct	fill_size(t_struct datas, int len_arg)
{
    int prec_len;

    prec_len = datas.flag[size_prec] > len_arg ? datas.flag[size_prec] : len_arg;
    prec_len -= datas.flag[neg] == 1;
    while ((datas.flag[size]--) > prec_len)
        datas = ft_buffer(' ', datas);
    if (datas.flag[prec] == '.')
    {
        while (prec_len > len_arg)
        {
            datas = ft_buffer('0', datas);
            prec_len--;
        }
    }
    return (datas);
}

t_struct pf_d(va_list ap, t_struct datas, int i, const char *s)
{
    int val;
    int j;
    char *stringValue;
    int len;
    int prec_len;

    (void)s;
    j = 0;
    datas.flag[temp] = i;
    val = va_arg(ap, int);
    stringValue = ft_itoa_base(datas, val, 10);
    len = ft_strlen(stringValue);
    len = ((val == 0 && (datas.flag[prec] == '.' &&
                    datas.flag[size_prec] == 0)) ? 0 : ft_strlen(stringValue));
    prec_len = 0;
    if (val >= 0)
    {
        if ((!datas.flag[flags] && datas.flag[size] > 0) ||
                (!datas.flag[flags] && datas.flag[size_prec] > 0))
            datas = fill_size(datas, len);
        if (datas.flag[flags] == '0')
            datas = ft_left_justify(datas, (int)ft_strlen(stringValue));
        if (datas.flag[prec] == '.' && datas.flag[flags] != '0' && datas.flag[flags])
            datas = fill_right_justify_prec(datas, (int)ft_strlen(stringValue), len);
        while (stringValue[j] && !(val == 0 && datas.flag[prec] == '.' && datas.flag[size_prec] == 0))
            datas = ft_buffer(stringValue[j++], datas);
        len = len > datas.flag[size_prec] ? len : datas.flag[size_prec];
        if (datas.flag[flags] == '-')
            while (datas.flag[size]-- > len)
                datas = ft_buffer(' ', datas);
        free(stringValue);
    }
    else
        datas = handle_neg(datas, val, 10, len);
    return (datas);
}
