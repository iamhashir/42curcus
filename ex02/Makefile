NAME        = bureaucrat

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

SRCS        = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJ_DIR     = obj
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) Home_shrubbery

re: fclean all

.PHONY: all clean fclean re
