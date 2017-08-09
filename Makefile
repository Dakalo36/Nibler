NAME = nibbler

MAKELIB = lib1.so

CORESRC = ./CoreSource/main.cpp\
		  ./CoreSource/Snake.cpp\
		  ./CoreSource/SnakePosition.cpp

LIB1SRC = ./Lib1Source/Gui.cpp

COREOBJ = $(CORESRC:%.cpp=%.o)

LIB1OBJ = $(LIB1SRC:%.cpp=%.o)

LIB		=	-lncurses

all:	$(NAME)

$(NAME): $(COREOBJ) $(MAKELIB)
	clang++ -Wall -Werror -Wextra -g3 -ldl -o $(NAME) $(COREOBJ) $(LIB) $(MAKELIB)

lib1: $(MAKELIB)

$(MAKELIB): $(LIB1OBJ)
	clang++ -fPIC -shared $(LIB1SRC) $(LIB) -o $(MAKELIB)

clean:
	rm -f $(NAME)
