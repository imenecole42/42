
NAME = push_swap

CC = gcc -g3

CFLAGS = -Wall -Werror -Wextra

SRC = A_is_sorted.c	\
	double.c	\
	main.c	\
	operation.c	\
	print.c	\
	radix_sort.c	\
	erreur.c	\
	tri.c	\

HEADER = pushswap.h

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

test3:
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Nombre d'opérations : "
	@./push_swap $(ARG) | wc -l

test5:
	$(eval ARG = $(shell shuf -i 0-5000 -n 5))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Nombre d'opérations : "
	@./push_swap $(ARG) | wc -l

test100:
	$(eval ARG = $(shell shuf -i 0-100 -n 100))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Nombre d'opérations : "
	@./push_swap $(ARG) | wc -l

stest6:
	$(eval ARG = $(shell shuf -i 0-5000 -n 6))
	./push_swap $(ARG)

stest500:
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker_linux $(ARG)

test258:
	$(eval ARG = $(shell shuf -i 0-5000 -n 258))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Nombre d'opérations : "
	@./push_swap $(ARG) | wc -l

test500:
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Nombre d'opérations : "
	@./push_swap $(ARG) | wc -l

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test3 test5 test500 stest6 stest500 test100
