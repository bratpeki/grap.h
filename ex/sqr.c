
#include "../src/graph.h"

#include <stdlib.h>

int main() {

	const int count = 100;
	double *x = (double*)calloc(sizeof(double), count);
	double *y = (double*)calloc(sizeof(double), count);

	int ind = 0;
	for (int i = -count/2; i < count/2; i++) {
		x[ind] = (double)i;
		y[ind] = (double)(i*i);
		ind++;
	}

	char *grid = createGraph2D(x, y, count, 22, 12);

	drawGraphInfo(x, y, count, "Square function y=x^2", "X values", "Y values");
	drawGraph2D(grid, 22, 12);

	free(grid);
	free(x);
	free(y);

}

