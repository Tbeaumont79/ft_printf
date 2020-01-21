/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:17:35 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/19 13:51:34 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct pf_c(va_list ap, t_struct datas, int i, const char *s)
{
    int val;
    int j;
    (void)s;

	datas.flag[temp] = i;
    j = 0;
    val = va_arg(ap, int);
    if ((!datas.flag[flags] && (!datas.flag[prec] || datas.flag[size_prec] == 0)
	 && datas.flag[size] > 0))
	 datas = fill_size(datas, 1);
    datas = ft_buffer(val, datas);
    return (datas);
}
