a.out: main.o EnteroLargo.o
	g++ main.o EnteroLargo.o
	
EnteroLargo.o: EnteroLargo.cpp EnteroLargo.h
	g++ -c EnteroLargo.cpp
	
Entero820.o: Entero820.cpp Entero820.h
	g++ -c Entero820.cpp
	
main.o: main.cpp EnteroLargo.h
	g++ -c main.cpp

run: a.out
	./a.out < entrada.txt

run820: 820.out
	./820.out < entrada820.txt

clean:
	rm -rf *.o *.out