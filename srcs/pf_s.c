/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:02:15 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/09 18:03:16 by thbeaumo         ###   ########.fr       */
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
		if (j >= prec_len)
			break ;
		datas = ft_buffer(val[j], datas);
		j++;
	}
	return (datas);
}

static t_struct	handle_dot(t_struct datas, char *val, int len)
{
	int i;

	i = 0;
	if (datas.flag[prec] == '.')
	{
		if (datas.flag[flags] != '-')
		{
			while (datas.flag[size]-- > len)
				datas = ft_buffer(' ', datas);
		}
		while (val[i] && datas.flag[size_prec] > 0)
		{
			datas = ft_buffer(val[i], datas);
			i++;
			datas.flag[size_prec]--;
		}
	}
	else
	{
		if (datas.flag[prec] == '.' && datas.flag[size_prec] == 0)
			return (datas);
		else
			datas = ft_display_val(datas, val, len);
	}
	return (datas);
}

static t_struct	handle_flag(t_struct datas, char *val, int len)
{
	int tmp;

	tmp = 0;
	datas.flag[size_prec] = datas.flag[size_prec] > len ?
		datas.flag[size_prec] : len;
	if (datas.flag[flags] == '0')
		while (datas.flag[size]-- > len)
			datas = ft_buffer('0', datas);
	datas = handle_dot(datas, val, len);
	if (datas.flag[flags] == '-')
	{
		while (datas.flag[size]-- > len)
			datas = ft_buffer(' ', datas);
	}
	return (datas);
}

t_struct		pf_s(va_list ap, t_struct datas, int i, const char *s)
{
	char	*val;
	int		j;
	int		len;

	j = 0;
	(void)s;
	if ((val = va_arg(ap, char *)) == NULL)
		val = "(null)";
	datas.flag[temp] = i;
	len = (int)ft_strlen(val);
	if (datas.flag[size_prec] > 0)
		len = len > datas.flag[size_prec] ? datas.flag[size_prec] : len;
	len = datas.flag[prec] == '.' && datas.flag[size_prec] == 0 ? 0 : len;
	if (datas.flag[flags])
		datas = handle_flag(datas, val, len);
	else
	{
		if (datas.flag[prec] == '.' && datas.flag[size_prec] == 0)
			len = 0;
		while (datas.flag[size]-- > len)
			datas = ft_buffer(' ', datas);
		if (len != 0)
			datas = ft_display_val(datas, val, len);
	}
	return (datas);
}
