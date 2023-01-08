
CC := g++
CFLAGS := -lcurses 
NAME := run

SRC := src
OBJ := bin

SOURCES := $(wildcard $(SRC)/*.cpp $(SRC)/*/*.cpp $(SRC)/*/*/*.cpp)
DEPS = $(wildcard $(SRC)/*.h $(SRC)/*/*.h $(SRC)/*/*/*.h)
OBJECTS := $(patsubst notdir %.cpp,$(OBJ)/%.o,$(SOURCES))

$(OBJ)/%.o: $(SRC)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)
	@ clear

.PHONY: clean test

clean:
	rm -f $(NAME) $(OBJ)/*.o *~ core $(INCDIR)/*~
