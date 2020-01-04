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
        tmp--;
    while (i < flag_len && s[tmp] != flag[i])
        i++;
	if (s[tmp] == flag[i])
		datas.flag[flags] = flag[i];
    if (s[tmp] == flag[i] && ft_isdigit(s[tmp + 1]))
        return (get_int(datas, tmp + 1, s));
    if (s[tmp] != flag[i] && ft_isdigit(s[tmp]))
        return (get_int(datas, tmp + 1, s));
    return (datas);
}
