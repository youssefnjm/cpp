NAME=megaphone
CPP=c++
FLAGS=-Wall -Wextra -Werror -std=c++98

SRC=megaphone.cpp
OBJ=$(SRC:.cpp=.o)

%.o: %.cpp 
	$(CPP) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
