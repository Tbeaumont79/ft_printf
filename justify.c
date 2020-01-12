/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   justify.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:18:48 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/03 15:09:58 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void     fill_if_prec(t_struct datas, int len_arg, int prec_len)
{
    while (datas.flag[size] - len_arg > 0 && datas.flag[size] - len_arg > prec_len)
    {
        ft_buffer(' ', datas);
        datas.flag[size]--;
    }
    while (prec_len > 0)
    {
        ft_buffer('0', datas);
        prec_len--;
    }
}

static void		fill_with_char(char c, t_struct datas, int final_length, int len_arg)
{
    int j;
    int prec_len;
    int tmp;

    j = 0;
    tmp = final_length; // probleme quand datas.size == 1 !
    prec_len = datas.flag[size_prec] > len_arg ? datas.flag[size_prec] - len_arg : 0;
    // pour le moment je mets 0 par supposition mais besoin de faire plus de test !
    if (datas.flag[prec] == '.')
         fill_if_prec(datas, len_arg, prec_len);
    else
    {
        while (j < final_length)
        {
            ft_buffer(c, datas);
            j++;
        }
    }
}

static int		ft_get_final_length(int len_arg, t_struct datas)
{
    return (len_arg > datas.flag[size] ? 
            len_arg - datas.flag[size] : (datas.flag[size] - len_arg));
}

void	ft_left_justify(t_struct datas, int len_arg)
{
    int final_length;

    final_length = ft_get_final_length(len_arg, datas);
    if (datas.flag[flags] == '0')
        fill_with_char('0', datas, final_length, len_arg);
    else
        fill_with_char(' ', datas, final_length, len_arg);
}

void	ft_right_justify(t_struct datas, int len_arg)
{
    int final_length;

    final_length = ft_get_final_length(len_arg, datas);
    if (datas.flag[flags] == '-')
        fill_with_char(' ', datas, final_length, len_arg);
}
