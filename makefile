CC=g++
CFLAGS=-I.

DIR=src

_DEPS = interface.h enemy.h player.h character.h combat.h weapon.h combatScheduler.h
DEPS = $(patsubst %,$(DIR)/%,$(_DEPS))

_OBJ = main.o interface.o enemy.o player.o character.o combat.o weapon.o combatScheduler.o
OBJ = $(patsubst %,$(DIR)/%,$(_OBJ))

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	rm -f $(DIR)/*.o *~

.PHONY: clean

clean:
	rm -f $(DIR)/*.o *~ core $(INCDIR)/*~