
#include <stdio.h>
#include <stdlib.h>

#include "./src/graph.h"

int main() {

	uint count;

	float k, n, t;
	float *x;
	float *y;

	printf("Note: We're working with linear functions, meaning:\n\n\ty = k*x +n\n\n");

	printf("Insert \"k\" and \"n\", seperated by spaces: ");
	scanf("%f %f", &k, &n);

	printf("How many \"x\"'s will you need? ");
	scanf("%u", &count);

	x = (float*)calloc(sizeof(float), count);
	y = (float*)calloc(sizeof(float), count);

	for (uint _x = 0; _x < count; _x++) {
		printf("x[%u]: ", _x); scanf("%f", &t);
		x[_x] = t;
		y[_x] = k*t + n;
	}

	char *grid = createGraph2D(x, y, count, 18, 10);
	drawGraph2D(grid, 18, 10);
	free(grid);

	return 0;

}

