SRCS = main.cpp Add.cpp Search.cpp
OBJ = $(SRCS:.c=.o)
FLAG = -Wall -Wextra -Werror
NAME = PhoneBook

all:	$(NAME)
.PHONY: clean fclean re 
$(NAME): $(OBJ)
		clang++ $(FLAG) -o $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all