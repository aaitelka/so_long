# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 18:52:15 by aaitelka          #+#    #+#              #
#    Updated: 2024/05/18 20:24:31 by aaitelka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN := \033[0;32m
NC := \033[0m
LIBMLX := ./lib/MLX42
LIBFT := ./lib/libft
CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := so_long
BONUS := so_long_bonus

HEADS := -I ./manda/include -I ./bonus/include -I $(LIBFT) -I $(LIBMLX)/include
LIBS := $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -lglfw -ldl -pthread -lm -L"/Users/$(USER)/.brew/opt/glfw/lib/"

SRCS := manda/main.c \
        manda/src/map.c \
        manda/src/moves.c \
        manda/src/assert.c \
        manda/src/window.c \
        manda/src/texture.c \
        manda/src/parsing.c \
        manda/src/cleaner.c \
        manda/src/game_init.c \
        manda/src/mlx_utils.c \
        manda/src/map_utils.c

OBJS := $(SRCS:%.c=%.o)

B_SRCS := bonus/main_bonus.c \
          bonus/src/map_bonus.c \
          bonus/src/moves_bonus.c \
          bonus/src/assert_bonus.c \
          bonus/src/window_bonus.c \
          bonus/src/texture_bonus.c \
          bonus/src/parsing_bonus.c \
          bonus/src/cleaner_bonus.c \
          bonus/src/mapping_bonus.c \
          bonus/src/game_init_bonus.c \
          bonus/src/mlx_utils_bonus.c \
          bonus/src/map_utils_bonus.c \
          bonus/src/enemy_moves_bonus.c \
          bonus/src/load_textures_bonus.c

B_OBJS := $(B_SRCS:%.c=%.o)

all: libft libmlx $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)==========| Linking $(NAME) executable... |==========$(NC)"
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

bonus: libft libmlx $(BONUS)

$(BONUS): $(B_OBJS)
	@echo "$(GREEN)==========| Linking $(BONUS) executable... |==========$(NC)"
	$(CC) $(CFLAGS) $(B_OBJS) $(LIBS) -o $(BONUS)

libft:
	@$(MAKE) --no-print-directory -C $(LIBFT) -j4

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && \
	make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADS) -o $@ -c $<

%_bonus.o : %_bonus.c bonus/include/types_bonus.h
	@$(CC) $(CFLAGS) $(HEADS) -o $@ -c $<
	
clean:
	@echo "$(GREEN)==========| Cleaning... |==========$(NC)"
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@echo "$(GREEN)==========| Full Cleaning... |==========$(NC)"
	$(RM) $(NAME) $(BONUS)
	$(RM) -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all
