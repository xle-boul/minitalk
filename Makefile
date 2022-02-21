SRCS_SVR = server.c utils.c
SRCS_CLT = client.c utils.c
SRCS_SVR_BONUS = bonus/server_bonus.c utils.c
SRCS_CLT_BONUS = bonus/client_bonus.c utils.c

OBJS_DIR = objs/
OBJS_DIR_BONUS = objs_bonus/

SRCS_SVR_OBJS = $(addprefix $(OBJS_DIR),$(SRCS_SVR:.c=.o))
SRCS_CLT_OBJS = $(addprefix $(OBJS_DIR),$(SRCS_CLT:.c=.o))
SRCS_SVR_BONUS_OBJS = $(addprefix $(OBJS_DIR_BONUS),server_bonus.o utils.o)
SRCS_CLT_BONUS_OBJS = $(addprefix $(OBJS_DIR_BONUS),client_bonus.o utils.o)

NAME_SVR = server
NAME_CLT = client
NAME_SVR_BONUS = server_bonus
NAME_CLT_BONUS = client_bonus

CC = gcc
FLAGS = -Werror -Wextra -Wall

all: $(OBJS_DIR) $(NAME_CLT) $(NAME_SVR)

$(OBJS_DIR):
	@$(CC) $(FLAGS) -c $(SRCS_CLT) $(SRCS_SVR)
	@mkdir -p $@
	@mv *.o $@

$(NAME_CLT):
	@$(CC) $(FLAGS) -o $@ $(SRCS_CLT_OBJS)
	@printf "\033[0;32mClient Compiled\n\e[0m"

$(NAME_SVR):
	@$(CC) $(FLAGS) -o $@ $(SRCS_SVR_OBJS)
	@printf "\033[0;32mServer Compiled\n\e[0m"

$(OBJS_DIR_BONUS):
	@$(CC) $(FLAGS) -c $(SRCS_CLT_BONUS) $(SRCS_SVR_BONUS)
	@mkdir -p $@
	@mv *.o $@

$(NAME_CLT_BONUS):
	@$(CC) $(FLAGS) -o $@ $(SRCS_CLT_BONUS_OBJS)
	@printf "\033[0;32mClient Bonus Compiled\n\e[0m"

$(NAME_SVR_BONUS):
	@$(CC) $(FLAGS) -o $(NAME_SVR_BONUS) $(SRCS_SVR_BONUS_OBJS)
	@printf "\033[0;32mServer Bonus Compiled\n\e[0m"
	
bonus: $(OBJS_DIR_BONUS) $(NAME_CLT_BONUS) $(NAME_SVR_BONUS)

clean:
	@rm -f $(NAME_CLT) $(NAME_CLT_BONUS) $(NAME_SVR) $(NAME_SVR_BONUS)

fclean:
	@rm -f $(NAME_CLT) $(NAME_CLT_BONUS) $(NAME_SVR) $(NAME_SVR_BONUS)
	@rm -rf $(OBJS_DIR)
	@rm -rf $(OBJS_DIR_BONUS)
	@printf "\033[0;31mDeleted Server/Bonus, Client/Bonus and Objects/Bonus\n\e[0m"

re: fclean all

bonus_re: fclean bonus

.PHONY: bonus clean fclean re bonus_re all
