SRCS_SVR = server.c utils.c
SRCS_CLT = client.c utils.c

NAME_SVR = server
NAME_CLT = client

CC = gcc
FLAGS = -Werror -Wextra -Wall

$(NAME_SVR): $(NAME_CLT)
	@$(CC) -o $(NAME_SVR) $(FLAGS) $(SRCS_SVR) 
	@echo "Compiled $(NAME_SVR)"

$(NAME_CLT):
	@$(CC) -o $(NAME_CLT) $(FLAGS) $(SRCS_CLT)
	@echo "Compiled $(NAME_CLT)"

all: $(NAME_SRV)

clean:
	@rm client server

fclean:
	@rm client server

re: fclean $(NAME_SVR)

.PHONY: $(NAME_SVR) $(NAME_CLT) clean fclean re all
