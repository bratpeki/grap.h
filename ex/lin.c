
#include <stdio.h>
#include <stdlib.h>

#include "../src/include/graph.h"

#define K    -2
#define N     3
#define count 100

int main() {

	double *x = calloc(sizeof(double), count);
	double *y = calloc(sizeof(double), count);

	int ind = 0;
	for (int i = -count/2; i < count/2; i++) {
		x[ind] = (double)i;
		y[ind] = (double)(K*i + N);
		ind++;
	}

	char *grid = graphCreate(x, y, count, 22, 12);

	printf("A linear function of y = %d*x + (%d)\n", K, N);

	graphDraw(grid, 22, 12);

	free(grid);
	free(x);
	free(y);

	return 0;

}

