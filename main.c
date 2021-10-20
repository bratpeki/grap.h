
#include <stdio.h>
#include <stdlib.h>

#include "./src/graph.h"

#define xs 12
#define ys 6

int main() {

	/* TESTING SEQUENCE */

	int gxs = 2 * xs + 1;
	int gys = 2 * ys + 1;

	char *out = (char*)calloc(sizeof(char), gxs*gys);

	out = createGraph2D(0, 0, xs, ys, "x", "y");

	for (int i = 0; i < gxs*gys; i++) {
		if ( (i % gxs == 0) * ( i != 0 ) ) printf("\n");
		printf("%c", out[i]);
	}
	printf("\n");

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

