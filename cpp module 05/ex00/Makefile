NAME=a.out

COMPILE=c++ -Wall -Wextra -Werror -std=c++98


SRC=Bureaucrat.cpp main.cpp
OBJ=$(SRC:.cpp=.o)

%.o: %.cpp Bureaucrat.hpp
	$(COMPILE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
