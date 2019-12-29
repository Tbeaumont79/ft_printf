#include "libft/libft.h"
#include "ft_printf.h"

int ft_get_int(t_struct datas, const char *s, int i)
{
	int nb;
	(void)datas;

	nb = 0;
	if (ft_isdigit(s[i]))
	{
		nb = nb * 10 + ft_atoi(&s[i]);
		while (ft_isdigit(s[i]))
			i++;
	}
	return (i);
}
