/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:02:15 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/30 11:40:06 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

static t_struct	ft_display_val(t_struct datas, char *val, int prec_len)
{
	int j;

	j = 0;
	while (val[j])
	{
		if (j < prec_len)
			datas = ft_buffer(val[j], datas);
		if (j >= prec_len || (datas.flag[prec] == '.' && datas.flag[size_prec] == 0))
			break ;
		j++;
	}
	return (datas);
}

t_struct	fill_size_s(t_struct datas, int len_arg)
{
	int value;
	//si il y a une prec prendre la diff entre size et size_prec et mettre des spaces while > 0 

	value = (datas.flag[size_prec] && datas.flag[size] < len_arg ?
			datas.flag[size] - datas.flag[size_prec] :
			datas.flag[size] - len_arg);
	while (value > 0)
	{
		datas = ft_buffer(' ', datas);
		value--;
	}
	return (datas);
}

t_struct pf_s(va_list ap, t_struct datas, int i, const char *s)
{
	char *val;
	int j;
	int len;
	int prec_len;
	(void)s;

	j = 0;
	val = va_arg(ap, char *);
	datas.flag[temp] = i;
	len = (int)ft_strlen(val);
	prec_len = (datas.flag[size_prec] > 0 ?
			datas.flag[size_prec] : len);
	prec_len = (datas.flag[prec] == '.' && datas.flag[size_prec] == 0 &&
			datas.flag[size] == 0) ? 0 : prec_len;
	if (!datas.flag[flags] && datas.flag[size] > 0)
		datas = fill_size_s(datas, len);
	if(val == NULL)
	{
		val = "(null)";
		printf("%s\n", val);
		datas = ft_display_val(datas, val, prec_len);
	}
	else
	{
		if (datas.flag[flags] == '0')
			datas = ft_left_justify(datas, len);
		else
			datas = ft_display_val(datas, val, prec_len);
	}
	if (datas.flag[flags] == '-')
		datas = ft_right_justify(datas, len, 0);
	return (datas);
}
