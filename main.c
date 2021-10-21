
#include <stdio.h>
#include <stdlib.h>

#include "./src/graph.h"

#define K    -2
#define N     3
#define COUNT 5

int main() {

	double *x = (double*)calloc(sizeof(double), COUNT);
	double *y = (double*)calloc(sizeof(double), COUNT);

	for (int t = 0; t < COUNT; t++) {
		x[t] = t;
		y[t] = K*t + N;
	}

	char *grid = createGraph2D(x, y, COUNT, 18, 10);

	drawGraphInfo(x, y, COUNT, "A linear function", "X values", "Y values");
	drawGraph2D(grid, 18, 10);

	free(grid);
	free(x);
	free(y);

	return 0;

}

