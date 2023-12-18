NAME=push_swap
CC=cc
CFLAGS=-Wall -Werror -Wextra
LIBFT=./libft/libft.a
H=src/push_swap.h

SRC=	check.c \
		movements_a.c \
		movements_b.c \
		movements_all.c \
		push_swap.c \
		aux.c \
		aux_sort.c \
		stack.c \
		free.c \
		sort.c

OBJ=$(SRC:.c=.o)

$(NAME): $(OBJ)
	@make all -C ./libft
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

all: $(NAME)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $<

#test: $(NAME)
#	@cp $(NAME) tester/
#	@cd tester; bash push_swap_test.sh

clean:
	@make clean -C ./libft
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@make clean -C ./libft
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

re_bonus: fclean

.PHONY: all clean fclean re