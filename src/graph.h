
/*
 * Here we'll be defining all graph-drawing functions
 *
 * The character macros correspond to the following:
 *
 * C_XAXIS       -> The x-axis (y = 0)
 * C_YAXIS       -> The y-axis (x = 0)
 * C_COORDBEGIN  -> The coordinate origin (0, 0)
 * C_EMPTY       -> A space with no points on it
 * C_POINT       -> A space with a point
 *
 * f_abs         -> Return the absolute value of 'a'
 * f_round       -> Return the rounded value of 'a'
 *
 * createGraph2D -> Create the graph character array and return it
 * drawGraph2D   -> Display the graph character array
 */

#ifndef SRC_GRAPH
#define SRC_GRAPH

#define C_XAXIS      '|'
#define C_YAXIS      '-'
#define C_COORDBEGIN 'O'
#define C_EMPTY      '.'
#define C_POINT      'x'

#define f_abs(a)   ( (a) * (a >= 0) - (a) * (a < 0) )
#define f_round(a) ( (int)a * ( (a - (int)a) < 0.5 ) + (int)(a+1) * ((a - (int)a) >= 0.5) )

typedef unsigned int uint;

char* createGraph2D(float *x, float *y, uint count, uint xlen, uint ylen);
void  drawGraph2D  (char *grid,                     uint xlen, uint ylen);

#endif

