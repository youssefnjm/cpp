NAME=a.out

COMPILE=c++ -Wall -Wextra -Werror -std=c++98

SRC=AForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp main.cpp
OBJ=$(SRC:.cpp=.o)

%.o: %.cpp AForm.hpp Bureaucrat.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp
	$(COMPILE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
