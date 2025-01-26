SRC =

SRC_BONUS =

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

EXE_BONUS = checker

NAME = push_swap

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME} : ${OBJ}
	cc ${FLAGS} ${OBJ} -o ${NAME}

${EXE_BONUS} : ${OBJ_BONUS}
	cc ${FLAGS} ${OBJ_BONUS} -o ${EXE_BONUS}

%.o : %.c push_swap.h
	cc ${FLAGS} -c $< -o $@

clean :
	rm -f ${OBJ} ${OBJ_BONUS}

fclean : clean
	rm -f ${NAME} ${EXE_BONUS}

re : fclean all

