/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:02:15 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/19 15:07:37 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct pf_s(va_list ap, t_struct datas, int i, const char *s)
{
    char *val;
    int j;
	int prec_len;
    (void)s;

    j = 0;
	datas.flag[temp] = i;
    if((val = va_arg(ap, char *)) == NULL)
    {
        val = "(null)";
        datas = ft_buffer('\0', datas);
        return (datas);
    }
	prec_len = (datas.flag[size_prec] > 0 ?
		   	datas.flag[size_prec] : (int)ft_strlen(val));
	if ((!datas.flag[flags] && (!datas.flag[prec] || datas.flag[size_prec] == 0)
	 && datas.flag[size] > 0))
		datas = fill_size(datas, (int)ft_strlen(val));
    while (val[j])
	{
		while (j < prec_len)
			datas = ft_buffer(val[j++], datas);
		if (j >= prec_len)
			break ;
	}
    return (datas);
}
