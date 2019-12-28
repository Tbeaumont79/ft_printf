#include "ft_printf.h"
#include "libft/libft.h"

t_struct get_int(t_struct datas, int tmp, const char *s)
{
    int nb;

    nb = 0;
    if (ft_isdigit(s[tmp]))
    {
        nb = nb * 10 + ft_atoi(&s[tmp]);
        while (ft_isdigit(s[tmp]))
            tmp++;
    }
    datas.flag[size] = nb;
    datas.flag[tmp] = tmp;
    return (datas);
}

t_struct get_flag(t_struct datas, int tmp, const char *s)
{
    static char *flag = {'0', '-', '*', '.'};
    int i;
    int flag_len;

    i = 0;
    flag_len = ft_strlen(flag);
    while (s[tmp] != '%')
        tmp--;
    while (i < flag_len && s[tmp] != flag[i])
        i++;
    if (i == flag_len && ft_isdigit(s[i + 1]))
        return (get_int(datas, tmp, s));
    if (i == flag_len && flag[i] == s[tmp])
        datas.flag[flags] = flag[i];

    return (datas);
}

int pf_d(va_list ap, t_struct datas, int i, const char *s)
{
    int val;
    int j;
    int tmp;
    char *stringValue;

    tmp = i;
    j = 0;
    val = va_arg(ap, int);
    stringValue = ft_itoa_base(val, 10);
    while (stringValue[j])
        ft_buffer(stringValue[j++], datas);
    return (i);
}
