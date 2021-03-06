/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:18:33 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/13 14:19:43 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

long int			nb_len(long nb, int base)
{
	int size;

	size = 0;
	if (nb < 0)
	{
		size++;
		nb = ft_abs(nb);
	}
	if (nb == 0)
		size++;
	while (nb > 0)
	{
		nb = nb / base;
		size++;
	}
	return (size);
}
