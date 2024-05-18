NAME = push_swap

SRCS = main.c split.c stack_init.c stack_util.c push_command.c reverse_rotate_command.c rotate_command.c \
	    sort_stack.c swap_command.c stack_init_a_to_b.c stack_init_b_to_a.c sort_three.c  error_hand.c \

PRINTF = ft_printf/libftprintf.a

CFLAGS = -Wall -Werror -Wextra

CC = cc

PRINTF_PATH = ft_printf

OBJ = $(SRCS:.c=.o)

all: $(NAME)


$(PRINTF) :
	$(MAKE) -C $(PRINTF_PATH)

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(PRINTF)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(PRINTF_PATH) clean

fclean: clean 
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_PATH) fclean

re: fclean all