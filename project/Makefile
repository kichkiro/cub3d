# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:51:06 by kichkiro          #+#    #+#              #
#    Updated: 2023/07/28 20:41:39 by anvannin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

NAME		:= minirt
SRCS        := \
				main/main.c \
				main/errors_handler.c \
				window/window.c \
				window/hooks.c \
				parser/parser.c \
				parser/get_value.c \
				parser/display_obj.c \
				parser/geometric_obj.c \
				parser/lighting_obj.c \
				_lst/t_scene_add_back.c \
				_lst/t_scene_new.c \
				_lst/t_scene_set_to_head.c \
				_lst/t_scene_free.c \
				color/color.c \
				add_to_libft/ft_atof.c

SRC_DIR     := src
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
BUILD_DIR   := .build
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
LIB  		:= ./lib/libft.a ./lib/libmlx.a
LIB_VECTOR	:= ./lib/vector
INCS        := ./include ./lib
CC          := gcc
CFLAGS      := -g #-Wall -Wextra -Werror
MLXFLAGS    := -lXext -lX11 -lm -lbsd
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
RM          := rm -rf
MAKEFLAGS   := --no-print-directory
DIR_DUP     = mkdir -p $(@D)

.PHONY: all clean fclean re
.SILENT:

# Percent functions ----------------------------------------------------------->

define total_files
$(shell echo "$(SRCS)" | wc -w)
endef

define obj_files
$(shell bash -c 'shopt -s nullglob && echo .build/**/*.o | wc -w')
endef

define percent
$(shell echo $$(($(obj_files) * 100 / $(total_files))))
endef

# Rules ----------------------------------------------------------------------->

all: banner vector $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB) $(MLXFLAGS)
	${info ${BOLD}[100%]	  Done!   ->  ${GREEN}$(NAME)${NO_COLOR}}

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	${info ${BOLD}[$(percent)%]	Compiling -> ${YELLOW}$@${NO_COLOR}}

-include $(DEPS)

vector:
	make -sC $(LIB_VECTOR)

vector_clean:
	make clean -sC $(LIB_VECTOR)

vector_fclean:
	make fclean -sC $(LIB_VECTOR)

clean: vector_clean
	$(RM) $(BUILD_DIR)
	${info }
	${info ${BOLD}${YELLOW}Cleaning in progress...${NO_COLOR}    🧹 🧹 🧹}

fclean: clean
	$(RM) $(NAME) $(NAME_CLIENT)

re: vector_fclean
	$(MAKE) fclean
	$(MAKE) all

bonus: all

# Style ----------------------------------------------------------------------->

RED 		:= ${shell tput setaf 1}
GREEN		:= ${shell tput setaf 2}
BLUE		:= ${shell tput setaf 4}
YELLOW		:= ${shell tput setaf 3}
CYAN		:= ${shell tput setaf 6}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

ECHO_BLUE	:= \033[34m
ECHO_BOLD	:= \033[1m
ECHO_UNSET	:= \033[0m

banner:
	@echo "${ECHO_BLUE}"'    ___       ___       ___       ___       ___       ___'
	@echo "${ECHO_BLUE}"'   /\__\     /\  \     /\__\     /\  \     /\  \     /\  \'
	@echo "${ECHO_BLUE}"'  /::L_L_   _\:\  \   /:| _|_   _\:\  \   /::\  \    \:\  \'
	@echo "${ECHO_BLUE}"' /:/L:\__\ /\/::\__\ /::|/\__\ /\/::\__\ /::\:\__\   /::\__\'
	@echo "${ECHO_BLUE}"' \/_/:/  / \::/\/__/ \/|::/  / \::/\/__/ \;:::/  /  /:/\/__/'
	@echo "${ECHO_BLUE}"'   /:/  /   \:\__\     |:/  /   \:\__\    |:\/__/   \/__/'
	@echo "${ECHO_BLUE}"'   \/__/     \/__/     \/__/     \/__/     \|__|'
	@echo
	@echo "${ECHO_BOLD}"'            ✨ My first RayTracer with miniLibX ✨${ECHO_UNSET}'

# ------------------------------------------------------------------------------
