SRCS_SVR = server.c utils.c
SRCS_CLT = client.c utils.c
SRCS_SVR_BONUS = bonus/server_bonus.c utils.c
SRCS_CLT_BONUS = bonus/client_bonus.c utils.c

NAME_SVR = server
NAME_CLT = client
NAME_SVR_BONUS = server_bonus
NAME_CLT_BONUS = client_bonus

CC = gcc
FLAGS = -Werror -Wextra -Wall

$(NAME_SVR): $(NAME_CLT)
	@$(CC) -o $(NAME_SVR) $(FLAGS) $(SRCS_SVR) 
	@echo "Compiled $(NAME_SVR)"

$(NAME_SVR_BONUS): $(NAME_CLT_BONUS)
	@$(CC) -o $(NAME_SVR_BONUS) $(FLAGS) $(SRCS_SVR_BONUS)
	@echo "Compiled $(NAME_SVR_BONUS)"

$(NAME_CLT):
	@$(CC) -o $(NAME_CLT) $(FLAGS) $(SRCS_CLT)
	@echo "Compiled $(NAME_CLT)"

$(NAME_CLT_BONUS):
	@$(CC) -o $(NAME_CLT_BONUS) $(FLAGS) $(SRCS_CLT_BONUS)
	@echo "Compiled $(NAME_CLT_BONUS)"

all: $(NAME_SVR)

bonus: $(NAME_SVR_BONUS)

clean:
	@rm -f $(NAME_CLT) $(NAME_CLT_BONUS) $(NAME_SVR) $(NAME_SVR_BONUS)

fclean:
	@rm -f $(NAME_CLT) $(NAME_CLT_BONUS) $(NAME_SVR) $(NAME_SVR_BONUS)

re: fclean $(NAME_SVR)

bonus_re: fclean bonus

.PHONY: $(NAME_SVR) $(NAME_CLT) $(NAME_SVR_BONUS) $(NAME_CLT_BONUS) bonus clean fclean re bonus_re all
