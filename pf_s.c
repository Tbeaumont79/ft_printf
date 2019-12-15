/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:02:15 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/11/08 14:00:49 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int pf_s(va_list ap, t_struct datas, int i)
{
    char *val;
    int j;

    j = 0;
    if((val = va_arg(ap, char *) == NULL) {
        val = "(null)";
    }
    while (val[j])
    {
        datas.str[i] = val[j];
        j++;
        i++;
    }

    ft_buffer(datas);
    free(datas.str);
    return (j);
}
