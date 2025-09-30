NAME=ex01
GPP=c++
FLAGS=-Wall -Wextra -Werror -std=c++98

SRC=main.cpp  zombieHorde.cpp Zombie.cpp
OBJ=$(SRC:.cpp=.o)

%.o: %.cpp Zombie.hpp
	$(GPP) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(GPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
