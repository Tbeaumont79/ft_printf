/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:02:15 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/11/05 18:49:44 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int     pf_s(va_list ap, t_struct *datas)
{
	char *tmp;
	char *val;

	val = va_arg(ap, char *);
	if (!(tmp = ft_strdup(val)))
		return (0);
	if (!(datas->str = ft_strjoin(datas->str, tmp)))
		return (0);
    if (!(ft_buffer(datas)))
        return (-1);
	free(tmp);
    return (1);
}
