/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:06:41 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/23 14:19:04 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	va_list ap;
	va_start(ap, s);
	t_struct *datas;
	
	if (!(datas = (t_struct *)malloc()))	

	va_end(ap);
	return (0);
}
