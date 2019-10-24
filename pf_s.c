/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:02:15 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/24 12:31:44 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		pf_s(va_list ap, t_struct *datas)
{
	char *tmp;

	if (!(tmp = ft_strjoin(datas->str, va_arg(ap, char *))))
		return (0);
	ft_putstr(tmp);
	free(tmp);
	return (-1);
}
