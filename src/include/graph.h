
/*
 * Here we'll be defining all graph-drawing functions
 *
 * The character macros correspond to the following:
 *
 * C_XAXIS       -> The x-axis (y = 0)
 * C_YAXIS       -> The y-axis (x = 0)
 * C_XAXISARROW  -> The x-axis' first line character, an arrow head
 * C_YAXISARROW  -> The y-axis' last line character, an arrow head
 * C_COORDBEGIN  -> The coordinate origin (0, 0)
 * C_EMPTY       -> A space with no points on it
 * C_POINT       -> A space with a point
 *
 * f_abs         -> Return the absolute value of 'a'
 * f_round       -> Return the rounded value of 'a'
 *
 * createGraph2D -> Create the graph character array and return it
 * drawGraph2D   -> Display the graph character array
 * drawGraphInfo -> Display the graph information
 */

#ifndef GRAPH_H
#define GRAPH_H

#define C_XAXIS      '|'
#define C_YAXIS      '-'
#define C_XAXISARROW '>'
#define C_YAXISARROW '^'
#define C_COORDBEGIN 'O'
#define C_EMPTY      '.'
#define C_POINT      'x'

#define f_abs(a)   ( (a) * (a >= 0) - (a) * (a < 0) )
#define f_round(a) ( (int)a * ( (a - (int)a) < 0.5 ) + (int)(a+1) * ((a - (int)a) >= 0.5) )

char* createGraph2D(double *x, double *y, unsigned int count, unsigned int xlen, unsigned int ylen);
void  drawGraph2D  (char *grid, unsigned int xlen, unsigned int ylen);
void  drawGraphInfo(double *x, double *y, unsigned int count, char *name, char *xlabel, char *ylabel);

#endif

