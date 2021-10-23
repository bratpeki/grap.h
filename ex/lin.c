
#include <stdio.h>
#include <stdlib.h>

#include "../src/include/graph.h"

#define K    -2
#define N     3

int main() {

	const int count = 100;
	double *x = (double*)calloc(sizeof(double), count);
	double *y = (double*)calloc(sizeof(double), count);

	int ind = 0;
	for (int i = -count/2; i < count/2; i++) {
		x[ind] = (double)i;
		y[ind] = (double)(K*i + N);
		ind++;
	}

	char *grid = createGraph2D(x, y, count, 22, 12);
	char name[40];

	sprintf(name, "A linear function of y = %d*x + (%d)", K, N);

	drawGraphInfo(x, y, count, name, "X values", "Y values");
	drawGraph2D(grid, 22, 12);

	free(grid);
	free(x);
	free(y);

	return 0;

}

