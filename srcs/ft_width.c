/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:17:27 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/05 16:36:20 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct	ft_width(va_list ap, t_struct datas, const char *s, int i)
{
    int val;
    int tmp;


    val = 0 ;
    tmp = 0;
    if ((tmp = va_arg(ap, int)) == 0)
    {
        datas.flag[size] = 0;
        datas.flag[size_prec] = 0;
        datas.flag[temp]++;
        return (datas);
    }
    if (s[i] == '*')
    {	
        val = tmp != 0 ? tmp : 0;
        if (val > 0)
        {
            if (i > 0 && s[i - 1] == '.')
                datas.flag[size_prec] = val;
            else
                datas.flag[size] = val;
        }
        if (val < 0) // check pour voir si ca s'applique a toutes les convertions ! 
        {
            if (i > 0 && s[i - 1] == '.')
            {
                datas.flag[size_prec] = val;
                datas.flag[temp]++;
                return (datas);
            }
            else
            {
                if (datas.flag[conv] == 's')
                {
                    datas.flag[size] = val;
                    datas.flag[temp]++;
                    return (datas);
                }
                else
                {
                    datas.flag[flags] = '-';
                    datas.flag[size] = -val;
                }
            }
        }            
        if (datas.flag[size_prec] || datas.flag[size])
            datas.flag[temp]++;
    }
    return (datas);
}
