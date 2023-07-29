# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 19:07:36 by anvannin          #+#    #+#              #
#    Updated: 2023/07/28 20:47:34 by anvannin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libvector.a
SRC		=	vector.c vector2.c
OBJ		=	$(SRC:.c=.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

# Colors and output modifiers
BOLD		:= ${shell tput bold}
UNSET		:= ${shell tput sgr0}
GREEN		:= ${shell tput setaf 2}

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	@echo "${BOLD}[100%]	  Done!   ->  ${GREEN}$(NAME)${UNSET}"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:
.SILENT:
