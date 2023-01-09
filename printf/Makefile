# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 14:22:55 by imraoui           #+#    #+#              #
#    Updated: 2022/06/06 15:53:55 by imraoui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##present :
##		@echo "\e[1;42m     PRINTF MAKER !    \e[0m"

SRC		= 	ft_printf.c \
	 		ft_printf_s.c \
			ft_printf_di.c \
			ft_printf_u.c \
			ft_printf_xp.c	 

OBJ		=	${SRC:.c=.o}

NAME	= 	libftprintf.a

CC 		= 	gcc

FLAGS 	= 	-Wall -Werror -Wextra

RM		=  rm -f

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o} 

all: 	$(NAME)

${NAME}:	${OBJ}
		ar rc ${NAME} ${OBJ}

clean:
		${RM} ${OBJ}

fclean:	clean
		${RM} ${NAME}

re: 		fclean all

.PHONY: 	all clean fclean re