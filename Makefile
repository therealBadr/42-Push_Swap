SRC = mandatory/ft_atoi.c \
      mandatory/ft_split.c \
      mandatory/lst_utils.c \
      mandatory/parsing.c \
      mandatory/push_swap.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

FLAGS = -Wall -Wextra -Werror -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re