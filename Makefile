build: main.o
	g++ -o cmpr main.o

main.o:
	g++ -c main.cpp

clean:
	rm -f main.o cmpr
