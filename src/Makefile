IDIR = ../include
CC=gcc
CFLAGS=-I$(IDIR)
ODIR=obj
LDIR = ../lib

LIBS=-lcrypto

_DEPS= defines.h params.h functions.h randombytes.h matrix_size.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = kks.o randombytes.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

kks: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o kks
