GREEN = \033[0;38;2;142;194;121;49m
LIGHTGREEN = \033[0;38;2;142;255;105;49m
YELLOW = \033[0;93m
LIGHTYELLOW = \033[1;33m
PINK = \033[0;38;2;255;206;248;49m
PURPLE = \033[0;38;2;194;170;242;49m
NONE = \033[0m

LIBFTPRINTF = libftprintf.a
PRINTF_SRCS = ft_printf/ft_printf.c ft_printf/functions.c \
			ft_printf/modify.c
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

NAME = pushswap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRCS = src/main.c src/parsing.c src/parsing_utils.c \
		src/list.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFTPRINTF) $(NAME)

$(LIBFTPRINTF): $(PRINTF_OBJS)
	@ar rcs $(LIBFTPRINTF) $(PRINTF_OBJS)
	@echo "$(LIGHTGREEN)Library created: $(LIBFTPRINTF)$(NONE)"

$(NAME): $(OBJS) $(LIBFTPRINTF)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF)
	@echo "$(PINK)Build complete (./pushswap)$(NONE)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling $<$(NONE)"

clean:
	@rm -f $(OBJS) $(PRINTF_OBJS)
	@echo "$(YELLOW)Cleaned objects$(NONE)"

fclean: clean
	@rm -f $(NAME) libftprintf.a
	@echo "$(LIGHTYELLOW)Cleaned all$(NONE)"

re: fclean all
	@echo "$(PURPLE)Rebuild complete$(NONE)"

.PHONY: all clean fclean re
