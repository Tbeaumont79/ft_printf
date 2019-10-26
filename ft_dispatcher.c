/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:33:55 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/26 17:42:18 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_dispatcher(va_list ap, t_struct *datas, size_t count)
{
	static char *conv= "s";
	int (*fct[1])(va_list, t_struct *) = {pf_s};
	size_t i;

	i = 0;
	while (datas->buf[i])
	{
		if (datas->buf[i] == conv[0])
		{
			count--;
			break ;
		}
		i++;
	}
	if (i >= 0)
		return (fct[0](ap, datas));
	return (-1);
}
