SRCS = main.cpp zombie.cpp randomchump.cpp newZombie.cpp
OBJ = $(SRCS:.c=.o)
FLAG = -Wall -Wextra -Werror
NAME = Zombie

all:	$(NAME)
.PHONY: clean fclean re 
$(NAME): $(OBJ)
		clang++ $(FLAG) -o $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all