/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:18:24 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/13 11:16:17 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

t_struct get_int(t_struct datas, int tmp, const char *s)
{
    int nb;
    static int preci = 0;
    
    nb = 0;
    if (datas.flag[prec] == '.')
        preci++;
    if (ft_isdigit(s[tmp]))
    {
        nb = nb * 10 + ft_atoi(&s[tmp]);
        while (ft_isdigit(s[tmp]))
		{
			datas.flag[temp]++;
            tmp++;
		}
    }
    if (preci == 1)
        datas.flag[size_prec] = nb;
    else
        datas.flag[size] = nb;
    return (datas);
}
