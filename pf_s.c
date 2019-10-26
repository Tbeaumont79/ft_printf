/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:02:15 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/25 17:16:19 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		pf_s(va_list ap, t_struct *datas)
{
	char *tmp;
	int	len;
	char *val;

	val = va_arg(ap, char *);
	len	= ft_strlen(val);
	if (!(tmp = ft_strdup(val)))
		return (0);
	if (!(datas->buf = ft_strjoin(datas->buf, tmp)))
		return (0);
	free(tmp);
	return (len);
}
