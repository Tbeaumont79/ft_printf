/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:33 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/04 12:01:23 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
// checker aussi la precision !

static int ft_get_int(t_struct datas, const char *s, int i)
{
	int nb;
	(void)datas;

	nb = 0;
	if (ft_isdigit(s[i]))
	{
		nb = nb * 10 + ft_atoi(&s[i]);
		while (ft_isdigit(s[i]))
			i++;
	}
	if (s[i] == '.')
	{
		i++;
		while (ft_isdigit(s[i]))
			i++;
	}
	return (i);
}
/**
static int ft_get_prec(t_struct datas, const char *s, int i, int size_of_flag)
{
	// the main idea is to skip the prec 
}
**/
static int ft_get_flag(t_struct datas, const char *s, int i)
{
	static char flag[4] = {'-', '0', '.', '*'};
	int j;
	int tmp;
	int size_of_flag_array;

	j = 0;
	tmp = 0;
	size_of_flag_array = ft_strlen(flag);
	while (s[tmp] && s[tmp] != '.')
		tmp++;
	while (j < size_of_flag_array && s[i + 1] != flag[j])
		j++;
	if (s[i + 1] == flag[j] && ft_isdigit(s[i + 2]))
		return (ft_get_int(datas, s, i + 2));
	// le point correspond a une precision faire un traitement apart !
	if (s[i + 1] == flag[j])
	{
		datas.flag[flags] = flag[j];
		i++;
	}
	else
		return (-1);
	return (++i);
}



int ft_parse(va_list ap, t_struct datas, const char *s)
{
	int i;
	int val;
	int j;

	j = 0;
	i = 0;
	val = 0;
	ft_bzero(datas.buf, ft_strlen(s) + 1);
	while (s[i])
	{
		if (s[i] && s[i] != '%')
			ft_buffer(s[i], datas);
		if (s[i] == '%')
		{
			// si ca return -1 tu peux call le dispatcher avec la bonne index !
			if (!(i = ft_get_flag(datas, s, i)))
				return (-1);
			if (!(i = ft_dispatcher(ap, datas, i - 1, s) + 1))
				return (-1);
		}
		i++;
	}
	return (i);
}
