CC := g++
CFLAGS := -Isrc/headers
NAME := run

SRC := src/
HSRC := $(SRC)/headers/
OBJ := bin/

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SOURCES := $(wildcard $(SRC)*.cpp)
DEPS = $(wildcard $(HSRC)*.h)
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJECTS := $(patsubst $(SRC)%.cpp,$(OBJ)%.o,$(SOURCES))


%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $(patsubst $(SRC)%,$(OBJ)%,$^) $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(NAME) $(OBJ)*.o *~ core $(INCDIR)/*~