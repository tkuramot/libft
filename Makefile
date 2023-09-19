NAME = libft.a
CFLAGS = -g -MMD -MP -Wall -Wextra -Werror
INCLUDE = -I include
SRC = /ctype/ft_isdigit.c /ctype/ft_isascii.c /ctype/ft_isprint.c /ctype/ft_toupper.c /ctype/ft_isalpha.c /ctype/ft_isalnum.c /ctype/ft_tolower.c /strings/ft_bzero.c /stdio/ft_putstr_fd.c /stdio/ft-printf/ft_dprintf_char.c /stdio/ft-printf/ft_dprintf_uint.c /stdio/ft-printf/ft_dprintf.c /stdio/ft-printf/ft_dprintf_putchar.c /stdio/ft-printf/ft_dprintf_str.c /stdio/ft-printf/ft_dprintf_ptr.c /stdio/ft-printf/ft_dprintf_lower_hex.c /stdio/ft-printf/ft_dprintf_percent.c /stdio/ft-printf/ft_dprintf_putstr.c /stdio/ft-printf/ft_dprintf_putnstr.c /stdio/ft-printf/ft_dprintf_int.c /stdio/ft-printf/ft_dprintf_upper_hex.c /stdio/ft-printf/ft_dprintf_utils.c /stdio/ft_putnbr_fd.c /stdio/ft_putendl_fd.c /stdio/get-next-line/get_next_line_bonus.c /stdio/get-next-line/get_next_line_utils.c /stdio/get-next-line/get_next_line.c /stdio/get-next-line/get_next_line_utils_bonus.c /stdio/ft_putchar_fd.c /list/ft_lstpop_front.c /list/ft_lstadd_front_bonus.c /list/ft_lstdelone_bonus.c /list/ft_lstadd_back_bonus.c /list/ft_lstmap_bonus.c /list/ft_lstclear_bonus.c /list/ft_lstpop_back_bonus.c /list/ft_lstiter_bonus.c /list/ft_lstlast_bonus.c /list/ft_lstsize_bonus.c /list/ft_lstnew_bonus.c /stdlib/ft_calloc.c /stdlib/ft_atoi.c /stdlib/ft_itoa.c /string/ft_strnstr.c /string/ft_strlcpy.c /string/ft_strlen.c /string/ft_memcmp.c /string/ft_strchr.c /string/ft_striteri.c /string/ft_strjoin.c /string/ft_memcpy.c /string/ft_split.c /string/ft_strrchr.c /string/ft_memchr.c /string/ft_memset.c /string/ft_substr.c /string/ft_strncmp.c /string/ft_strmapi.c /string/ft_strtrim.c /string/ft_memmove.c /string/ft_strlcat.c /string/ft_strdup.c /string/ft_strcmp.c
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))
DEPEND = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.c
	@ mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

cfile:
	find . -name "*.c" | sed 's/\.//' | tr '\n' ' '

.PHONY: clean fclean re all

-include $(DEPEND)
