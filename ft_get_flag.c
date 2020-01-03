/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:18:14 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/03 09:51:35 by thbeaumo         ###   ########.fr       */
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
        tmp--;
    while (i < flag_len && s[tmp] != flag[i])
        i++;
    if (s[tmp] == flag[i] && ft_isdigit(s[tmp + 1]))
    {
        datas.flag[flags] = flag[i];
        return (get_int(datas, tmp, s));
    }
    if (s[tmp] != flag[i] && ft_isdigit(s[tmp]))
        return (get_int(datas, tmp, s));
    return (datas);
}
