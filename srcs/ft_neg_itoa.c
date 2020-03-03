/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neg_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:07:02 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/13 14:20:49 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../Libft/libft.h"
#include <stdio.h>

t_struct	handle_right_justify(t_struct datas, int tmp, int sizes)
{
	if (datas.flag[flags] == '-')
	{
		tmp = (datas.flag[conv] == 'd' || datas.flag[conv] == 'i') ?
			tmp + 1 : tmp;
		tmp = sizes > tmp && datas.flag[prec] == '.' &&
			(datas.flag[conv] == 'x' || datas.flag[conv] == 'X') ?
			tmp + (sizes - tmp) : tmp;
		tmp = sizes >= tmp && datas.flag[prec] == '.' &&
			(datas.flag[conv] == 'i' || datas.flag[conv] == 'd') ?
			tmp + (sizes - tmp + 1) : tmp;
		while (datas.flag[size]-- > tmp)
			datas = ft_buffer(' ', datas);
	}
	return (datas);
}

t_struct	h_neg_itoa(t_struct datas, char *s, int tmp, int l)
{
	int i;
	int sizes;

	i = 0;
	sizes = datas.flag[size_prec];
	if (datas.flag[neg] == 0)
	{
		datas = ft_buffer('-', datas);
		datas.flag[neg] = 1;
	}
	if ((datas.flag[conv] == 'x' || datas.flag[conv] == 'X'))
		datas = fill_if_neg(datas, tmp);
	if (datas.flag[flags] == '-' && datas.flag[prec] == '.')
		datas = fill_right_justify_prec(datas, tmp, l);
	while (s[i])
	{
		datas = datas.flag[conv] == 'x' && ft_maj_alpha(s[i]) ?
			ft_buffer(s[i] + 32, datas) : ft_buffer(s[i], datas);
		i++;
	}
	datas = handle_right_justify(datas, tmp, sizes);
	return (datas);
}

t_struct	display_neg_str(t_struct datas, char *neg_str, long nb, int b)
{
	char	*tab;
	int		sizes;
	int		i;
	int		l;
	int		tmp;

	nb = b == 10 ? ft_abs(nb) : nb;
	sizes = nb_len(nb, b);
	tab = "0123456789ABCDEF";
	neg_str[sizes] = '\0';
	i = 0;
	tmp = 0;
	while (sizes > 0)
	{
		sizes--;
		tmp++;
		neg_str[sizes] = tab[nb % b];
		nb = nb / b;
	}
	sizes = datas.flag[size_prec];
	l = datas.flag[size_prec] > tmp ? datas.flag[size_prec] - tmp : tmp;
	datas = h_neg_itoa(datas, neg_str, tmp, l);
	free(neg_str);
	return (datas);
}

t_struct	handle_neg(t_struct datas, long nb, int base)
{
	int		lim;
	int		sizes;
	char	*neg_str;

	lim = 0;
	datas.flag[neg] = 0;
	if (nb < 0 && base == 10)
	{
		sizes = nb_len(nb, base);
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
