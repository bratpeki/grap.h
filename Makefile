
CC   =gcc -std=c99 -O2 -Wall -Wextra -Wpedantic
LIN  =./ex/lin.c
SQR  =./ex/sqr.c
CUB  =./ex/cub.c

all:
	@$(CC) -o lin $(LIN)
	@$(CC) -o sqr $(SQR)
	@$(CC) -o cub $(CUB)

lin:
	@$(CC) -o lin $(LIN)

sqr:
	@$(CC) -o sqr $(SQR)

cub:
	@$(CC) -o cub $(CUB)

clean:
	@if [ -f lin ]; then rm lin; fi
	@if [ -f sqr ]; then rm sqr; fi
	@if [ -f cub ]; then rm cub; fi

