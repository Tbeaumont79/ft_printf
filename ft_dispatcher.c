/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:33:55 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/11/07 20:25:29 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_dispatcher(va_list ap, t_struct datas, int i, const char *s)
{
	static char conv[2]= {'s', 'd'};
	int j;
	int size;
	int (*fct[2])(va_list, t_struct, int i) = {pf_s, pf_d};

	j = 0;
	size = ft_strlen(conv);
	while (j < size)
	{
		if (s[i] == conv[j])
			break ;
		j++;
	}
	if (j >= 0 && j <= size)
		return (fct[j](ap, datas, i));
	return (-1);
}
