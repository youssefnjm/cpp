NAME=a.out

COMPILE=c++ -Wall -Wextra -Werror -std=c++98


SRC=main.cpp AMateria.cpp Character.cpp Cure.cpp ICharacter.cpp IMateriaSource.cpp Ice.cpp MateriaSource.cpp List.cpp
OBJ=$(SRC:.cpp=.o)

%.o: %.cpp AMateria.hpp Character.hpp Cure.hpp ICharacter.hpp IMateriaSource.hpp Ice.hpp MateriaSource.hpp List.hpp
	$(COMPILE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
