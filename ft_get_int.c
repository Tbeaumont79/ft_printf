/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:18:24 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/03 14:22:45 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

t_struct get_int(t_struct datas, int tmp, const char *s)
{
    int nb;

    nb = 0;
    if (ft_isdigit(s[tmp]))
    {
        nb = nb * 10 + ft_atoi(&s[tmp]);
        while (ft_isdigit(s[tmp]))
            tmp++;
    }
    datas.flag[size] = nb;
    datas.flag[temp] = tmp++;
    return (datas);
}
