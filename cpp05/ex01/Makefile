CC			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror

SRC			=	main.cpp Bureaucrat.cpp Form.cpp

OBJ			=	$(SRC:.cpp=.o)

NAME		=	Bureaucrat

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean all