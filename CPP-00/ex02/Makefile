SRCS = Test.cpp Account.cpp
OBJ = $(SRCS:.c=.o)
FLAG = -Wall -Wextra -Werror
NAME = BanksAccount

all:	$(NAME)
.PHONY: clean fclean re 
$(NAME): $(OBJ)
		clang++ $(FLAG) -o $(NAME) $(OBJ)