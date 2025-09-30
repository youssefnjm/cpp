NAME=ex05
GPP=c++
FLAGS=-Wall -Wextra -Werror -std=c++98

SRC=main.cpp Harl.cpp
OBJ=$(SRC:.cpp=.o)

%.o: %.cpp Harl.hpp
	$(GPP) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(GPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
