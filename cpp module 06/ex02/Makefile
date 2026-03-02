NAME=a.out

COMPILE=c++ -Wall -Wextra -Werror -std=c++98

SRC=Base.cpp main.cpp
OBJ=$(SRC:.cpp=.o)

%.o: %.cpp Base.hpp A.hpp B.hpp C.hpp
	$(COMPILE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
