
all:
	@gcc -o lin ./ex/lin.c ./src/graph.c
	@gcc -o sqr ./ex/sqr.c ./src/graph.c
	@gcc -o cub ./ex/cub.c ./src/graph.c

lin:
	@gcc -o lin ./ex/lin.c ./src/graph.c

sqr:
	@gcc -o sqr ./ex/sqr.c ./src/graph.c

cub:
	@gcc -o cub ./ex/cub.c ./src/graph.c

clean:
	@if [ -f lin ]; then rm lin; fi
	@if [ -f sqr ]; then rm sqr; fi
	@if [ -f cub ]; then rm cub; fi

