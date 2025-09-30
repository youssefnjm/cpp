GPP=c++
FLAGS=-Wall -Wextra -Werror -std=c++98

SRC=megaphone.cpp
OBJ=$(SRC:.cpp=.o)

%.o: %.cpp 
	$(GPP) $(FLAGS) -c $< -o $@

all: $(OBJ)
	$(GPP) $(FLAGS) $(OBJ) -o ex00

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ex00

re: fclean all
