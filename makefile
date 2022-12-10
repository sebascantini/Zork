CC := g++
CFLAGS := -Isrc/headers -lcurses `pkg-config --libs libbsd`
NAME := dark

SRC := src
HSRC := $(SRC)/headers
OBJ := bin

SOURCES := $(wildcard $(SRC)/*.cpp)
DEPS = $(wildcard $(HSRC)/*.h)
OBJECTS := $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SOURCES))

$(OBJ)/%.o: $(SRC)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)
	@ clear

.PHONY: clean test

clean:
	rm -f $(NAME) $(OBJ)/*.o *~ core $(INCDIR)/*~
