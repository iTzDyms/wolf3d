#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cheron <cheron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 17:06:50 by cheron            #+#    #+#              #
#    Updated: 2015/02/16 16:18:14 by cheron           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC := gcc
CFLAGS := -Wall -Werror -Wextra
OFLAGS := -O3
RM := rm -rf

LIBFT_PATH := ./libft
LIBFT_INCLUDES_PATH := ./libft/includes
WOLF3D_INCLUDES_PATH := ./includes
SDL2_INCLUDES_PATH := ./SDL2/include/SDL2

LDFLAGS := -lSDL2
LIBFTFLAGS := -lft

LIBFT := $(LIBFT_PATH)/libft.a

NAME := wolf3d

SDL2_PATH := ./SDL2/lib
lSDL2 := libSDL2.a

SRC := main.c ft_print_map.c set_player_pos.c ft_map.c ft_pdata.c \
	ft_sdl.c ft_proceed.c ft_screen.c ft_draw_renderer.c \
	ft_move.c ft_rotate.c ft_ray.c	ft_distance.c ft_dda.c \
	ft_collide.c ft_set_color.c ft_texture.c ft_surface.c

OBJ := $(SRC:.c=.o)
POBJ = $(addprefix $(OBJ_PATH)/, $(OBJ))

SRC_PATH := srcs
OBJ_PATH := obj

all: $(LIBFT) $(NAME)

run: all
	./$(NAME)
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
	@echo ""

$(NAME): $(SDL2_PATH)/$(lSDL2) $(LIBFT) $(OBJ_PATH) $(POBJ)
	@($(CC) -o $@ -L$(SDL2_PATH) $(LDFLAGS) -L$(LIBFT_PATH) $(LIBFTFLAGS) $(POBJ))
	@echo "\nLinking "$@

clean:	
	@($(RM) $(POBJ))
	@echo "\nCleaning object files in "$(NAME)"\n"
	$(MAKE) $@ -C $(LIBFT_PATH)


fclean: clean
	@$(RM) $(NAME)
	@echo "\nCleaning "$(NAME)"\n"
	$(MAKE) $@ -C $(LIBFT_PATH)

re: fclean all

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(WOLF3D_INCLUDES_PATH)
	$(CC) $(CFLAGS) $(OFLAGS) $(LDFLAGS) -c $< -o $@ -I $(WOLF3D_INCLUDES_PATH) -I $(LIBFT_INCLUDES_PATH) -I $(SDL2_INCLUDES_PATH)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(SDL2_PATH)/$(lSDL2):
	rm -rf SDL2/junk/SDL2-2.0.3.tar.gz SDL2/junk/SDL2-2.0.3
	mkdir -p SDL2/junk
	curl -O https://www.libsdl.org/release/SDL2-2.0.3.tar.gz
	tar xf SDL2-2.0.3.tar.gz
	( cd SDL2-2.0.3 \
	 && ./configure CC=clang --prefix=$(shell pwd)/SDL2/ \
  	 && $(MAKE) CC=clang && $(MAKE) CC=clang install )
	mv SDL2-2.0.3.tar.gz SDL2-2.0.3 SDL2/junk
							 
.PHONY: SDL2 all clean re fclean
