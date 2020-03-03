/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:01 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/13 17:14:40 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct	fill_right_justify_prec(t_struct datas, int len_arg, int p)
{
	p = datas.flag[size_prec] > len_arg ?
		datas.flag[size_prec] : len_arg;
	if (datas.flag[prec] == '.' && p > len_arg)
	{
		while (p > len_arg)
		{
			datas = ft_buffer('0', datas);
			p--;
		}
	}
	return (datas);
}

t_struct	fill_size(t_struct datas, int len_arg)
{
	int prec_len;

	prec_len = datas.flag[size_prec] > len_arg ?
		datas.flag[size_prec] : len_arg;
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

t_struct	handleflag(t_struct datas, int len, int prec_len, int val)
{
	if ((!datas.flag[flags] && datas.flag[size] > 0) ||
			(!datas.flag[flags] && datas.flag[size_prec] > 0))
		datas = fill_size(datas, len);
	if (datas.flag[flags] == '0')
	{
		(void)val;
		datas.flag[size_prec] = datas.flag[size_prec] < 0 ?
		0 : datas.flag[size_prec];
		datas = ft_left_justify(datas, len);
	}
	if (datas.flag[prec] == '.' && datas.flag[flags] != '0' &&
			datas.flag[flags])
		datas = fill_right_justify_prec(datas, len, prec_len);
	return (datas);
}

t_struct	handlepositif(t_struct datas, char *s, int len, int val)
{
	int	prec_len;
	int	j;

	j = 0;
	prec_len = datas.flag[size_prec] > len ? datas.flag[size_prec] - len : 0;
	datas = handleflag(datas, len, prec_len, val);
	while (s[j] && !(val == 0 && datas.flag[prec] == '.' &&
				len == 0))
		datas = ft_buffer(s[j++], datas);
	len = len > datas.flag[size_prec] ? len : datas.flag[size_prec];
	if (datas.flag[flags] == '-')
		while (datas.flag[size]-- > len)
			datas = ft_buffer(' ', datas);
	return (datas);
}

t_struct	pf_d(va_list ap, t_struct datas, int i, const char *s)
{
	char	*string_value;
	int		val;
	int		j;
	int		len;

	(void)s;
	j = 0;
	datas.flag[temp] = i;
	val = va_arg(ap, int);
	if (val < 0)
		datas = handle_neg(datas, val, 10);
	if (val >= 0)
	{
		string_value = ft_itoa_base(datas, val, 10);
		len = (val == 0 && (datas.flag[prec] == '.' &&
					datas.flag[size_prec] == 0)) ? 0 : ft_strlen(string_value);
		datas = handlepositif(datas, string_value, len, val);
		free(string_value);
	}
	return (datas);
}
