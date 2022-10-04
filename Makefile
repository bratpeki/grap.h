
CC=gcc -std=c99 -O2 -Wall -Wextra -Wpedantic
LIN=./ex/lin.c
SQR=./ex/sqr.c
CUB=./ex/cub.c
GRAPH=./src/graph.c

all:
	@make lin sqr cub

lin:
	@$(CC) -o lin $(LIN) $(GRAPH)

sqr:
	@$(CC) -o sqr $(SQR) $(GRAPH)

cub:
	@$(CC) -o cub $(CUB) $(GRAPH)

clean:
	@if [ -f lin ]; then rm lin; fi
	@if [ -f sqr ]; then rm sqr; fi
	@if [ -f cub ]; then rm cub; fi

