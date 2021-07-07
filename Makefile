##
## EPITECH PROJECT, 2021
## Makefile for antman
## File description:
## global makefile
##

all:
	make -C antman/
	make -C giantman/

clean:
	make clean -C antman/
	make clean -C giantman/

fclean:
	make fclean -C antman/
	make fclean -C giantman/

re:
	make re -C antman/
	make re -C giantman/

.PHONY: all clean fclean re