
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

	while (1) {

		printf("How many \"x\"'s will you need? ");
		scanf("%d", &count);

		if (count == 0) printf("You need an actual number of slots, dumbass. Try again.\n");
		if (count  < 0) count = -count;
		if (count  > 0) break;

	}

	x = (float*)calloc(sizeof(float), count);
	y = (float*)calloc(sizeof(float), count);

	for (uint _x = 0; _x < count; _x++) {
		printf("x[%u]: ", _x); scanf("%f", &t);
		x[_x] = t;
		y[_x] = k*t + n;
	}

	for (uint _y = 0; _y < count; _y++) {
		printf("%f\t%f\n", x[_y], y[_y]);
	}

	char *grid = createGraph2D(x, y, count, 40, 20);
	drawGraph2D(grid, 40, 20);
	free(grid);

	return 0;

}

