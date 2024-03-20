CC				=	c++

CPPFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC				=	main.cpp

OBJ				=	$(SRC:.cpp=.o)

NAME			=	easyFind

all:			$(NAME)

%.o: %.cpp *.hpp
				$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME):		$(OBJ)
				$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME)


clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all