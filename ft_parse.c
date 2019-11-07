/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:33 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/11/07 14:45:02 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
//faire un truck qui ajoute dans un tableau de tableau chaque valeur des
//argument puis remplacer les %s 
int		ft_parse(va_list ap, t_struct *datas, const char *s)
{
	int k;

	k = 0;
	datas->start = 0;
	if (!(datas->str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (s[datas->start])
	{
		if (s[datas->start] == '%')
			ft_dispatcher(ap, datas);
		else
			datas->str[k++] = s[datas->start];
		datas->start++;
	}
	return (0);
}
