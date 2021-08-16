SRCS = main.cpp Zombie.cpp ZombieHorde.cpp
OBJ = $(SRCS:.c=.o)
FLAG = -Wall -Wextra -Werror
NAME = Zombie

all:	$(NAME)
$(NAME): $(OBJ)
		clang++ $(FLAG) -o $(NAME) $(OBJ)
