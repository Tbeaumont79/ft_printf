/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   justify.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:18:48 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/02 17:18:49 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void fill_with_char(char c, t_struct datas, int final_length)
{
    int j;

    j = 0;
    while (j < final_length)
    {
        ft_buffer(c, datas);
        j++;
    }
}

void ft_left_justify(t_struct datas, int len_arg)
{
    int final_length;

    if (len_arg > datas.flag[size])
        final_length = len_arg - datas.flag[size];
    if (datas.flag[size] > len_arg)
        final_length = datas.flag[size] - len_arg;
    if (datas.flag[flags] == '0')
        fill_with_char('0', datas, final_length);
    else
        fill_with_char(' ', datas, final_length);
}
