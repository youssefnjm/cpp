NAME=PhoneBook

GPP=c++

FLAGS=-Wall -Wextra -Werror -std=c++98

SRC=PhoneBook.cpp Contact.cpp main.cpp

OBJ=$(SRC:.cpp=.o)

%.o: %.cpp PhoneBook.hpp Contact.hpp
	$(GPP) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(GPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
