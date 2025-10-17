NAME=a.out

COMPILE=c++ -Wall -Wextra -Werror -std=c++98

SRC=main.cpp ClapTrap.cpp 
OBJ=$(SRC:.cpp=.o)

%.o: %.cpp ClapTrap.hpp
	$(COMPILE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
