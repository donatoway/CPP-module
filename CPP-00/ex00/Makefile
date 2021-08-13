SRCS = megaphone.c++
OBJ = $(SRCS:.c=.o)
FLAG = -Wall -Wextra -Werror
NAME = megaphone

all:	$(NAME)
.PHONY: clean fclean re 
$(NAME): $(OBJ)
		clang++ $(FLAG) -o $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all