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
	static char *conv= "s";
	int j;
	int (*fct[1])(va_list, t_struct, int i) = {pf_s};

	j = 0;
	while (conv[j])
	{
		if (s[i] == conv[j])
			break ;
		j++;
	}
	if (i >= 0)
		return (fct[0](ap, datas, i));
	return (-1);
}
