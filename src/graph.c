
#include "./graph.h"

#include <stdio.h>
#include <stdlib.h>

char *createGraph2D(
		int *x, int *y,
		unsigned int xsize, unsigned int ysize,
		char* xlabel, char* ylabel
		) {

	/* Setting grid dimensions */

	int gxsize = 2 * xsize + 1;
	int gysize = 2 * ysize + 1;

	/* Defining grid */

	char *grid = (char*)calloc(sizeof(char), gxsize*gysize);

	/*
	 * Drawing lines
	 *
	 * 'xmid' and 'ymid' are middle values (15/2 = 7.5 => 7)
	 *
	 * 'xq' and 'yq' are boolean-like values that determine weather on not
	 * the given value of 'i' is qualified to be on the x-axis or y-axis
	 */

	int xmid = gxsize/2;
	int ymid = gysize/2;

	int xq, yq;

	for (unsigned int i = 0; i < gxsize*gysize; i++) {

		xq = ( (i % gxsize) == xmid );
		yq = ( i >= gxsize*(ymid) ) && ( i < gxsize*(ymid+1) );

		grid[i] =
			C_XAXIS      * ( xq * !yq) +
			C_YAXIS      * (!xq *  yq) +
			C_COORDBEGIN * ( xq *  yq) +
			C_EMPTY      * (!xq * !yq);

	}

	/* Return grid */

	return grid;

}

