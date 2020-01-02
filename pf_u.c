/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:19:12 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/02 17:19:13 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int pf_u(va_list ap, t_struct datas, int i, const char *s)
{
    unsigned long long int nb;
    char *string;
    int j;
    (void)s;

    j = 0;
    nb = va_arg(ap, unsigned long long int);
    if (!(string = ft_itoa_base(nb, 10)))
        return (0);
    while (string[j])
        ft_buffer(string[j++], datas);
    return (i);
}
