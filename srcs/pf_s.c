/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:02:15 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/16 08:17:59 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

int pf_s(va_list ap, t_struct datas, int i, const char *s)
{
    char *val;
    int j;
	int prec_len;
    (void)s;

    j = 0;
    if((val = va_arg(ap, char *)) == NULL)
    {
        val = "(null)";
        ft_buffer('\0', datas);
        return (i);
    }
	prec_len = (datas.flag[size_prec] > 0 ?
		   	datas.flag[size_prec] : (int)ft_strlen(val));
    while (val[j])
	{
		while (j < prec_len)
			ft_buffer(val[j++], datas);
		if (j >= prec_len)
			break ;
	}
    return (i);
}
