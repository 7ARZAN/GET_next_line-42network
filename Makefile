# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 10:11:41 by elakhfif          #+#    #+#              #
#    Updated: 2022/10/31 10:11:46 by elakhfif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
CC = gcc
CFLAGS = -Wall -Wextra -Werror -D
SRC =  get_next_line.c\
		get_next_line_bonus.c\
		get_next_line_utils.c\
		get_next_line_utils_bonus.c\   
OBJ = $(SRC:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o $@

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	$(OBJ)
			@echo "$(GREEN)Compilation $(CLR_RMV)of ${YELLOW}$(NAME) $(CLR_RMV)7ARZAN ..."
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
			@echo "$(GREEN)$(NAME) HAK HAHOWA M9AD[0m ✔️"

all:		$(NAME)

bonus:		all

clean:
			@ $(RM) $(OBJ)
			@ echo "$(RED)7ARZAN GALIK MSE7 $(CYAN)$(NAME) $(CLR_RMV)OBJS ✔️"

fclean:		clean
			@ $(RM) $(NAME)
			@ echo "$(RED)7ARZAN GALIK $(CYAN)$(NAME) $(CLR_RMV)BINARY ✔️"

re:			fclean all

.PHONY:		all clean fclean re


