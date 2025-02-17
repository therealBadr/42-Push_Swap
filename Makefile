SRC = mandatory/sort_small.c \
      mandatory/ft_split.c \
      mandatory/lst_utils.c \
      mandatory/parsing.c \
      mandatory/push_swap.c \
      mandatory/indexing.c \
      mandatory/sort.c \
      operations/pa_pb.c \
      operations/ra_rb.c \
      operations/rra_rrb.c \
      operations/sa_sb.c \
	  mandatory/ft_atoi.c \
	  mandatory/ft_strncmp.c 

BONUS = bonus/checker_bonus.c \
		bonus/checker_utils_bonus.c \
		bonus/get_next_line_bonus.c \
		bonus/get_next_line_utils_bonus.c \
		operations/pa_pb.c \
      	operations/ra_rb.c \
      	operations/rra_rrb.c \
      	operations/sa_sb.c \
      	mandatory/lst_utils.c \
      	mandatory/parsing.c \
		mandatory/ft_split.c \
		mandatory/ft_atoi.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

NAME = push_swap

BONUS_NAME = checker

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	cc $(FLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

%.o: %.c push_swap.h
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re