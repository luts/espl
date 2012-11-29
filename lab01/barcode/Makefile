CC=gcc
CFLAGS=-O -g

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: decbc encbc test

test: decbc encbc testbc
	./testbc
	if [ "`./encbc shalom olam|./decbc`" != "shalom olam" ]; then\
		exit 1;\
	fi

decbc: decbc.o bclib.o
	$(CC) $(CFLAGS) -o $@ $^

encbc: encbc.o bclib.o
	$(CC) $(CFLAGS) -o $@ $^

testbc: bclib.c
	$(CC) $(CFLAGS) -o $@ -DTESTBC=1 $^

decbc.o: decbc.c bclib.h
encbc.o: encbc.c bclib.h
bclib.o: bclib.c bclib.h

clean:
	rm -f *.o encbc decbc testbc
