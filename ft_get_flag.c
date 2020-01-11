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

t_struct get_flag(t_struct datas, int tmp, const char *s)
{
    static char flag[4] = {'0', '-', '*', '.'};
    int i;
    int flag_len;

    i = 0;
    flag_len = ft_strlen(flag);
    while (s[tmp - 1] != '%')
    {
        if (s[tmp] == '.' && ft_isdigit(s[tmp + 1]))
        {
            datas.flag[flags] = s[tmp];
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
   /* if (s[datas.flag[temp]] == '.' && ft_is_digit(s[datas.flag[temp] + 1]))
    {
        tmp = datas.flag[temp];
        datas = get_int(datas, tmp + 1, s);
    }*/
    return (datas);
}

//faire un check dans la boucle de decrementation si s[tmp] == '.' et que ft_isdigit[tmp + 1]
//alors prec == 1 et datas.flag[size_prec == get_int(datas, tmp + 1, s) ] et comme ca tu soustrait ca a la valeur des autres flag and its done
