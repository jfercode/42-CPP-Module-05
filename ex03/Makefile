# Static library name
NAME		= ex03

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Directories and files
SRC			= source/Bureaucrat.cpp source/AForm.cpp main.cpp \
			  source/PresidentialPardonForm.cpp source/ShrubberyCreationForm.cpp \
			  source/RobotomyRequestForm.cpp source/Intern.cpp

OBJ			= $(SRC:.cpp=.o)

all:	$(NAME)
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re