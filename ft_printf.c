/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:06:41 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/11/08 00:07:24 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	va_list ap;
	va_start(ap, s);
	t_struct datas;
	
    ft_bzero(datas.buf, 1);
	ft_parse(ap, datas, s);
	va_end(ap);
	return (0);
}

int main(int ac, char **av)
{
	(void)ac;
	ft_printf("bonjour je suis %s et j'ai %d ans enfaite je suis nee en %i et %x et un 10: %X\n", av[1], 20, 1999, 14, 10);
	printf("bonjour je suis %s et j'ai %d ans enfaite je suis nee en %i et %x  et un 10: %X\n", av[1], 20, 1999, 14, 10);
	return (0);
}
