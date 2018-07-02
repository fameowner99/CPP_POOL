NAME = whatever

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98 

RM = rm -f

SRC = whatever.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@ 
	@echo "whatever done."

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
