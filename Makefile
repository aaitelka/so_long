# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 18:52:15 by aaitelka          #+#    #+#              #
#    Updated: 2024/04/30 19:03:21 by aaitelka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GREEN	:=	\033[0;32m
NC		:=	\033[0m

LIBFT	:=	libft/libft.a
MK_LBFT	:=	@$(MAKE) --no-print-directory -C libft

CC		:=	cc
CFLAGS	:=	#-Wall -Wextra -Werror

NAME	:=	so_long
HEAD	:=	include/so_long.h

BONUS	:= so_long_bonus
B_HEAD	:= bonus/include/so_long_bonus.h

SRCS	:=	so_long.c \

OBJS	:=	$(SRCS:%.c=%.o)

B_SRCS	:=	

B_OBJS	:=	$(B_SRCS:%_bonus.c=%_bonus.o)

all : 			$(NAME)

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME): 		$(OBJS) $(LIBFT) $(HEAD)
				@echo "$(GREEN)==========| Linking $(NAME) executable... |==========$(NC)"
				$(CC) $(OBJS) $(LIBFT) -o $@


%_bonus.o : 	%_bonus.c
				$(CC) $(CFLAGS) -c $< -o $@

bonus		: 	$(CHECKER)

$(BONUS)	: 	$(B_OBJS) $(LIBFT) $(B_HEAD)
				@echo "$(GREEN)==========| Linking $(CHECKER) executable... |==========$(NC)"
				$(CC) $(B_OBJS) $(LIBFT) -o $@

$(LIBFT) :
				@echo "$(GREEN)==========| Compiling libft... |==========$(NC)"
				$(MK_LBFT)
				@echo "$(GREEN)==========| Compiling libft bonus... |==========$(NC)"
				$(MK_LBFT) bonus

clean		:
				@echo "$(GREEN)==========| Cleaning... |==========...$(NC)"
				$(MK_LBFT) clean
				$(RM) $(OBJS) $(B_OBJS)

fclean :		clean
				@echo "$(GREEN)==========| Full Cleaning... |==========$(NC)"
				$(MK_LBFT) fclean
				$(RM) $(NAME) $(CHECKER)

re		:		fclean all