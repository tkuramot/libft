#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
	char *s = calloc(30, sizeof(char));
	memcpy(s, "libft-test-tokyo", 17);
	memcpy(s + 20, "acdfg", 5);
	//printf("%s\n", ft_memchr(s, 'z', 30));
    printf("%s\n", memchr(s, 'z', 30));
    return 0;
}