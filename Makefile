NAME = libft.a
CFLAGS = -g -MMD -MP -Wall -Wextra -Werror
DFLAGS = -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined -fsanitize=bounds
INCLUDE = -I ./include
SRC = \
			ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_chrdup.c \
			ft_dlstadd_back.c \
			ft_dlstadd_front.c \
			ft_dlstclear.c \
			ft_dlstdelone.c \
			ft_dlstiter.c \
			ft_dlstlast.c \
			ft_dlstmap.c \
			ft_dlstnew.c \
			ft_dlstpop_back.c \
			ft_dlstpop_front.c \
			ft_dlstsize.c \
			ft_dprintf.c \
			ft_dprintf_char.c \
			ft_dprintf_int.c \
			ft_dprintf_lower_hex.c \
			ft_dprintf_percent.c \
			ft_dprintf_ptr.c \
			ft_dprintf_putchar.c \
			ft_dprintf_putnstr.c \
			ft_dprintf_putstr.c \
			ft_dprintf_str.c \
			ft_dprintf_uint.c \
			ft_dprintf_upper_hex.c \
			ft_dprintf_utils.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_lstadd_back_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstmap_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstpop_back_bonus.c \
			ft_lstpop_front.c \
			ft_lstsize_bonus.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c \
			get_next_line_bonus.c \
			get_next_line_utils.c \
			get_next_line_utils_bonus.c
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEPEND = $(OBJ:.o=.d)

vpath %.c ctype strings stdio stdio/ft-printf stdio/get-next-line list dlist stdlib string

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(if $(DEBUG),$(DFLAGS),) $(INCLUDE) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug:
	make DEBUG=1

.PHONY: clean fclean re all debug

-include $(DEPEND)
