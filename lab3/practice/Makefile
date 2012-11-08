%.o: %.c
	gcc -c -o $@ $<
 
all: xsum
 
clean:
	rm -f *.o
 
xsum.o: xsum.c
	gcc -c -o xsum.o xsum.c

xsum: xsum.o 
	gcc -o xsum xsum.o 

