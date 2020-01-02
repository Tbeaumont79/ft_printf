/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:17:27 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/02 17:17:30 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int ft_width(int val, char *str, int i, t_struct datas)
{
    int j;
    int size;
    int nb_zero;
    int total_size;

    size = nb_len(val, 10);
    nb_zero = ft_atoi(&str[i]);
    j = 0;
    if (nb_zero > size)
        total_size = nb_zero - size;
    else
        total_size = size - nb_zero;
    while (total_size > 0)
    {
        ft_buffer('0', datas);
        total_size--;
    }

    return (1);
}
