# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imraoui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 11:56:34 by imraoui           #+#    #+#              #
#    Updated: 2022/11/07 11:56:36 by imraoui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY : all test testb lldb lldbb bonus norm clean fclean re

NAME := so_long.a
NAME_BONUS := so_long_bonus.a
SOFT_NAME := so_long
SOFT_BONUS := so_long_bonus

CC := gcc
FLAGS := -Wall -Wextra -Werror -I includes/
SRC_DIR := sources/
OBJ_DIR := objects/
AR := ar rc
RM := rm
VAL := valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
MLXFLAGS := -L libs/minilibx-linux/ -lmlx -lXext -lX11 -lz -lm

BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

SRCS = main.c	\
	check.c	\
	check_parsing.c\
	ft_free.c \
	ft_error.c \
	check_items.c\
	ft_backtacking.c\
	ft_mlx.c\
	ft_print_img.c\
	ft_move.c\
	free_mlx.c\


BONUS =

LIBFT := libs/libft.a
MLX := libs/minilibx-linux/libmlx_Linux.a
FCLIB := ${MAKE} fclean -C libs
CMLX := ${MAKE} clean -C libs/minilibx-linux

OBJS = $(SRCS:%.c=%.o)
BOBJS = $(BONUS:%.c=%.o)
NORM = $(wildcard *.c) $(wildcard *.h)

OBJ = $(addprefix $(OBJ_DIR),$(OBJS))
BOBJ = $(addprefix $(OBJ_DIR),$(BOBJS))

OBJF := .cache_exists

all : ${LIBFT} ${NAME} ${SOFT_NAME}

${LIBFT} :
	${MAKE} all -C libs/minilibx-linux
	${MAKE} all -C libs
	cp ${LIBFT} ${NAME}

${NAME} : ${OBJ}
	@echo "${BLUE}###${NC}Update de l'archive ${NAME}${BLUE}###${MAGENTA}"
	${AR} ${NAME} ${MLX} ${OBJ}
	@echo "${NC}"

${OBJ_DIR}%.o : %.c | $(OBJF)
	@echo "${BLUE}###${NC}Creation du fichier ${@:%.c=%.o}${BLUE}###${ORANGE}"
	${CC} ${FLAGS} ${MLXFLAGS} -c $< -o $@
	@echo "${NC}"

${SOFT_NAME} :
	@echo "${BLUE}###${NC}Creation du fichier ${SOFT_NAME}${BLUE}###${ORANGE}"
	${CC} ${NAME} ${FLAGS} ${MLXFLAGS} -o ${SOFT_NAME}
	@echo "${NC}"

$(OBJF) :
	@mkdir -p ${OBJ_DIR}

bonus : ${LIBFT} ${BOBJ} ${NAME_BONUS} ${SOFT_BONUS}

${NAME_BONUS} : ${BOBJ}
	@echo "${BLUE}###${NC}Update de l'archive ${NAME_BONUS}${BLUE}###${MAGENTA}"
	${AR} ${NAME_BONUS} ${MLX} ${BOBJ}
	@echo "${NC}"

${SOFT_BONUS} :
	@echo "${BLUE}###${NC}Creation du fichier ${SOFT_BONUS}${BLUE}###${ORANGE}"
	${CC} ${NAME_BONUS} ${LIBFT} ${FLAGS} ${MLXFLAGS} -o ${SOFT_BONUS}
	@echo "${NC}"

test : all
	${VAL} ./${SOFT_NAME} "maps/basic.ber"

testb : bonus
	${VAL} ./${SOFT_BONUS} "basic_bonus.ber"

lldb :
	${CC} -g3 ${SRCS} ${LIBFT} ${MLXFLAGS} -o ${SOFT_NAME}
	lldb ./${SOFT_NAME} "basic.ber"

lldbb :
	${CC} -g3 ${BONUS} ${LIBFT} ${MLXFLAGS} -o ${SOFT_BONUS}
	lldb ./${SOFT_BONUS} "basic.ber"

clean :
	${FCLIB}
	${CMLX}
	@echo "${RED}###${NC}Nettoyage des fichiers .o${RED}###"
	${RM} -rf ${OBJ_DIR}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

fclean : clean
	@echo "${RED}###${NC}Nettoyage d'archives et de Softs${RED}###"
	${RM} -f ${NAME} ${NAME_BONUS} ${SOFT_NAME} ${SOFT_BONUS}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

re : fclean all
