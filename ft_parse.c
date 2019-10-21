/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:33 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/21 15:32:00 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_parse(t_struct *data)
{
	int i;
	int val;
	static char *conv= "cspdiuxX"; //ect
//malloc data dans main
	val = 0;
	i = 0;
	while (data->str[i])
	{
		if (data->str[i] == '%')
		{
			if (data->str[i + 1] == 'd' || data->str[i + 1] == 'i')
				return (1);
			if (data->str[i + 1] == 'c')
				return (2);
			if (data->str[i + 1] == 's')
				return (3);
		}
		i++;
	}
	return (0);
}
