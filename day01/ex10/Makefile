NAME = cato9tails

CC = clang++

FLAGS = -Wall -Wextra -Werror 

RM = rm -f

SRC = main.cpp Cat.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@ 
	@echo "cato9tails done."

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
