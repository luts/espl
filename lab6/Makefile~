.PHONY: all clean


all: bfix bcmp

bfix: bfix.o bfixAS.o diff.o
	gcc -m32 -o bfix bfix.o bfixAS.o diff.o

bcmp: bcmp.o bcmpAS.o
	gcc -m32 -o bcmp bcmp.o bcmpAS.o

bfix.o: bfix.c diff.h
	gcc -m32 -c bfix.c

bfixAS.o: bfixAS.asm
	nasm -g -f elf bfixAS.asm

bcmp.o: bcmp.c
	gcc -m32 -c bcmp.c

bcmpAS.o: bcmpAS.asm
	nasm -g -f elf bcmpAS.asm


diff.o: diff.c diff.h
	gcc -m32 -c diff.c

clean:
	rm *.o