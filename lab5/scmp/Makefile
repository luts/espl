.PHONY: all clean


all: scmp

scmp: scmp.o cmpstr.o
	gcc -m32 -o scmp scmp.o cmpstr.o

scmp.o: scmp.c
	gcc -m32 -c scmp.c

cmpstr.o: cmpstr.asm
	nasm -g -f elf cmpstr.asm



