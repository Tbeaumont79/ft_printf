/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:33:55 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/23 14:05:16 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_dispatcher(va_list ap, t_struct *datas)
{
	static char *conv= "cs";
	int (*fct[2])(va_list, t_struct *) = {pf_c, pf_s};
	size_t i;

	while (datas->str[i])
	{
		if (datas->str[i] == conv[i])
			break;
		i++;
	}
	if (i >= 0 && i < 2)
		return (fct[i](ap, datas));
	return (-1);
}
