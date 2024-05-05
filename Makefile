# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 18:52:15 by aaitelka          #+#    #+#              #
#    Updated: 2024/05/04 23:57:27 by aaitelka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GREEN	:= \033[0;32m
NC		:= \033[0m

LIBMLX	:= ./lib/MLX42

LIBFT	:= ./lib/libft

CC		:= cc
CFLAGS	:= #-Wall -Wextra -Werror

NAME	:= so_long
HEADS	:= -I ./include -I $(LIBFT) -I $(LIBMLX)/include

BONUS	:= so_long_bonus
B_HEAD	:= bonus/include/so_long_bonus.h

LIBS	:= $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

SRCS	:= so_long.c \
			src/moves.c \

OBJS	:= $(SRCS:%.c=%.o)

B_SRCS	:=	

B_OBJS	:= $(B_SRCS:%_bonus.c=%_bonus.o)

all: libft libmlx $(NAME)

libft:
	@$(MAKE) --no-print-directory -C $(LIBFT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADS)

$(NAME) : $(OBJS) include/so_long.h
	@echo "$(GREEN)==========| Linking $(NAME) executable... |==========$(NC)"
	@$(CC) $(OBJS) $(LIBS) $(HEADS) -o $(NAME)

%_bonus.o : %_bonus.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@echo "$(GREEN)==========| Cleaning... |==========...$(NC)"
	$(RM) $(OBJS) $(B_OBJS)
	$(RM) -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT) clean

fclean : clean
	@echo "$(GREEN)==========| Full Cleaning... |==========$(NC)"
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re : fclean all

.PHONY: all, clean, fclean, re, libmlx