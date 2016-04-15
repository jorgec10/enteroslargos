a.out: main.o EnteroLargo.o
	g++ main.o EnteroLargo.o

820.out: main820.o EnteroLargo.o Entero820.o
	g++ main820.o EnteroLargo.o Entero820.o -o 820.out

val.out: validacion.o EnteroLargo.o Entero820.o
	g++ validacion.o EnteroLargo.o Entero820.o -o val.out

exp.out: experimento.o EnteroLargo.o Entero820.o
	g++ experimento.o EnteroLargo.o Entero820.o -o exp.out

expEL.out: experimentoEL.o EnteroLargo.o Entero820.o
	g++ experimentoEL.o EnteroLargo.o Entero820.o -o expEL.out
	
EnteroLargo.o: EnteroLargo.cpp EnteroLargo.h
	g++ -c EnteroLargo.cpp
	
Entero820.o: Entero820.cpp Entero820.h
	g++ -c Entero820.cpp
	
main.o: main.cpp EnteroLargo.h
	g++ -c main.cpp
	
main820.o: main820.cpp EnteroLargo.h Entero820.h
	g++ -c main820.cpp

val.o: validacion.cpp EnteroLargo.h Entero820.h
	g++ -c validacion.cpp

experimento.o: experimento.cpp EnteroLargo.h Entero820.h
	g++ -c experimento.cpp

experimentoEL.o: experimentoEL.cpp EnteroLargo.h Entero820.h
	g++ -c experimentoEL.cpp
	
run: a.out
	./a.out < entrada.txt

run820: 820.out
	./820.out < entrada820.txt > salida820.txt

runval: val.out
	./val.out < entrada820.txt
	
clean:
	rm -rf *.o *.out