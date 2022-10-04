
#include "./include/graph.h"

char* graphCreate(double *x, double *y, unsigned int count, unsigned int xlen, unsigned int ylen) {

	/*
	 * Setting grid dimensions
	 *
	 * The addition of 1 is done to make space for the axis itself
	 */

	int gxlen = 2 * xlen + 1;
	int gylen = 2 * ylen + 1;

	/* Defining square grid for the graph */

	char* grid = calloc(sizeof(char), gxlen*gylen);

	/*
	 * Drawing lines
	 *
	 * 'xmid' and 'ymid' are middle values (15/2 = 7.5 => 7)
	 *
	 * 'xq' and 'yq' are boolean-like values that determine weather or not
	 * the given value of 'i' is qualified to be on the x-axis or y-axis
	 *
	 * 'xa' and 'ya' are similar to 'xq' and 'yq', with the difference being
	 * that they determine if the given value of 'i' is the end of an axis where
	 * an arrow will be drawn
	 */

	int xmid = gxlen / 2;
	int ymid = gylen / 2;

	int xq, yq;
	int xa, ya;

	for (int i = 0; i < gxlen * gylen; i++) {

		xq = ( (i % gxlen) == xmid );
		yq = ( i >= gxlen * ymid ) && ( i < gxlen * (ymid + 1) );

		ya = ( i == xlen );
		xa = ( i == (ylen+1)*gxlen - 1 );

		grid[i] =
			C_XAXIS      * ( xq * !yq * !ya) +
			C_YAXIS      * (!xq *  yq * !xa) +
			C_XAXISARROW * (!xq *  yq *  xa) +
			C_YAXISARROW * ( xq * !yq *  ya) +
			C_COORDBEGIN * ( xq *  yq) +
			C_EMPTY      * (!xq * !yq);

	}

	/*
	 * Drawing points
	 *
	 * The procedure for each axis is:
	 *
	 *     Find the maximum absolute value
	 *     Use the following formula to find the position of the point on the graph:
	 *         graph_size : max_axis_value = graph_position : axis_value
	 *         graph_position * max_axis_value = graph_size * axis_value
	 *         graph_position = ( graph_size * axis_value ) / max_axis_value
	 *     Draw points
	 */

	/* Finding x and y coordinate absolute maximums */

	double xmax, ymax = 0;
	int xf, yf;

	for (int i = 0; i < count; i++) if ( ABS(x[i]) > xmax ) xmax = ABS(x[i]);
	for (int i = 0; i < count; i++) if ( ABS(y[i]) > ymax ) ymax = ABS(y[i]);

	for (int i = 0; i < count; i++) {

		xf = ROUND(( xlen * x[i] ) / xmax);
		yf = ROUND(( ylen * y[i] ) / ymax);

		/*    Middle point        Dist from origin        */
		grid[ ymid*gxlen + xlen - yf*gxlen + xf ] = C_POINT;

	}

	/* Return grid */

	return grid;

}

void graphDraw(char* grid, unsigned int xlen, unsigned int ylen) {

	int gxlen = 2 * xlen + 1;
	int gylen = 2 * ylen + 1;

	for (int j = 0; j < gxlen * gylen; j++) {

		if ( (j % gxlen == 0) * (j != 0) ) printf("\n");
		printf("%c", grid[j]);

	}

	printf("\n");

}

