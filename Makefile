LIBFTPRINTF = libftprintf.a
PRINTF_SRCS = ft_printf.c functions.c modify.c
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

NAME = pushswap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = pushswap.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFTPRINTF) $(NAME)

$(LIBFTPRINTF): $(PRINTF_OBJS)
	@ar rcs $(LIBFTPRINTF) $(PRINTF_OBJS)
	@echo "Library created: $(LIBFTPRINTF)"

$(NAME): $(OBJS) $(LIBFTPRINTF)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"

clean:
	@rm -f $(OBJS)
	@echo "Cleaned objects"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned all"

re: fclean all
	@echo "Rebuild complete"

.PHONY: all clean fclean re
