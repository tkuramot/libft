#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[12];
    char *s = "abcdefg";
    ft_memmove(str, s, 7);
    printf("%s\n", str);

    char str1[100] = "123456789";
    ft_memmove(str1 + 5, str1, 11);
    printf("%s\n", str1);
    return 0;
}