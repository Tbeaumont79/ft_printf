#include "../Libft/libft.h"
#include "../headers/ft_printf.h"

t_struct     fill_if_percent(t_struct datas)
{
    if (datas.flag[flags] == '0')
    {
        while (datas.flag[size]-- > 1)
            datas = ft_buffer('0', datas);
    }
    if (datas.flag[prec] == '.')
    {
        while (datas.flag[size_prec]-- > 1)
            datas = ft_buffer('0', datas);
    }
    if (datas.flag[prec] == '.' && datas.flag[flags] == '-')
    {
        while (datas.flag[size_prec]-- > 1)
            datas = ft_buffer('0', datas);
    }
    datas = ft_buffer('%', datas);
    if (datas.flag[flags] == '-')
    {
        while (datas.flag[size]-- > 1)
            datas = ft_buffer(' ', datas);
    }
    return (datas);
}
t_struct    pf_pct(va_list ap, t_struct datas, int i, const char *s)
{
    int j;

    (void)s;
    (void)ap;
    j = 0;
    datas.flag[temp] = i;
    if (datas.flag[flags])
        datas = fill_if_percent(datas);
    else
    {
        while (datas.flag[size]-- > 1)
            datas = ft_buffer(' ', datas);
        datas = ft_buffer('%', datas);
    }
    return (datas);
}
