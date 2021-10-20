
/*
 * Here we'll be defining all graph-drawing functions
 *
 * The character macros correspond to the following:
 *
 * C_XAXIS      - The x-axis (y = 0)
 * C_YAXIS      - The y-axis (x = 0)
 * C_COORDBEGIN - The coordinate origin (0, 0)
 * C_EMPTY      - A space with no points on it
 * C_POINT      - A space with a point
 *
 * createGraph2D -> Create the graph character array and return it
 * drawGraph2D   -> Display the graph character array
 */

#ifndef DRAW_GRAPH
#define DRAW_GRAPH

#define C_XAXIS      '|'
#define C_YAXIS      '-'
#define C_COORDBEGIN 'O'
#define C_EMPTY      '.'
#define C_POINT      '*'

typedef unsigned int uint;

char* createGraph2D(float *x, float *y, uint count, uint xlen, uint ylen);
void  drawGraph2D  (char *grid,                     uint xlen, uint ylen);

#endif

