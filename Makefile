# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbounor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 14:43:37 by lbounor           #+#    #+#              #
#    Updated: 2022/05/10 10:46:52 by lbounor          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c						\
		init_push_swap.c				\
		short_sort.c					\
		utils/ft_isdigit.c 				\
		utils/ft_atoi.c 				\
		utils/ft_strlen.c				\
		utils/ft_split.c				\
		utils/ft_putendl_fd.c			\
		utils/ft_strcmp.c				\
		utils/ft_lstadd_front.c			\
		utils/ft_lstsize.c				\
		utils/ft_lstlast.c				\
		utils/ft_lstnew.c				\
		utils/ft_lstadd_back.c			\
		utils/ft_substr.c				\
		utils/ft_lstclear.c				\
		operations/push.c				\
		operations/reverse_rotate.c		\
		operations/rotate.c				\
		operations/swap.c				\
		

OBJS = ${SRCS:.c=.o}

INCLUDES = push_swap.h

CC = gcc
RM = rm -f

FLAGS = -Wall -Wextra -Werror

all: ${NAME} 

$(NAME): ${OBJS}
	${CC} ${OBJS} -o ${NAME}
	
%.o: %.c ${INCLUDES}
	${CC} ${FLAGS} -I includes -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
         
.PHONY: all clean fclean re
