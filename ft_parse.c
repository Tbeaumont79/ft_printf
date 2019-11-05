/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:33 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/11/05 16:34:36 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
//faire un truck qui ajoute dans un tableau de tableau chaque valeur des
//argument puis remplacer les %s 
int		ft_parse(va_list ap, t_struct *datas, const char *s)
{
	size_t		i;
	size_t		j;
	size_t		k;
	static char *conv= "\%scdep"; //ect
//malloc data dans main
	i = 0;
	k = 0;
	if (!(datas->str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (*s)
	{
        j = 0;
	    while (conv[j])
		{
			if (conv[j] == *s)
		        ft_dispatcher(ap, datas);
            else
                datas->str[k] = *s;
			j++;
		}
        k++;
        s++;
	}
	return (0);
}
