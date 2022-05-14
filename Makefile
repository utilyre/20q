20q: main.o
	gcc -o 20q main.o

main.o: main.c
	gcc -c main.c

clean:
	rm -f *.o 20q
