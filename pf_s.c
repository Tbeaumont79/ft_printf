/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:02:15 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/11/07 15:19:59 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int     pf_s(va_list ap, t_struct *datas)
{
	char *val;
	char *tmp;
	
	val = va_arg(ap, char *);
	if (!(tmp = ft_strdup(val)))
		return (-1);
	//printf("%s <- AVANT\n", datas->str);
	if (!(datas->str = ft_strjoin(datas->str, tmp)))
		return (-1);
	//printf("%s <- APRES\n", datas->str);
    if (!(ft_buffer(datas)))
        return (-1);
    return (1);
}
