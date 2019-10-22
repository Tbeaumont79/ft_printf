/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:00:10 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/22 13:57:48 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

char *test_1(int i, ...)
{
	va_list argptr;
	va_start(argptr, i);
	char *str = "\0";
	while (i)
	{
		str[i] = va_arg(argptr, int);
		i--;
	}
	va_end(argptr);
	return (str);
}
int main(int ac, char **av)
{
	(void)ac;
	char *s = test_1(3, av[1][0], av[2][0], av[3][0]);
	printf("%s\n",s);
	return (0);
}
