/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:05 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/05 14:35:10 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

int     nb_len_hexa(unsigned long int val, int base)
{
    int len;

    len = 0;
    while (val >= (unsigned int long)base)
    {
        len++;
        val /= base;
    }
    return (len + 1);
}

t_struct putnbr_base(unsigned long int val, char *tab, t_struct datas)
{
    if (val >= 16)
        datas = putnbr_base(val / 16, tab, datas);
    datas = ft_buffer(tab[val % 16], datas);
    return (datas);
}

t_struct handle_flag_p(unsigned long int val, t_struct datas, char *tab, int l)
{
    if (datas.flag[size_prec] != '.')
    {
        datas = ft_buffer('0', datas);
        datas = ft_buffer('x', datas);
    }
    if (datas.flag[flags] == '0')
    {
        while (datas.flag[size]-- > l)
            datas = ft_buffer('0', datas);
    }
    if (datas.flag[prec] == '.')
    {
        if (datas.flag[flags] != '-')
            while (datas.flag[size]-- > l)
                datas = ft_buffer(' ', datas);
        datas = ft_buffer('0', datas);
        datas = ft_buffer('x', datas);
        while (datas.flag[size_prec]-- > l)
            datas = ft_buffer('0', datas);
    }
    datas = (datas.flag[prec] == '.' && datas.flag[size_prec] <= 0 && val == 0) ?
        datas : putnbr_base(val, tab, datas);
    if (datas.flag[flags] == '-')
        while (datas.flag[size]-- > l)
            datas = ft_buffer(' ', datas);
    return (datas);
}

t_struct pf_p(va_list ap, t_struct datas, int i, const char *s)
{
	unsigned long int val;
    char tab[17];
	int len;
    int tmp;

	(void)s;
    tmp = datas.flag[size_prec];
	datas.flag[temp] = i;
    ft_strlcpy(tab, "0123456789abcdef", 17);
    val = va_arg(ap, unsigned long int);
    len = nb_len_hexa(val, 16);
    len = len > datas.flag[size_prec] ? len : datas.flag[size_prec];
    len = datas.flag[prec] == '.' && datas.flag[size_prec] == 0 && val == 0 ?
        0 : len;
    len += 2;
    if (datas.flag[flags])
        datas = handle_flag_p(val, datas, tab, len);
    else
    {
        len = nb_len_hexa(val, 16);
        len = datas.flag[prec] == '.' && datas.flag[size_prec] == 0 && val == 0 ?
            0 : len;
        datas.flag[size] -= datas.flag[size] >= 2 ? 2 : 0;
        while (datas.flag[size] > len)
        {
            datas = ft_buffer(' ', datas);
            datas.flag[size]--;
        }
        datas = ft_buffer('0', datas);
        datas = ft_buffer('x', datas);
        while ((tmp-- - len) > 0)
            datas = ft_buffer('0', datas);
        datas = (datas.flag[prec] == '.' && datas.flag[size_prec] <= 0 && val == 0) ?
            datas : putnbr_base(val, tab,  datas);
    }
    return (datas);
}
