/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:17:35 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/16 08:17:07 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

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
