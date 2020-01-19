/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:18:01 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/19 10:36:20 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Libft/libft.h"
#include "../headers/ft_printf.h"


int		ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}