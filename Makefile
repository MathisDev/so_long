# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamottet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/11 16:19:23 by mamottet          #+#    #+#              #
#    Updated: 2023/08/25 10:57:53 by mamottet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compile 
CC = gcc
FLG = -Wall -Wextra -Werror -I$(PATH_LIB)
COMP = $(CC) $(FLG)

# C / D
RM = rm -fr
MKDIR = mkdir -p 

# directory
BIN = bin
DIR = $(BIN)

# SRC
SRC = 	./src/frees.c \
	./src/map_validate.c \
	./src/map_init.c \
	./src/utils.c \
	./src/map_init_utils.c \
	./src/game_events_utils.c \
	./src/exit_actions.c \
	./src/main.c \
	./src/game_events.c \
	./src/draw.c \
	./src/errors.c \
	./src/game_init.c 

# lib
PATH_LIB =libs/c_lib/
NAME_LIB=lib.a
A_LIB = $(PATH_LIB)$(NAME_LIB)
MAKE_LIB= make -C $(PATH_LIB)


# MLX
PATH_MLX = libs/minilibx-linux/
NAME_MLX = libmlx.a
NAME2_MLX = libmlx_Linux.a
A_MLX = $(PATH_MLX)$(NAME_MLX) $(PATH_MLX)$(NAME2_MLX)
MAKE_MLX = make -C $(PATH_MLX)

link= -lXext -lX11 -lm -lz

all:
	@ echo "\n Build LIB"
	$(MAKE_LIB)
	@echo "\n Build MLX\n"
	$(MAKE_MLX)
	@echo "\n Start Build \n" 
	$(MKDIR) $(DIR)
	@echo "\n Build main\n"
	$(COMP) $(SRC) -o bin/so_long $(A_LIB) $(A_MLX) $(link)

fclean:
	$(RM) $(DIR)
	$(MAKE_LIB) fclean
	$(MAKE_MLX) clean
re:	fclean all
