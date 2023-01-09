# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omechri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 15:49:26 by omechri           #+#    #+#              #
#    Updated: 2022/06/13 16:01:24 by omechri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = minishell
LIBS            = ./libft/libft.a
HEADER          = minishell.h
CC              = gcc
FLAGS           = -Wall -Werror -Wextra -lreadline
CFLAGS          = -g3 
RM                      = rm -f
SRCS            =  main.c list.c env_utils.c echo.c cd.c pwd.c export.c unset.c env.c utils.c  pipe_utils.c  pipe.c expansion.c exit.c heredoc.c command.c parser.c expansion_utils.c  parser_handler.c parse_in_out.c  tokens.c parser_utils.c  list_status.c  execution.c
OBJS            = ${SRCS:.c=.o}

%.o : %.c ${HEADER}
	${CC} ${FLAGS} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	$(MAKE) -C libft
	cp libft/libft.a ${NAME}
	$(CC) -o $(NAME) $(OBJS) $(FLAGS) $(LIBS)

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	${RM} ${OBJS}

fclean: clean
	$(MAKE) fclean -C ./libft
	${RM} ${NAME}

re:     fclean all


.PHONY : all clean fclean re


