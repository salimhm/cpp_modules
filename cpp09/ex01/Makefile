CC				=	c++

CPPFLAGS		=	-Wall -Wextra -Werror

SRC				=	main.cpp Rpn.cpp

OBJ				=	$(SRC:.cpp=.o)

NAME			=	RPN

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all