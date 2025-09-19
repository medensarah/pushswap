GREEN = \033[0;38;2;142;194;121;49m
LIGHTGREEN = \033[0;38;2;142;255;105;49m
YELLOW = \033[0;93m
LIGHTYELLOW = \033[1;33m
PINK = \033[0;38;2;255;206;248;49m
PURPLE = \033[0;38;2;194;170;242;49m
NONE = \033[0m

LIBFT = libft.a
LIBFT_SRCS = ft_libft/ft_atoi.c ft_libft/ft_bzero.c \
	ft_libft/ft_calloc.c ft_libft/ft_isalnum.c \
	ft_libft/ft_isalpha.c ft_libft/ft_isascii.c \
	ft_libft/ft_isdigit.c ft_libft/ft_isprint.c \
	ft_libft/ft_itoa.c ft_libft/ft_memchr.c \
	ft_libft/ft_memmove.c ft_libft/ft_memset.c \
	ft_libft/ft_memcpy.c ft_libft/ft_memcmp.c \
	ft_libft/ft_putchar_fd.c ft_libft/ft_putnbr_fd.c \
	ft_libft/ft_putstr_fd.c ft_libft/ft_split.c \
	ft_libft/ft_strchr.c ft_libft/ft_strdup.c \
	ft_libft/ft_striteri.c ft_libft/ft_strjoin.c \
	ft_libft/ft_strlcat.c ft_libft/ft_strlcpy.c \
	ft_libft/ft_strlen.c ft_libft/ft_strmapi.c \
	ft_libft/ft_strnstr.c ft_libft/ft_strncmp.c \
	ft_libft/ft_strnstr.c ft_libft/ft_strrchr.c \
	ft_libft/ft_strtrim.c ft_libft/ft_substr.c \
	ft_libft/ft_tolower.c ft_libft/ft_putendl_fd.c \
	ft_libft/ft_toupper.c
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

PRINTF = printf.a
PRINTF_SRCS = ft_printf/ft_printf.c ft_printf/functions.c \
			ft_printf/modify.c
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

NAME = pushswap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRCS = src/list.c src/main.c \
	src/parsing_utils.c src/parsing.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT): $(LIBFT_OBJS)
	@ar rcs $(LIBFT) $(LIBFT_OBJS)
	@echo "$(LIGHTGREEN)Library libft created: $(LIBFT)$(NONE)"

$(PRINTF): $(PRINTF_OBJS)
	@ar rcs $(PRINTF) $(PRINTF_OBJS)
	@echo "$(LIGHTGREEN)Library printf created: $(PRINTF)$(NONE)"

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)
	@echo "$(PINK)Build complete (./pushswap)$(NONE)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling $<$(NONE)"

clean:
	@rm -f $(OBJS) $(LIBFT_OBJS) $(PRINTF_OBJS)
	@echo "$(YELLOW)Cleaned objects$(NONE)"

fclean: clean
	@rm -f $(NAME) libft.a printf.a
	@echo "$(LIGHTYELLOW)Cleaned all$(NONE)"

re: fclean all
	@echo "$(PURPLE)Rebuild complete$(NONE)"

.PHONY: all clean fclean re
