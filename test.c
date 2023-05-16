#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char *s1 = "abcd";
    char *s2 = "abzz";
	printf("%d\n", ft_strncmp(s1, s2, 4));
	printf("%d\n", strncmp(s1, s2, 4));
    return 0;
}