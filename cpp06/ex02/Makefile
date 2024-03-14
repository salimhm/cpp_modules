CC				=	c++

CPPFLAGS		=	-Wall -Wextra -Werror

SRC				=	main.cpp Base.cpp A.cpp B.cpp C.cpp

OBJ				=	$(SRC:.cpp=.o)

NAME			=	polycast

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all