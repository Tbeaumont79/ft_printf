#include "libft/libft.h"
#include "ft_printf.h"

char *string_lower(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
        i++;
    }
    return (s);
}