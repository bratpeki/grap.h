
#include "./graph.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * Create the graph character array and return it
 *
 * '*x' and '*y' are arrays for X and Y point values
 * 'xlen' and 'ylen' are distances from their respective axes
 */

char* createGraph2D(int *x, int *y, unsigned int xlen, unsigned int ylen) {

	/* Setting grid dimensions */

	int gxlen = 2 * xlen + 1;
	int gylen = 2 * ylen + 1;

	/* Defining grid */

	char *grid = (char*)calloc(sizeof(char), gxlen*gylen);

	/*
	 * Drawing lines
	 *
	 * 'xmid' and 'ymid' are middle values (15/2 = 7.5 => 7)
	 *
	 * 'xq' and 'yq' are boolean-like values that determine weather on not
	 * the given value of 'i' is qualified to be on the x-axis or y-axis
	 */

	int xmid = gxlen / 2;
	int ymid = gylen / 2;

	int xq, yq;

	for (unsigned int i = 0; i < gxlen * gylen; i++) {

		xq = ( (i % gxlen) == xmid );
		yq = ( i >= gxlen * ymid ) && ( i < gxlen * (ymid + 1) );

		grid[i] =
			C_XAXIS      * ( xq * !yq) +
			C_YAXIS      * (!xq *  yq) +
			C_COORDBEGIN * ( xq *  yq) +
			C_EMPTY      * (!xq * !yq);

	}

	/* Return grid */

	return grid;

}

/*
 * Display the graph character array
 *
 * '*grid' respresents the graph character array
 * 'xlen' and 'ylen' serve the same purpose as in createGraph2D
 */

void drawGraph2D(char *grid, unsigned int xlen, unsigned int ylen) {

	int gxlen = 2 * xlen + 1;
	int gylen = 2 * ylen + 1;

	for (unsigned int j = 0; j < gxlen * gylen; j++) {
		if ( (j % gxlen == 0) * (j != 0) ) printf("\n");
		printf("%c", grid[j]);
	}
	printf("\n");

}

