/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:00:10 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/15 08:13:43 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

char *test_1(int i, ...)
{
	va_list argptr;
	va_start(argptr, i);
	char *str;
	int size;

	size = 0;
	if (!(str = (char *)malloc(sizeof(char ) * (i + 1))))
		return (0);
	while (size < i)
	{
		str[size] = va_arg(argptr, int);
		size++;
	}
	return (str);
}
int main(int ac, char **av)
{
	char *s = test_1(ac - 1, av[1][0], av[2][0], av[3][0]);
	printf("%s\n",s);
	return (0);
}
