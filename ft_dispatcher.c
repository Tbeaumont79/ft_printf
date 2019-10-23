/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:33:55 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/23 18:06:41 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_dispatcher(va_list ap, t_struct *datas)
{
	static char *conv= "s";
	int (*fct[1])(va_list, t_struct *) = {pf_s};
	size_t i;

	i = 0;
	while (datas->str[i])
	{
		if (datas->str[i] == conv[0])
		{
			printf("JE BREAK !!\n");
			break;
		}
		printf("JE TOURNE DANS DISPATCHER \n");
		i++;
	}
	if (i >= 0)
		return (fct[0](ap, datas));
	return (-1);
}
