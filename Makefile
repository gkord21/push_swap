# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkord <gkord@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 18:47:06 by gkord             #+#    #+#              #
#    Updated: 2022/03/11 17:02:30 by gkord            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
NAME_B	= checker

SRC	=		ft_atoi.c\
    		ft_error_exit.c\
    		ft_isdigit.c\
    		ft_sort.c\
    		ft_stack_utils.c\
    		push_swap.c\
			ft_swap.c\
			ft_rotate.c\
			ft_rev_rotate.c\
			ft_push.c\
			ft_mod.c\
			ft_big_sort.c\
			ft_big_sort_utils.c\
			ft_array_utils.c\
			ft_check_sort_and_dub.c\
			ft_split.c\
			ft_get_num.c\
			ft_strlen.c\

BNS		=	checker.c\
			ft_strncmp.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			ft_atoi.c\
			ft_error_exit.c\
			ft_isdigit.c\
			ft_stack_utils.c\
			ft_swap.c\
			ft_rotate.c\
			ft_rev_rotate.c\
			ft_push.c\
			ft_check_sort_and_dub.c\
			ft_split.c\
			ft_get_num.c\

OBJ		=	$(SRC:.c=.o)
BOBJ	=	$(BNS:.c=.o)
HDR		= 	push_swap.h
CC		=	gcc
FLAGS 	=	-Wall -Wextra -Werror
RM		=	rm -f

$(NAME):	$(HDRS) $(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)

bonus:	$(BOBJ) $(HDR) get_next_line/get_next_line.h
		$(CC) $(FLAGS) $(BOBJ) -o ${NAME_B}

all: $(NAME)

clean:
		$(RM) $(OBJ) $(BOBJ)

fclean: clean
		$(RM) $(NAME) $(NAME_B)

re:      fclean all

.PHONY: all clean fclean bonus re