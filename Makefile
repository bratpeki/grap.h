
CC   =gcc -std=c99
LIN  =$(shell find -name *lin.c)
SQR  =$(shell find -name *sqr.c)
CUB  =$(shell find -name *cub.c)
GRAPH=$(shell find -name *graph.c)

all:
	@$(CC) -o lin $(LIN) $(GRAPH)
	@$(CC) -o sqr $(SQR) $(GRAPH)
	@$(CC) -o cub $(CUB) $(GRAPH)

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

