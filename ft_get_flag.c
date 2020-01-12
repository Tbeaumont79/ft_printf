/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:18:14 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/04 12:01:27 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

t_struct get_flag(t_struct datas, const char *s, int i)
{
    static char flag[4] = {'-', '0', '.', '*'};
    int j;
    int tmp;
    int size_of_flag_array;

    j = 0;
    tmp = 0;
    datas.flag[temp] = i;
    size_of_flag_array = ft_strlen(flag);
    while (s[tmp])
    {
        if (s[tmp] == '.' && ft_isdigit(s[tmp + 1]))
        {
            datas.flag[prec] = s[tmp];
            datas = get_int(datas, tmp + 1, s);
        }
        tmp++;
    }
    while (j < size_of_flag_array && s[i + 1] != flag[j])
        j++;
    if (s[i + 1] == flag[j] && !ft_isdigit(s[i + 2]))
    {
        datas.flag[flags] = flag[j];
        datas.flag[temp]++;
    }
    if (s[i + 1] == flag[j] && ft_isdigit(s[i + 2]))
    {
        datas.flag[flags] = flag[j];
        datas = get_int(datas, datas.flag[temp] + 2, s);
    }
    return (datas);
}

//faire un check dans la boucle de decrementation si s[tmp] == '.' et que ft_isdigit[tmp + 1]
//alors prec == 1 et datas.flag[size_prec == get_int(datas, tmp + 1, s) ] et comme ca tu soustrait ca a la valeur des autres flag and its done
//
//
/*
 *     static char flag[4] = {'0', '-', '*', '.'};
 int i;
 int flag_len;

 i = 0;
 flag_len = ft_strlen(flag);
 while (s[tmp - 1] != '%')
 {
 if (s[tmp] == '.' || (s[tmp] == '.' && ft_isdigit(s[tmp + 1])))
 {
 datas.flag[prec] = s[tmp];
 datas = get_int(datas, tmp + 1, s);
 }
 tmp--;
 }
 while (i < flag_len && s[tmp] != flag[i])
 i++;
 if (s[tmp] == flag[i])
 datas.flag[flags] = flag[i];
 if (s[tmp] == flag[i] && ft_isdigit(s[tmp + 1]))
 datas = get_int(datas, tmp + 1, s);
 if (s[tmp] != flag[i] && ft_isdigit(s[tmp]))
 datas = get_int(datas, tmp + 1, s);
 return (datas);
 */
