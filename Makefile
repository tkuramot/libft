NAME = libft.a
CFLAGS = -g -MMD -MP -Wall -Wextra -Werror
INCLUDE = -I include
SRC = /ctype/ft_isalnum.c /ctype/ft_isalpha.c /ctype/ft_isascii.c /ctype/ft_isdigit.c /ctype/ft_isprint.c /ctype/ft_tolower.c /ctype/ft_toupper.c /list/ft_lstadd_back_bonus.c /list/ft_lstadd_front_bonus.c /list/ft_lstclear_bonus.c /list/ft_lstdelone_bonus.c /list/ft_lstiter_bonus.c /list/ft_lstlast_bonus.c /list/ft_lstmap_bonus.c /list/ft_lstnew_bonus.c /list/ft_lstsize_bonus.c /stdio/ft-printf/ft_printf.c /stdio/ft-printf/ft_printf_char.c /stdio/ft-printf/ft_printf_int.c /stdio/ft-printf/ft_printf_lower_hex.c /stdio/ft-printf/ft_printf_percent.c /stdio/ft-printf/ft_printf_ptr.c /stdio/ft-printf/ft_printf_str.c /stdio/ft-printf/ft_printf_uint.c /stdio/ft-printf/ft_printf_upper_hex.c /stdio/ft-printf/ft_printf_utils.c /stdio/ft-printf/ft_putchar_r.c /stdio/ft-printf/ft_putnstr_r.c /stdio/ft-printf/ft_putstr_r.c /stdio/ft-printf/libft/ft_atoi.c /stdio/ft-printf/libft/ft_bzero.c /stdio/ft-printf/libft/ft_calloc.c /stdio/ft-printf/libft/ft_isalnum.c /stdio/ft-printf/libft/ft_isalpha.c /stdio/ft-printf/libft/ft_isascii.c /stdio/ft-printf/libft/ft_isdigit.c /stdio/ft-printf/libft/ft_isprint.c /stdio/ft-printf/libft/ft_itoa.c /stdio/ft-printf/libft/ft_lstadd_back_bonus.c /stdio/ft-printf/libft/ft_lstadd_front_bonus.c /stdio/ft-printf/libft/ft_lstclear_bonus.c /stdio/ft-printf/libft/ft_lstdelone_bonus.c /stdio/ft-printf/libft/ft_lstiter_bonus.c /stdio/ft-printf/libft/ft_lstlast_bonus.c /stdio/ft-printf/libft/ft_lstmap_bonus.c /stdio/ft-printf/libft/ft_lstnew_bonus.c /stdio/ft-printf/libft/ft_lstsize_bonus.c /stdio/ft-printf/libft/ft_memchr.c /stdio/ft-printf/libft/ft_memcmp.c /stdio/ft-printf/libft/ft_memcpy.c /stdio/ft-printf/libft/ft_memmove.c /stdio/ft-printf/libft/ft_memset.c /stdio/ft-printf/libft/ft_putchar_fd.c /stdio/ft-printf/libft/ft_putendl_fd.c /stdio/ft-printf/libft/ft_putnbr_fd.c /stdio/ft-printf/libft/ft_putstr_fd.c /stdio/ft-printf/libft/ft_split.c /stdio/ft-printf/libft/ft_strchr.c /stdio/ft-printf/libft/ft_strdup.c /stdio/ft-printf/libft/ft_striteri.c /stdio/ft-printf/libft/ft_strjoin.c /stdio/ft-printf/libft/ft_strlcat.c /stdio/ft-printf/libft/ft_strlcpy.c /stdio/ft-printf/libft/ft_strlen.c /stdio/ft-printf/libft/ft_strmapi.c /stdio/ft-printf/libft/ft_strncmp.c /stdio/ft-printf/libft/ft_strnstr.c /stdio/ft-printf/libft/ft_strrchr.c /stdio/ft-printf/libft/ft_strtrim.c /stdio/ft-printf/libft/ft_substr.c /stdio/ft-printf/libft/ft_tolower.c /stdio/ft-printf/libft/ft_toupper.c /stdio/ft-printf/libft/get_next_line.c /stdio/ft-printf/libft/get_next_line_utils.c /stdio/ft_putchar_fd.c /stdio/ft_putchar_r.c /stdio/ft_putendl_fd.c /stdio/ft_putnbr_fd.c /stdio/ft_putnstr_r.c /stdio/ft_putstr_fd.c /stdio/ft_putstr_r.c /stdio/get-next-line/get_next_line.c /stdio/get-next-line/get_next_line_bonus.c /stdio/get-next-line/get_next_line_utils.c /stdio/get-next-line/get_next_line_utils_bonus.c /stdlib/ft_atoi.c /stdlib/ft_calloc.c /stdlib/ft_itoa.c /string/ft_memchr.c /string/ft_memcmp.c /string/ft_memcpy.c /string/ft_memmove.c /string/ft_memset.c /string/ft_split.c /string/ft_strchr.c /string/ft_strdup.c /string/ft_striteri.c /string/ft_strjoin.c /string/ft_strlcat.c /string/ft_strlcpy.c /string/ft_strlen.c /string/ft_strmapi.c /string/ft_strncmp.c /string/ft_strnstr.c /string/ft_strrchr.c /string/ft_strtrim.c /string/ft_substr.c /strings/ft_bzero.c
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

fname:
	find . -name "*.c" | sed 's/\.//' | tr '\n' ' '

.PHONY: clean fclean re all

-include $(DEPEND)
