/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:33 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/23 14:01:30 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_parse(va_list ap, t_struct *datas)
{
	size_t		i;
	size_t		j;
	static char *conv= "cspdiuxX"; //ect
//malloc data dans main
	i = 0;
	while (datas->str[i])
	{
		if (datas->str[i] == '%')
		{
			while (conv[j])
			{
				if (conv[j] == datas->str[i + 1])
					return (ft_dispatcher(ap, datas));
				j++;
			}
			// call au dispatcher !!
		}
		// sinon tu bufferise le reste de la string 
		i++;
	}
	return (0);
}
