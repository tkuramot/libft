NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
INCLUDE = 'libft.h'
SOURCES = ft_isalpha.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

.c.o: $(OBJECTS)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all