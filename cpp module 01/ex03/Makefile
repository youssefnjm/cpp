NAME=violence
GPP=c++
FLAGS=-Wall -Wextra -Werror -std=c++98

SRC=main.cpp Weapon.cpp HumanB.cpp HumanA.cpp
OBJ=$(SRC:.cpp=.o)

%.o: %.cpp Weapon.hpp HumanB.hpp HumanA.hpp
	$(GPP) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(GPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
