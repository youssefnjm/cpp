GPP=g++
FLAGS=-Wall -Wextra -Werror -std=c++98

SRC=Account.cpp
OBJ=$(SRC:.cpp=.o)

%.o: %.cpp 
	$(GPP) $(FLAGS) -c $< -o $@

all: $(OBJ)
	$(GPP) $(FLAGS) $(OBJ) -o ex02

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ex02

re: fclean all
