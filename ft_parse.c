/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:33 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/03 09:54:12 by thbeaumo         ###   ########.fr       */
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
	return (i);
}

static int ft_get_flag(t_struct datas, const char *s, int i)
{
	static char flag[4] = {'-', '0', '.', '*'};
	int j;
	int size_of_flag_array;

	j = 0;
	size_of_flag_array = ft_strlen(flag);
	while (j < size_of_flag_array && s[i] != flag[j])
		j++;
	if (j == size_of_flag_array && ft_isdigit(s[i + 1]))
		return (ft_get_int(datas, s, i + 2));
	// le point correspond a une precision faire un traitement apart !
	if (j == size_of_flag_array && s[i] == flag[j])
		datas.flag[flags] = flag[j];
	else
		return (i + 1); 
	return (++i);
}

int ft_parse(va_list ap, t_struct datas, const char *s)
{
	int i;
	int val;

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
