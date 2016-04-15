#/bin/bash

for (( c=8; c<=1073741824; c=c*2 ))
do 
	echo "Generando resultados con size=$c"
	./expEL.out $c $c >> resultados.txt
	python notification.py
done
