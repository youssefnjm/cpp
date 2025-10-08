NAME=PhoneBook 

CPP=c++ 

FLAGS=-Wall -Wextra -Werror -std=c++98 

SRC=PhoneBook.cpp Contact.cpp main.cpp

OBJ=$(SRC:.cpp=.o) 

%.o: %.cpp PhoneBook.hpp Contact.hpp 
	$(CPP) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
