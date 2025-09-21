GPP=g++
FLAGS=-Wall -Wextra -Werror -std=c++98

SRC=phonebook.cpp
OBJ=$(SRC:.cpp=.o)

%.o: %.cpp 
	$(GPP) $(FLAGS) -c $< -o $@

all: $(OBJ)
	$(GPP) $(FLAGS) $(OBJ) -o ex01

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ex01

re: fclean all
