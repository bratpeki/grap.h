
#include <stdio.h>
#include <stdlib.h>

#include "./src/graph.h"

#define xs 8
#define ys 4

int main() {

	/* TESTING SEQUENCE */

	float *tx = (float*)calloc(sizeof(float), 3);
	float *ty = (float*)calloc(sizeof(float), 3);

	tx[0] = 1.0;
	tx[1] = 1.6;
	tx[2] = 0.5;

	ty[0] = 3.0;
	ty[1] = 3.3;
	ty[2] = 1.5;

	char *out = createGraph2D(tx, ty, 3, xs, ys);
	drawGraph2D(out, xs, ys);

	return 0;

	/* CODE CONTINUES HERE */

	int k, n, count, t;
	int *x;
	int *y;

	printf("Note: We're working with linear functions, meaning:\n\n\ty = k*x +n\n\n");

	printf("Insert \"k\" and \"n\", seperated by spaces: ");
	scanf("%d %d", &k, &n);

	while (1) {

		printf("How many \"x\"'s will you need? ");
		scanf("%d", &count);

		if (count == 0) printf("You need an actual number of slots, dumbass. Try again.\n");
		if (count  < 0) count = -count;
		if (count  > 0) break;

	}

	x = (int*)calloc(sizeof(int), count);
	y = (int*)calloc(sizeof(int), count);

	for (int _x = 0; _x < count; _x++) {
		printf("x[%d]: ", _x); scanf("%d", &t);
		x[_x] = t;
		y[_x] = k*t + n;
	}

	for (int _y = 0; _y < count; _y++) {
		printf("%d\t%d\n", x[_y], y[_y]);
	}

	return 0;

}

