all: add-nbo

add-nbo: my_htonl.o main.o
	g++ -o add-nbo my_htonl.o main.o

my_htonl.o: my_htonl.cpp my_htonl.h
	g++ -c -o my_htonl.o my_htonl.cpp

main.o: main.cpp my_htonl.h
	g++ -c -o main.o main.cpp

clean:
	rm -f add-nbo *.o