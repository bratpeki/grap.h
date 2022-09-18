
#include <stdio.h>
#include <stdlib.h>

#include "../src/include/graph.h"

int main() {

	const int count = 100;
	double *x = calloc(sizeof(double), count);
	double *y = calloc(sizeof(double), count);

	int ind = 0;
	for (int i = -count/2; i < count/2; i++) {
		x[ind] = (double)i;
		y[ind] = (double)(i*i*i);
		ind++;
	}

	char *grid = graphCreate(x, y, count, 22, 12);

	printf("Cube function y=x^3\n");
	graphDraw(grid, 22, 12);

	free(grid);
	free(x);
	free(y);

}

