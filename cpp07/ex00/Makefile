CC				=	c++

CPPFLAGS		=	-Wall -Wextra -Werror

SRC				=	main.cpp

OBJ				=	$(SRC:.cpp=.o)

NAME			=	templates

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all