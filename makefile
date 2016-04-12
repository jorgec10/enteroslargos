a.out: main.o EnteroLargo.o
	g++ main.o EnteroLargo.o
	
EnteroLargo.o: EnteroLargo.cpp EnteroLargo.h
	g++ -c EnteroLargo.cpp
	
main.o: main.cpp EnteroLargo.h
	g++ -c main.cpp

run: a.out
	./a.out < entrada.txt

clean:
	rm -rf *.o *.out