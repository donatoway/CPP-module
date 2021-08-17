SRCS = main.cpp HumanA.cpp Weapon.cpp
OBJ = $(SRCS:.c=.o)
FLAG = -Wall -Wextra -Werror
NAME = War

all:	$(NAME)
$(NAME): $(OBJ)
		clang++ $(FLAG) -o $(NAME) $(OBJ)