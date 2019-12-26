/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:33 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/11/08 14:08:37 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

// Coder un fonction getFlag qui applique le traitement adequat !

int ft_get_int(t_struct datas, const char *s, int i)
{
	int j;
	int nb;

	nb = 0;
	j = 0;
	if (ft_isdigit(s[i]))
	{
		nb = nb * 10 + ft_atoi(&s[i]);
		while (ft_isdigit(s[i]))
			i++;
	}
	datas.flag[size] = nb;
	return (++i);
}

int ft_get_flag(t_struct datas, const char *s, int i)
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
	//just check si l'element apres le flag correspond a un num dans c'est cas tu stock dans ta datas la taille (le result de ton atoi)
	// le point correspond a une precision faire un traitement apart !
	if (j == size_of_flag_array && s[i] == flag[j])
		datas.flag[j] = 1;
	else
		return (i);
	return (++i);
}

// checker aussi la precision !

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
			if (!(i = ft_get_flag(datas, s, i)))
				return (-1);
			if (!(i = ft_dispatcher(ap, datas, i - 2, s) + 1))
				return (-1);
		}
		i++;
	}

	return (i);
}
