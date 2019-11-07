/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:33:55 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/11/07 14:31:54 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_dispatcher(va_list ap, t_struct *datas)
{
	static char *conv= "s";
	int j;
	int (*fct[1])(va_list, t_struct *) = {pf_s};

	j = 0;
	while (conv[j])
	{
		if (datas->str[datas->start] == conv[j])
			break ;
		j++;
	}
	if (datas->start >= 0)
		return (fct[0](ap, datas));
	return (-1);
}
