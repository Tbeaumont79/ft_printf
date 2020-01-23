/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neg_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:07:02 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/23 14:27:59 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../Libft/libft.h"

t_struct	fill_size_neg(t_struct datas, int len_arg)
{
	int prec_len;

	prec_len = (datas.flag[size_prec] > len_arg ?
			datas.flag[size_prec] - len_arg : 0);
	while (datas.flag[size] - len_arg - 1 > prec_len)
	{
		datas = ft_buffer(' ', datas);
		datas.flag[size]--;
	}
	if (prec_len > 0)
	{
		datas = ft_buffer('-', datas);
		datas.flag[neg] = 1;
	}
	while (prec_len > 0)
	{
		datas = ft_buffer('0', datas);
		prec_len--;
	}
	return (datas);
}

t_struct	fill_if_neg(t_struct datas, int sizes)
{
    int prec_len;

    prec_len = datas.flag[size_prec] > sizes ?
        datas.flag[size_prec] - sizes : 0;
    if ((!datas.flag[flags] && datas.flag[size] > 0) ||
            (!datas.flag[flags] && datas.flag[size_prec] > 0))
    {
        sizes--;
        datas = fill_size_neg(datas, sizes);
    }
    if (datas.flag[flags] == '0')
        datas = ft_left_justify(datas, sizes);
    return (datas);
}

t_struct	display_neg_str(t_struct datas, char *neg_str, long long nb, int l)
{
    char *tab;
    int sizes;
    int base;
    int i;
    int tmp;

    base = 10;
    sizes = nb_len(nb, base);
    tab = "0123456789ABCDEF";
    neg_str[sizes] = '\0';
    i = 0;
    tmp = sizes;
    while (sizes > 0)
    {
        sizes--;
        neg_str[sizes] = tab[nb % base];
        nb = nb / base;
    }
	if (datas.flag[neg] != 1)
	{
		datas = ft_buffer('-', datas);
		datas.flag[neg] = 1;
	}
    if (datas.flag[flags] == '-' && datas.flag[prec] == '.')
	{
		tmp += datas.flag[size] > datas.flag[size_prec] ? 1 : 0;
        datas = fill_right_justify_prec(datas, tmp, l);
	}
    while (neg_str[i])
    {
        datas = ft_buffer(neg_str[i], datas);
        i++;
    }
    if (datas.flag[flags] == '-')
        datas = ft_right_justify(datas, tmp + 1, l);
    free(neg_str);
    return (datas);
}

t_struct	handle_neg(t_struct datas, long long nb, int base, int prec_len)
{
    int lim;
    int sizes;
    char *neg_str;

    lim = 0;
    sizes = nb_len(nb, base);
	datas.flag[neg] = 0;
    if (nb < 0 && base == 10)
    {
        if (!(neg_str = (char *)malloc(sizeof(char) * (sizes + 1))))
            return (datas);
        datas = fill_if_neg(datas, sizes);
        nb = ft_abs(nb);
		prec_len = datas.flag[size_prec] > sizes ? datas.flag[size_prec] - sizes : 0; 
        return (display_neg_str(datas, neg_str, nb, prec_len));
    }
    return (datas);
}
