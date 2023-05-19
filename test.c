#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

char addOne(unsigned int i, char c) {return (i + c);}

int main(void)
{
	char * s = ft_strmapi("1234", addOne);
	printf("%p\n", s);
	free(s);
	s = ft_strmapi("", addOne);
	printf("%p\n", s);
	printf("%d\n", strcmp(s, ""));
	return 0;
}