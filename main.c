/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:08:27 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/15 12:27:47 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("FOR x :: ---------------------------\n");
	printf("0*.*x : %0*.*xbonjour\n",10, 5, 12);
	printf("-*.*x : %-*.*xbonjour\n",10, 5, 12);
	printf("010.5x : %010.5xbonjour\n", 12);
	printf("-10.5x : %-10.5xbonjour\n", 12);
	printf("0*x : %0*xbonjour\n",10, 12);
	printf("-*x : %-*xbonjour\n",10, 12);
	printf("FOR X :: ---------------------------\n");
	printf("0*.*X : %0*.*Xbonjour\n",10, 5, 12);
	printf("-*.*X : %-*.*Xbonjour\n",10, 5, 12);
	printf("010.5X : %010.5Xbonjour\n", 12);
	printf("-10.5X : %-10.5Xbonjour\n", 12);
	printf("0*X : %0*Xbonjour\n",10, 12);
	printf("-*X : %-*Xbonjour\n",10, 12);
	printf("FOR u :: ---------------------------\n");
	printf("0*.*u : %0*.*ubonjour\n",10, 5, 12);
	printf("-*.*u : %-*.*ubonjour\n",10, 5, 12);
	printf("010.5u : %010.5ubonjour\n", 12);
	printf("-10.5u : %-10.5ubonjour\n", 12);
	printf("0*u : %0*ubonjour\n",10, 12);
	printf("-*u : %-*ubonjour\n",10, 12);
	return 0;
}
