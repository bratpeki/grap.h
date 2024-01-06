
#include <stdio.h>
#include <stdlib.h>

#include "../src/grap.h"

#define count 100

int main() {

	double *x = calloc(sizeof(double), count);
	double *y = calloc(sizeof(double), count);

	if ( x == NULL || y == NULL ) {
		printf("Allocation failed\n");
		return EXIT_FAILURE;
	}

	int ind = 0;
	for (int i = -count/2; i < count/2; i++) {
		x[ind] = (double)i;
		y[ind] = (double)(i*i);
		ind++;
	}

	char *grid = graphCreate(x, y, count, 22, 12);
	if (grid == NULL) {
		printf("Couldn't allocate enough memory for the grid! Exiting...\n");
		return 1;
	}

	printf("Square function: y=x^2\n");
	graphDraw(grid, 22, 12);

	free(grid);
	free(x);
	free(y);

	return EXIT_SUCCESS;

}

