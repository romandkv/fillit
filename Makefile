FLAGS = -Wall -Wextra -Werror
SRC = *.c
INC = -I .
LIB = -L libft/ -lft 

all :
	gcc  $(INC) $(SRC) $(LIB) -o fillit

clean :
	rm -rf fillit

re : clean all

