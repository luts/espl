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

decbc: secret-elf-a secret-elf-c
	$(CC) -m32 $(CFLAGS) -o $@ $^

encbc: secret-elf-b secret-elf-c
	$(CC) -m32 $(CFLAGS) -o $@ $^

testbc: bclib.c
	$(CC) -m32 $(CFLAGS) -o $@ -DTESTBC=1 $^

secret-elf-a: decbc.c bclib.h
secret-elf-b: encbc.c bclib.h
secret-elf-c: bclib.c bclib.h

clean:
	rm -f *.o encbc decbc testbc
