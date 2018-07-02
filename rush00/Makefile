NAME = ft_retro

CC = clang++

FLAGS = -lncurses -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC = ClassBullet.cpp ClassEnemy.cpp ClassNcurses.cpp ClassObject.cpp ClassPlayer.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@ 
	@echo "ft_retro done."

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
