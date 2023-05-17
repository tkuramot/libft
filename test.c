#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    printf("%p\n", calloc(0, 0));
    printf("%p\n", ft_calloc(0, 0));
    return 0;
}