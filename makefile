CC := g++
CFLAGS := -I.
NAME := run

SRC := src

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SOURCES := $(wildcard $(SRC)/*.cpp)
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))


%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)
	rm -f $(SRC)/*.o *~

.PHONY: clean

clean:
	rm -f $(NAME) $(SRC)/*.o *~ core $(INCDIR)/*~