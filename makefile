CC = gcc

all: extractnumber.o postwykl.o power.o main.o
	$(CC) extractnumber.o postwykl.o power.o main.o -o test -lm

main.o: main.c extractnumber.h postwykl.h power.h
	$(CC) main.c -c -o main.o -lm

extractnumber.o: extractnumber.c extractnumber.h structures.h
	$(CC) extractnumber.c -c -o extractnumber.o -lm

postwykl.o: postwykl.c postwykl.h structures.h
	$(CC) postwykl.c -c -o postwykl.o -lm

power.o: power.c power.h structures.h
	$(CC) power.c -c -o power.o -lm

clean:
	rm -f *.o test







