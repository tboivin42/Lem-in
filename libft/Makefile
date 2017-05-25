#	Output's Name
NAME = libft.a

#	GCC flags
CFLAGS = -Werror
ALL_CFLAGS = -Wall -Wextra $(CFLAGS)

# Includes directories
INC_PATH = includes/
INCLUDES_FILES=  includes/ft_printf.h includes/get_next_line.h includes/libft.h

INCLUDES += $(addprefix -iquote , $(INC_PATH))
# Sources Objects directories
SRCS = Lst/ft_lstadd.c \
	Lst/ft_lstdel.c \
Lst/ft_lstdelone.c\
Lst/ft_lstiter.c\
Lst/ft_lstmap.c\
Lst/ft_lstnew.c\
\
Mem/ft_memalloc.c\
Mem/ft_memccpy.c\
Mem/ft_memchr.c\
Mem/ft_memcmp.c\
Mem/ft_memcpy.c\
Mem/ft_memdel.c\
Mem/ft_memmove.c\
Mem/ft_memset.c\
\
Other/ft_atoi.c\
Other/ft_bzero.c\
Other/ft_count_bits.c\
Other/ft_exit.c\
Other/ft_isalnum.c\
Other/ft_isalpha.c\
Other/ft_isascii.c\
Other/ft_isdigit.c\
Other/ft_islower.c\
Other/ft_isprint.c\
Other/ft_isupper.c\
Other/ft_itoa.c\
Other/ft_itoa_base.c\
Other/ft_power.c\
Other/ft_tolower.c\
Other/ft_toupper.c\
Other/ft_wcharlen.c\
Other/ft_wstrlen.c\
Other/get_next_line.c\
\
Put/ft_putchar.c\
Put/ft_putchar_fd.c\
Put/ft_putendl.c\
Put/ft_putendl_fd.c\
Put/ft_putnbr.c\
Put/ft_putnbr_fd.c\
Put/ft_putstr.c\
Put/ft_putstr_fd.c\
Put/ft_putwchar.c\
Put/ft_putwstr.c\
\
Str/ft_str_isalnum.c\
Str/ft_str_isascii.c\
Str/ft_str_isdigit.c\
Str/ft_strcat.c\
Str/ft_strccmp.c\
Str/ft_strchr.c\
Str/ft_strclen.c\
Str/ft_strclr.c\
Str/ft_strcmp.c\
Str/ft_strcpy.c\
Str/ft_strdel.c\
Str/ft_strdup.c\
Str/ft_strequ.c\
Str/ft_striter.c\
Str/ft_striteri.c\
Str/ft_strjoin.c\
Str/ft_strlcat.c\
Str/ft_strlen.c\
Str/ft_strmap.c\
Str/ft_strmapi.c\
Str/ft_strncat.c\
Str/ft_strncmp.c\
Str/ft_strncpy.c\
Str/ft_strndup.c\
Str/ft_strnequ.c\
Str/ft_strnew.c\
Str/ft_strnlen.c\
Str/ft_strnstr.c\
Str/ft_strrchr.c\
Str/ft_strsplit.c\
Str/ft_strstr.c\
Str/ft_strsub.c\
Str/ft_strtrim.c\
\
printf/ft_printf.c\
printf/setup.c\
\
printf/conv/conv_base.c\
printf/conv/conv_c.c\
printf/conv/conv_d.c\
printf/conv/handles_conv.c\
printf/conv/mod_conv.c\
\
printf/get/get_flags.c\
printf/get/get_string_c.c\
printf/get/get_string_d.c\
printf/get/get_string_s.c\
\
printf/print/print_c.c\
printf/print/print_d.c\
\
printf/tools/color_fun.c\
printf/tools/ft_strsetc.c\
printf/tools/ft_wlen.c\
printf/tools/print_w.c\
printf/tools/tools.c\

OBJS = $(SRCS:.c=.o)

all: makefile $(INCLUDES_FILES) $(NAME)

header:
	@echo "\033[1;36m[${NAME}]\033[1;32m Compile && Archive\033[0m"

$(NAME): $(OBJS)
	@printf "\r\e\033[0m\e[K\033[1;31m $@ \033[1;32m - Finished\033[0m\n"
	@ar rc $(NAME) $(OBJS)
%.o: %.c
	@printf "\r\033[1;32m. Compilation .\e\033[0m\e[K \033[1;31m$<"
	@gcc $(ALL_CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "\033[1;31m[\033[1m$(NAME)]\033[0m\033[1;33m >>\033[0m \033[1;32mclean (*.o)\033[0m"
	@$(RM) $(OBJS)

fclean: clean
	@echo "\033[1;31m[\033[1m$(NAME)]\033[0m\033[1;33m >>\033[0m \033[1;32mfclean ($(NAME))\033[0m"
	@$(RM) $(NAME)

re: fclean all
