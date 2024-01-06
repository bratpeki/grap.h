
#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

/*
 * The character macros correspond to the following:
 *
 * C_XAXIS       -> The x-axis (y = 0)
 * C_YAXIS       -> The y-axis (x = 0)
 * C_XAXISARROW  -> The x-axis' first line character, an arrow head
 * C_YAXISARROW  -> The y-axis' last line character, an arrow head
 * C_COORDBEGIN  -> The coordinate origin (0, 0)
 * C_EMPTY       -> A space with no points on it
 * C_POINT       -> A space with a point
 */

#define C_XAXIS      '|'
#define C_YAXIS      '-'
#define C_XAXISARROW '>'
#define C_YAXISARROW '^'
#define C_COORDBEGIN 'O'
#define C_EMPTY      '.'
#define C_POINT      'x'

/* Return the absolute value of 'a' */
#define ABS(a) ( (a) * (a >= 0) - (a) * (a < 0) )

/* Return the rounded value of 'a' */
#define ROUND(a) ( (int)a * ( (a - (int)a) < 0.5 ) + (int)(a+1) * ((a - (int)a) >= 0.5) )

/*
 * Create the graph character array and return it
 *
 * '*x' and '*y' are arrays for X and Y point values
 * 'xlen' and 'ylen' are distances from their respective axes
 *
 * So, along the x-axis, the graph will stretch from -xlen to +xlen.
 * The same logic applies to 'ylen'.
 */

char* graphCreate(double *x, double *y, unsigned int count, unsigned int xlen, unsigned int ylen) {

	/*
	 * Setting grid dimensions
	 *
	 * The addition of 1 is done to make space for the axis itself
	 */

	unsigned int gxlen = 2 * xlen + 1;
	unsigned int gylen = 2 * ylen + 1;

	/* Defining square grid for the graph */

	char* grid = (char*)calloc(gxlen*gylen, sizeof(char));

	/* If allocation fails, return NULL */

	if ( grid == NULL ) return NULL;

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

	unsigned int xmid = gxlen / 2;
	unsigned int ymid = gylen / 2;

	unsigned int xq, yq;
	unsigned int xa, ya;

	for (unsigned int i = 0; i < gxlen * gylen; i++) {

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

	double xmax = 0, ymax = 0;
	int xf, yf;

	for (unsigned int i = 0; i < count; i++) if ( ABS(x[i]) > xmax ) xmax = ABS(x[i]);
	for (unsigned int i = 0; i < count; i++) if ( ABS(y[i]) > ymax ) ymax = ABS(y[i]);

	for (unsigned int i = 0; i < count; i++) {

		xf = ROUND(( xlen * x[i] ) / xmax);
		yf = ROUND(( ylen * y[i] ) / ymax);

		/*    Middle point        Dist from origin        */
		grid[ ymid*gxlen + xlen - yf*gxlen + xf ] = C_POINT;

	}

	/* Return grid */

	return grid;

}

/*
 * Display the graph character array
 *
 * '*grid' respresents the graph character array
 * 'xlen' and 'ylen' serve the same purpose as in graphCreate
 */

void graphDraw(char* grid, unsigned int xlen, unsigned int ylen) {

	int gxlen = 2 * xlen + 1;
	int gylen = 2 * ylen + 1;

	for (int j = 0; j < gxlen * gylen; j++) {

		if ( (j % gxlen == 0) && (j != 0) ) printf("\n");
		printf("%c", grid[j]);

	}

	printf("\n");

}

#endif

