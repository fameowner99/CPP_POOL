# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anesteru <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 21:58:01 by anesteru          #+#    #+#              #
#    Updated: 2018/07/01 23:31:29 by obamzuro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_gkrellm

SRC				=	main.cpp		IMonitorDisplay.cpp		IMonitorModule.cpp \
					shellUI.cpp		graphicalUI.cpp		HostnameUsernameModule.cpp \
					OSInfoModule.cpp	DateTimeModule.cpp	CPUInfoModule.cpp \
					RAMInfoModule.cpp	NetworkThroughputModule.cpp \
					DiskUsageModule.cpp Graphic.cpp	Point.cpp	Sdl.cpp

HEADERS			=	gkrellm.hpp		IMonitorDisplay.hpp		IMonitorModule.hpp \
					shellUI.hpp		graphicalUI.hpp 	HostnameUsernameModule.hpp \
					OSInfoModule.hpp	DateTimeModule.hpp	CPUInfoModule.hpp \
					RAMInfoModule.hpp	NetworkThroughputModule.hpp \
					DiskUsageModule.hpp Graphic.hpp	Point.hpp	Sdl.hpp

CC				=	clang++
FLAGS			=	-Wall -Wextra -Werror -std=c++98

LIBRARY			=	-framework SDL2 -F SDL_LIBRARY -rpath SDL_LIBRARY -framework SDL2_ttf
SDL_LIB			=	-I /Library/Frameworks/SDL2.framework/Headers
NCURSES_FLAG	=	-lncurses


OBJ				=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
INC				=	$(addprefix $(INC_DIR), $(HEADERS))

SRC_DIR			=	./src/
OBJ_DIR			=	./obj/
INC_DIR			=	./includes/

NC				=	\033[0m
BLUE			=	\033[3;36m

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(SDL_LIB) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	@$(CC) $(FLAGS)  $(NCURSES_FLAG) $(LIBRARY) -o $(NAME) $(OBJ) 
	@echo "${BLUE}$(NAME)${NC}  is ready"

clean:
	@rm -f $(OBJ)
	@echo  "$(OBJ) removed"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re
