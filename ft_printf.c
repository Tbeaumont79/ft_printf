/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:06:41 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/24 12:31:45 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	va_list ap;
	va_start(ap, s);
	t_struct *datas;
	size_t	 len;
	
	len = ft_strlen(s);
	if (!(datas = (t_struct *)malloc(sizeof(t_struct) * (len + 1))))
		return (0);
	ft_parse(ap, datas, s);
	va_end(ap);
	return (0);
}

int main(int ac, char **av)
{
	(void)ac;
	ft_printf("Bonjour %s mdr ceci est un test", av[1]);
	return (0);
}
