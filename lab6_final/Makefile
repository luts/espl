.PHONY: all clean


all:  bcmp

bcmp: bcmpAS.o
	gcc -m32 -o bcmp bcmpAS.o


bcmpAS.o: bcmpAS.asm
	nasm -g -f elf bcmpAS.asm


clean:
	rm *.o