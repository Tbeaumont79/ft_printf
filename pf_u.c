#include "ft_printf.h"
#include "libft/libft.h"

int pf_u(va_list ap, t_struct datas, int i)
{
    unsigned long long int nb;
    char *string;
    int j;

    j = 0;
    nb = va_arg(ap, unsigned long long int);
    if (!(string = ft_itoa_base(nb, 10)))
        return (0);
    while (string[j])
        ft_buffer(string[j++], datas);
    return (i);
}
