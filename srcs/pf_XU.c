/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_xu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:20 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/09 17:47:12 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

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
			datas.flag[prec] == '.' && datas.flag[size] <= 0 ?
			sizes : datas.flag[size_prec];
		datas.flag[size_prec] = datas.flag[size_prec] < 0 &&
			datas.flag[prec] == '.' && datas.flag[size] > sizes ?
			datas.flag[sizes] - sizes : datas.flag[size_prec];
		datas.flag[size_prec] = datas.flag[size_prec] < 0 &&
			datas.flag[prec] == '.' && datas.flag[size] < sizes ?
			sizes - datas.flag[size] : datas.flag[size_prec];
		datas = ft_left_justify(datas, sizes);
	}
	return (datas);
}

t_struct	pf_xu(va_list ap, t_struct datas, int i, const char *s)
{
	int		val;
	int		j;
	int		prec_len;
	char	*string_value;
	int		len;

	(void)s;
	j = 0;
	datas.flag[temp] = i;
	val = va_arg(ap, long long int);
	string_value = ft_itoa_base(datas, val, 16);
	len = (val == 0 && (datas.flag[prec] == '.' &&
				datas.flag[size_prec] == 0) ? 0 : ft_strlen(string_value));
	prec_len = datas.flag[size_prec] > len ? datas.flag[size_prec] - len : 0;
	if (val >= 0)
	{
		datas = handle(datas, len, prec_len, val);
		datas = display(datas, string_value, len);
		if (datas.flag[flags] == '-')
			datas = ft_right_justify(datas, len, prec_len);
	}
	else
		datas = handle_neg(datas, val, 16);
	free(string_value);
	return (datas);
}
