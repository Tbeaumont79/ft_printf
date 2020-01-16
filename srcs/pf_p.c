/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:05 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/16 08:17:39 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

int pf_p(va_list ap, t_struct datas, int i, const char *s)
{
    long long val;
    int j;
    char *stringValue;
    (void)s;

    j = 0;
    val = va_arg(ap, long long);
    if (!(stringValue = ft_itoa_base(val, 16)))
        return (0);
    stringValue = string_lower(stringValue);
    ft_buffer('0', datas);
    ft_buffer('x', datas);
    while (stringValue[j])
        ft_buffer(stringValue[j++], datas);
    return (i); 
}
