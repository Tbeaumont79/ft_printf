/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:12 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/09 17:53:27 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct	handle_flag(t_struct datas, int prec_l, int l, unsigned long long v)
{
	if (datas.flag[flags] == '0')
	{
		datas.flag[size_prec] = datas.flag[size_prec] < 0 &&
			datas.flag[prec] == '.' && v == 0 && datas.flag[size] >= l ?
			datas.flag[size] : datas.flag[size_prec];
		datas.flag[size_prec] =
			datas.flag[size_prec] < 0 && datas.flag[prec] == '.' &&
			datas.flag[size] < l
			&& v > 0 ? -datas.flag[size_prec] : datas.flag[size_prec];
		datas.flag[size_prec] =
			datas.flag[size_prec] < 0 && datas.flag[prec] == '.' &&
			datas.flag[size] > l
			&& v > 0 ? datas.flag[size] - l : datas.flag[size_prec];
		datas = ft_left_justify(datas, l);
	}
	if (datas.flag[flags] == '-' && datas.flag[prec] == '.')
		datas = fill_right_justify_prec(datas, l, prec_l);
	if ((!datas.flag[flags] && datas.flag[size] > 0) ||
			(!datas.flag[flags] && datas.flag[size_prec] > 0))
		datas = fill_size(datas, l);
	return (datas);
}

t_struct	pf_u(va_list ap, t_struct datas, int i, const char *s)
{
	unsigned long long int	val;
	char					*string_value;
	int						j;
	int						prec_len;
	int						len;

	(void)s;
	j = 0;
	datas.flag[temp] = i;
	val = 0;
	val = va_arg(ap, unsigned long long int);
	string_value = ft_itoa_base(datas, (unsigned long long)val, 10);
	len = (val == 0 && (datas.flag[prec] == '.' &&
				datas.flag[size_prec] == 0) ? 0 : ft_strlen(string_value));
	prec_len = datas.flag[size_prec] > len ? datas.flag[size_prec] - len : 0;
	if (val >= 0)
	{
		datas = handle_flag(datas, prec_len, len, val);
		while (string_value[j] && len > 0)
			datas = ft_buffer(string_value[j++], datas);
		if (datas.flag[flags] == '-')
			datas = ft_right_justify(datas, len, prec_len);
	}
	free(string_value);
	return (datas);
}
