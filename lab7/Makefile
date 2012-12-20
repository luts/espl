%.o: %.c
	gcc -c -o $@ $<
 
all: bfix

bfix: bfix.o diff.o

bfix.o: bfix.c diff.h
diff.o: diff.c diff.h

clean:
	rm *.o
