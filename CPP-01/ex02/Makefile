SRCS = main.cpp
OBJ = $(SRCS:.c=.o)
FLAG = -Wall -Wextra -Werror
NAME = Program

all:	$(NAME)
$(NAME): $(OBJ)
		clang++ $(FLAG) -o $(NAME) $(OBJ)