/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:19:33 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/26 17:42:17 by thbeaumo         ###   ########.fr       */
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
	size_t		count;
	static char *conv= "s"; //ect
//malloc data dans main
	i = 0;
	count = 0;
	j = 0;
	k = 0;
	if (!(datas->buf = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (s[k])
	{
		if (s[k] == '%')
			count++;
		k++;
	}
	k = 0;
	printf("%lu\n", count);
	while (s[k] && count)
	{
		if (s[k] == '%')
		{
			while (conv[j])
			{
				if (conv[j] == s[k + 1])
					i = ft_dispatcher(ap, datas, count);
				j++;
			}
			k += i;
			// le k++ est temporaire faire un strlen apres le %
	   }	
		datas->buf[k] = s[k];
		k++;
		printf("%lu\n",count);
	}
	ft_putstr(datas->buf);
	return (0);
}
