/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:02:15 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/11/08 14:00:49 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int     pf_s(va_list ap, t_struct datas)
{
	char *val;
    int i;

    i = 0;
	val = va_arg(ap, char *);
    datas.arg_len = ft_strlen(val);
	printf("%s <- AVANT\n", datas.str);
    while(val[i])
    {
        datas.str[datas.start] = val[i];
        i++;
        datas.start++;
    }
    datas.str[datas.start] = '\0';
	printf("%s <- APRES\n", datas.str);
    ft_buffer(datas);
    return (i);
}
