
/*
 * Here we'll be defining all graph-drawing functions
 *
 * drawGraph2D -> The master drawing function, drawing a coordinate
 *                system and point on it, with variable precision
 */

#ifndef DRAW_GRAPH
#define DRAW_GRAPH

#define C_XAXIS      '|'
#define C_YAXIS      '-'
#define C_COORDBEGIN 'O'
#define C_EMPTY      '.'
#define C_POINT      '*'

char *createGraph2D(
		int *x, int *y,
		unsigned int xsize, unsigned int ysize,
		char* xlabel, char* ylabel
		);

void drawGraph2D(char *grid);

#endif

