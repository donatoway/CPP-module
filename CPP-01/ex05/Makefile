SRCS = main.cpp karen.cpp
OBJ = $(SRCS:.c=.o)
NAME = Karen
FLAG = -Wall -Wextra -Werror

all:	$(NAME)
$(NAME): $(OBJ)
		clang++ $(FLAG) -o $(NAME) $(OBJ)