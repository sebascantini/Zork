CC=g++
CFLAGS=-I.

DIR=src

_DEPS = character.h combat.h player.h enemy.h attack.h
DEPS = $(patsubst %,$(DIR)/%,$(_DEPS))

_OBJ = boot.o character.o combat.o player.o enemy.o attack.o
OBJ = $(patsubst %,$(DIR)/%,$(_OBJ))

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	rm -f $(DIR)/*.o *~

.PHONY: clean

clean:
	rm -f $(DIR)/*.o *~ core $(INCDIR)/*~