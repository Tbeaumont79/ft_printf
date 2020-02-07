/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:02:15 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/06 16:28:35 by thbeaumo         ###   ########.fr       */
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

t_struct	handle_flag(t_struct datas, char *val, int len)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	datas.flag[size_prec] = datas.flag[size_prec] > len ? datas.flag[size_prec] : len;
	if (datas.flag[flags] == '0')
	{
		while (datas.flag[size]-- > len)
			datas = ft_buffer('0', datas);
	}
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
	if (datas.flag[flags] == '-')
	{
		while (datas.flag[size]-- > len)
			datas = ft_buffer(' ', datas);
	}
	return (datas);
}

char	*handle_null(char *val)
{
	char *tmp;

	if (!(tmp = ft_strdup("(null)")))
		return (0);
	val = tmp;
	free(tmp);
	return (val);
}

t_struct pf_s(va_list ap, t_struct datas, int i, const char *s)
{
	char *val;
	int j;
	int len;
	(void)s;

	j = 0;
	if ((val = va_arg(ap, char *)) == NULL)
		val = handle_null(val);
	datas.flag[temp] = i;
	len = (int)ft_strlen(val);
	if (datas.flag[size_prec] > 0)
		len = len > datas.flag[size_prec] ? datas.flag[size_prec] : len;
	if (datas.flag[prec] == '.' && (datas.flag[size_prec] == 0))
		len = 0;
	if (datas.flag[flags])
		datas = handle_flag(datas, val, len);
	else
	{
		if (datas.flag[prec] == '.' && datas.flag[size_prec] == 0)
			len = 0;	
		while (datas.flag[size]-- > len)
			datas = ft_buffer(' ', datas);
		if (len == 0)
			return (datas);
		else
			datas = ft_display_val(datas, val, len);
	}
	return (datas);
}
