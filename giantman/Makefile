##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

NAME = giantman

SRCS =	src/main.c

HEADER = ./include
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -I ${HEADER}
RM = rm -f

all:	giantman

giantman:	${OBJS}
		${CC} ${OBJS} ${CFLAGS} -o ${NAME}

clean:
		${RM} ${OBJS}
		${RM} *.*gc*

fclean:	clean
		${RM} ${NAME} unit_tests

re:		fclean all

tests_run:
		${CC} ${SRCST} -I ${HEADER} -lm -lcriterion --coverage -o unit_tests
		./unit_tests

.PHONY: all lib giantman clean fclean re tests_run
