#include "ft_printf.h"
#include "libft/libft.h"

int pf_p(va_list ap, t_struct datas, int i)
{
    long long val;
    int j;
    char *stringValue;

    j = 0;
    val = va_arg(ap, long long);
    if (!(stringValue = ft_itoa_base(val, 16)))
        return (0);
    stringValue = string_lower(stringValue);
    ft_buffer('0', datas);
    ft_buffer('x', datas);
    while (stringValue[j])
        ft_buffer(stringValue[j++], datas);
    return (i); 
}