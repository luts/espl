%.o: %.c
	gcc -c -o $@ $<

all: encbc

clean:
	rm -f *.o
encbc: encbc.o
	cc -o $@ $^ 
