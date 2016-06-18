# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehansman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/12 13:36:17 by ehansman          #+#    #+#              #
#    Updated: 2016/06/12 16:35:54 by ehansman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
FILES = read.c store_arr.c filler.c *weight.c seek.c
FILES += basic_math.c scan_arr.c result.c free_arr.c
HEADER = filler.h
OBJECTS = $(FILES:.c=.o)
CFLAG = -Wall -Werror -Wextra
ATTACH = libft/libft.a

all: fclean lib $(NAME)
	@echo "Ready for use ;)"

quick: fclean $(NAME)
	@echo "Made Quickly"

lib:
	@make -C libft/ fclean
	@make -C libft/

$(NAME):
	@gcc $(CFLAG) $(FILES) $(HEADER) $(ATTACH)
	@echo "filler Successfully Compiled"
	@mv a.out $(NAME)

clean:
	@/bin/rm -f $(OBJECTS) $(HEADER:.h=.h.gch)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

norm:
	@clear
	@norminette -R CheckForbiddenSourceHeader $(FILES) $(HEADER)

test:
	@/bin/rm -f debugdump.txt
	@touch debugdump.txt
	@resources/filler_vm -p1 ./filler -f resources/maps/map00

testvs:
	@/bin/rm -f debugdump.txt
	@touch debugdump.txt
	@resources/filler_vm -p1 ./filler -p2 ./resources/players/grati.filler -f \
		resources/maps/map00

testvs2:
	#@/bin/rm -f debugdump.txt
	#@touch debugdump.txt
	@resources/filler_vm -p1 ./resources/players/grati.filler -p2 ./filler -f \
		resources/maps/map00

ftest: fclean all test
	@echo "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
	#@less debugdump.txt
