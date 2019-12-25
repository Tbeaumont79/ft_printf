#include "ft_printf.h"
#include "libft/libft.h"

int		nb_len(long nb, int base)
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