NAME = push_swap

BONUS_NAME = checker

SRCS = main.c split.c stack_init.c stack_util.c push_command.c reverse_rotate_command.c rotate_command.c \
	    sort_stack.c swap_command.c stack_init_a_to_b.c stack_init_b_to_a.c sort_three.c  error_hand.c \
		with_main.c \

BONUS = checker.c split.c stack_init.c stack_util.c push_command.c reverse_rotate_command.c rotate_command.c \
	    sort_stack.c swap_command.c stack_init_a_to_b.c stack_init_b_to_a.c sort_three.c  error_hand.c \
		with_main.c get_next_line.c get_next_line_utils.c checker_utils.c \

PRINTF = ft_printf/libftprintf.a

CFLAGS = -Wall -Werror -Wextra

CC = cc

PRINTF_PATH = ft_printf

OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)

all: $(NAME)

$(PRINTF) :
	$(MAKE) -C $(PRINTF_PATH)

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(PRINTF)

$(BONUS_NAME): $(OBJ_BONUS) $(PRINTF)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJ_BONUS) $(PRINTF)

bonus : fclean $(BONUS_NAME)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	$(MAKE) -C $(PRINTF_PATH) clean

fclean: clean 
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(PRINTF_PATH) fclean

re: fclean all