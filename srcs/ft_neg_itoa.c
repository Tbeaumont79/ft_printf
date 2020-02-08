/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neg_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:07:02 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/08 17:00:41 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../Libft/libft.h"

t_struct	fill_size_neg(t_struct datas, int len_arg)
{
	int prec_len;

	datas.flag[size_prec] += datas.flag[neg] != 2;	
	prec_len = datas.flag[size_prec] > len_arg ?
	   	datas.flag[size_prec] : len_arg;
	while ((datas.flag[size]--) > prec_len)
		datas = ft_buffer(' ', datas);
	if (datas.flag[prec] == '.')
	{
		if (prec_len > 0)
		{
			datas = datas.flag[neg] == 0 && (datas.flag[conv] == 'd' ||
                    datas.flag[conv] == 'i') ? ft_buffer('-', datas) : datas;
			datas.flag[neg] = 1;
		}
		while (prec_len > len_arg)
		{
			datas = ft_buffer('0', datas);
			prec_len--;
		}
	}
	return (datas);
}

t_struct	fill_if_neg(t_struct datas, int sizes)
{
	if ((!datas.flag[flags] && datas.flag[size] > 0) ||
            (!datas.flag[flags] && datas.flag[size_prec] > 0))
        datas = fill_size_neg(datas, sizes);
    if (datas.flag[flags] == '0')
    {
        if (datas.flag[neg] == 0)
            datas.flag[neg] = 1;
		sizes -= datas.flag[neg] != 2;
			datas.flag[size_prec] = datas.flag[size_prec] < 0 &&
			   	datas.flag[prec] == '.' &&  datas.flag[size] <= 0 ?
				sizes : datas.flag[size_prec];
        datas = ft_left_justify(datas, sizes);
    }
    return (datas);
}

t_struct	display_neg_str(t_struct datas, char *neg_str, long long nb, int base)
{
    char	*tab;
    int		sizes;
    int		i;
	int		l;
    int		tmp;

    nb = base == 10 ?  ft_abs(nb) : nb;
    sizes = nb_len(nb, base);
    tab = "0123456789ABCDEF";
    neg_str[sizes] = '\0';
    i = 0;
    tmp = 0;
    while (sizes > 0)
    {
        sizes--;
		tmp++;
        neg_str[sizes] = tab[nb % base];
        nb = nb / base;
    }
	if (datas.flag[neg] == 0)
	{
		datas = ft_buffer('-', datas);
		datas.flag[neg] = 1;
	}
	sizes = datas.flag[size_prec];
	l = datas.flag[size_prec] > tmp ? datas.flag[size_prec] - tmp : tmp;
	if ((datas.flag[conv] == 'x' || datas.flag[conv] == 'X'))
		datas = fill_if_neg(datas, tmp);
    if (datas.flag[flags] == '-' && datas.flag[prec] == '.')
		datas = fill_right_justify_prec(datas, tmp, l);
    while (neg_str[i])
    {
        if (datas.flag[conv] == 'x' && neg_str[i] >= 'A' && neg_str[i] <= 'Z')
            datas = ft_buffer(neg_str[i] + 32, datas);
        else
            datas = ft_buffer(neg_str[i], datas);
        i++;
    }
    if (datas.flag[flags] == '-')
	{
		tmp = (datas.flag[conv] == 'd' || datas.flag[conv] == 'i') ? tmp + 1: tmp;
		tmp = sizes > tmp && datas.flag[prec] == '.' &&
		   	(datas.flag[conv] == 'x' || datas.flag[conv] == 'X') ?
		   	tmp + (sizes - tmp) : tmp;
		tmp = sizes > tmp && datas.flag[prec] == '.' &&
		   	(datas.flag[conv] == 'i' || datas.flag[conv] == 'd') ?
		   	tmp + (sizes - tmp + 1) : tmp;
		while (datas.flag[size]-- > tmp)
			datas = ft_buffer(' ', datas);
	}
    free(neg_str);
    return (datas);
}

t_struct	handle_neg(t_struct datas, long long nb, int base)
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
		if ((datas.flag[conv] == 'd' || datas.flag[conv] == 'i'))
			datas = fill_if_neg(datas, sizes);
        return (display_neg_str(datas, neg_str, nb, 10));
    }
	if (nb < 0 && base == 16)
	{
        nb = 4294967295 + nb + 1;
		datas.flag[neg] = 2;
		sizes = nb_len(nb, base);
		if (!(neg_str = (char *)malloc(sizeof(char) * (sizes + 1))))
			return (datas);
        return (display_neg_str(datas, neg_str, nb, 16));
	}
    return (datas);
}
