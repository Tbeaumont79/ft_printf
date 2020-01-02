/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:17:35 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/02 17:17:39 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int pf_c(va_list ap, t_struct datas, int i, const char *s)
{
    int val;
    int j;
    (void)s;

    j = 0;
    val = va_arg(ap, int);
    ft_buffer(val, datas);
    return (i);
}
