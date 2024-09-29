CC				=	c++

CPPFLAGS		=	-Wall -Wextra -Werror #-fsanitize=address -g

SRC				=	main.cpp PmergeMe.cpp

OBJ				=	$(SRC:.cpp=.o)

NAME			=	PmergeMe

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all