NAME = PmergeMe

SRC = main.cpp   PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)


CXX = c++ -fsanitize=address -g3
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean

re: fclean all