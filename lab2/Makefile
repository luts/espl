%.o: %.c
	gcc -c -o $@ $<
 
all: canalyze
 
clean:
	rm -f *.o
 
canalyze.o: canalyze.c fgetname.h namelist.h
	gcc -c -o canalyze.o canalyze.c

canalyze: canalyze.o fgetname.o namelist.o
	gcc -o canalyze canalyze.o fgetname.o namelist.o

fgetname.o: fgetname.c fgetname.h 
	gcc -c -o fgetname.o fgetname.c

namelist.o: namelist.c namelist.h 
	gcc -c -o namelist.o namelist.c
