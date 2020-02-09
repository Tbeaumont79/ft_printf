/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:15 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/09 17:49:27 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct	display(t_struct datas, char *string_value, int len)
{
	int j;

	j = 0;
	while (string_value[j] && len > 0)
		datas = ft_buffer(string_value[j++], datas);
	return (datas);
}

t_struct	handle(t_struct datas, int len, int prec_len, int val)
{
	if ((!datas.flag[flags] && datas.flag[size] > 0) ||
			(!datas.flag[flags] && datas.flag[size_prec] > 0))
		datas = fill_size(datas, len);
	if (datas.flag[flags] == '0')
	{
		datas.flag[size_prec] = datas.flag[size_prec] < 0 &&
			datas.flag[prec] == '.' && val == 0 && datas.flag[size] >= len ?
			datas.flag[size] : datas.flag[size_prec];
		datas.flag[size_prec] =
			datas.flag[size_prec] < 0 && datas.flag[prec] == '.' &&
			datas.flag[size] < len
			&& val > 0 ? -datas.flag[size_prec] : datas.flag[size_prec];
		datas.flag[size_prec] =
			datas.flag[size_prec] < 0 && datas.flag[prec] == '.' &&
			datas.flag[size] > len
			&& val > 0 ? datas.flag[size] - len : datas.flag[size_prec];
		datas = ft_left_justify(datas, len);
	}
	if (datas.flag[flags] == '-' && datas.flag[prec] == '.')
		datas = fill_right_justify_prec(datas, len, prec_len);
	return (datas);
}

t_struct	pf_x(va_list ap, t_struct datas, int i, const char *s)
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
	string_value = string_lower(ft_itoa_base(datas, val, 16));
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
