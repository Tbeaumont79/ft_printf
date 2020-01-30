/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:17:35 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/30 11:57:39 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct pf_c(va_list ap, t_struct datas, int i, const char *s)
{
    int val;
    int j;
	int prec_len;
    (void)s;

	datas.flag[temp] = i;
    j = 0;
    val = va_arg(ap, int);
	prec_len = (datas.flag[size_prec] > 1 ? datas.flag[size_prec] - 1 : 0);
    if ((!datas.flag[flags] && (!datas.flag[prec] || datas.flag[size_prec] == 0)
	 && datas.flag[size] > 0))
	 datas = fill_size(datas, 1);
    datas = ft_buffer(val, datas);
	if (datas.flag[flags] == '-')
		datas = ft_right_justify(datas, 1, prec_len);
    return (datas);
}
