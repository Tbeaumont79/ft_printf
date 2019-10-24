/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:02:15 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/24 16:13:05 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		pf_s(va_list ap, t_struct *datas)
{
	char *tmp;
	int	len;
   
	len	= ft_strlen(va_arg(ap, char *));
	if (!(tmp = ft_strjoin(datas->buf, va_arg(ap, char *))))
		return (0);
	datas->buf = tmp;
	free(tmp);
	return (len);
}
