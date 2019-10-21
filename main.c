/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:08:27 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/10/21 12:24:14 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
   printf("Characters: %c %c \n", 'a', 65);
   printf("Decimals: %d %ld\n", 1977, 650000L);
   printf("Preceding with blanks: %10d \n", 1977);
   printf("Preceding with zeros: %010d \n", 1977);
   printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf("Width trick: %*d \n", 5, 10);
   printf("%s \n", "A string");
   return 0;
}
