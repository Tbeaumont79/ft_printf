/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:17:35 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/08 13:01:37 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct pf_c(va_list ap, t_struct datas, int i, const char *s)
{
    int val;
    int j;
	int prec_len;
	int sizes;
    (void)s;

	sizes = 1;
	datas.flag[temp] = i;
    j = 0;
    val = va_arg(ap, int);
	prec_len = (datas.flag[size_prec] > sizes ? datas.flag[size_prec] - sizes : 0);
    if ((!datas.flag[flags] && (!datas.flag[prec] || datas.flag[size_prec] == 0)
	 && datas.flag[size] > 0))
	 datas = fill_size(datas, sizes);
    datas = ft_buffer(val, datas);
	if (datas.flag[flags] == '-')
		datas = ft_right_justify(datas, sizes, prec_len);
    return (datas);
}
