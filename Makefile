# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbounor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 14:43:37 by lbounor           #+#    #+#              #
#    Updated: 2022/05/09 14:43:39 by lbounor          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c						\
		push_swap_utils.c				\
		push_swap_short.c				\
		libft/ft_isdigit.c 				\
		libft/ft_strlen.c				\
		libft/ft_strchr.c				\
		libft/ft_atol.c					\
		libft/ft_split.c				\
		libft/ft_putchar_fd.c			\
		libft/ft_putstr_fd.c			\
		libft/ft_putendl_fd.c			\
		libft/ft_putnbr_fd.c			\
		libft/ft_strcmp.c				\
		libft/ft_lstnew.c				\
		libft/ft_lstadd_front.c			\
		libft/ft_lstsize.c				\
		libft/ft_lstlast.c				\
		libft/ft_lstadd_back.c			\
		libft/ft_substr.c				\
		libft/ft_lstclear.c				\
		libft/ft_lstindex_val.c			\
		operations/ft_push.c			\
		operations/ft_reverse_rotate.c	\
		operations/ft_rotate.c			\
		operations/ft_swap.c			\
		

OBJS = ${SRCS:.c=.o}

INCLUDES = push_swap.h					\
		libft/libft.h					\
		operations//operations.h		\

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
