/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:08:27 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/13 14:34:07 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
   //printf("other:%05d bonjour\n", 12);
   printf("-1.5 : %-1.5dbonjour\n", 12);
   printf("01.5 : %01.5dbonjour\n", 12);
   printf("-5.2 : %-5.2dbonjour\n", 12);
   printf("05.2 : %05.2dbonjour\n", 12);
   printf("-10.5 : %-10.5dbonjour\n", 12);
   printf("010.5 : %010.5dbonjour\n", 12);
   return 0;
}
