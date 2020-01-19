/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:33:55 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/16 14:02:55 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"


int		ft_dispatcher(va_list ap, t_struct datas, int i, const char *s)
{
	static char conv[8]= {'s', 'd', 'i', 'x', 'X', 'p', 'c', 'u'};
	int j;
	int size;
	int (*fct[8])(va_list, t_struct, int i, const char *s) = {pf_s, pf_d, pf_d, pf_x, pf_XU, pf_p, pf_c, pf_u};

	j = 0;
	size = ft_strlen(conv);
	while (j < size)
	{
		if (conv[j] == s[i])
			break ;
		j++;
	}
	if (j >= 0 && j < size)
		return (fct[j](ap, datas, i, s));
	return (-1);
}