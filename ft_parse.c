/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:33 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/24 12:31:44 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_parse(va_list ap, t_struct *datas, const char *s)
{
	size_t		i;
	size_t		j;
	static char *conv= "s"; //ect
//malloc data dans main
	i = 0;
	j = 0;
	if (!(datas->str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (s[i])
	{
		datas->str[i] = s[i];
		i++;
	}
	i = 0;
	while (datas->str[i])
	{
		if (datas->str[i] == '%')
		{
			printf("OHHOOH\n");
			while (conv[j])
			{
				if (conv[j] == datas->str[i + 1])
				{
					printf("JE VAIS DANS LE DISPATCHER !!!!! \n");
					return (ft_dispatcher(ap, datas));
				}
				printf("JE PARCOURS CONVV[J] %c !!!!! ET DATAS->STR[i] == %c\n",conv[j],datas->str[i + 1]);
				j++;
			}
			// call au dispatcher !!
		}
		printf("je passe par la ! %c et s :: %c \n", datas->str[i], s[i]);
		// sinon tu bufferise le reste de la string 
		i++;
	}
	return (0);
}
