
#ifndef GRAPH_H
#define GRAPH_H

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

// Return the absolute value of 'a'
#define f_abs(a) ( (a) * (a >= 0) - (a) * (a < 0) )

// Return the rounded value of 'a'
#define f_round(a) ( (int)a * ( (a - (int)a) < 0.5 ) + (int)(a+1) * ((a - (int)a) >= 0.5) )

/*
 * Create the graph character array and return it
 *
 * '*x' and '*y' are arrays for X and Y point values
 * 'xlen' and 'ylen' are distances from their respective axes
 *
 * So, along the x-axis, the graph will stretch from -xlen to +xlen.
 * The same logic applies to 'ylen'.
 */

char* graphCreate(double *x, double *y, unsigned int count, unsigned int xlen, unsigned int ylen);

/*
 * Display the graph character array
 *
 * '*grid' respresents the graph character array
 * 'xlen' and 'ylen' serve the same purpose as in graphCreate
 */

void graphDraw(char *grid, unsigned int xlen, unsigned int ylen);

/*
 * Display the graph information
 *
 * 'x' and 'y' are value arrays used to make a value table
 * 'name', 'xlabel' and 'ylabel' are self-explanatory
 */

void graphDrawInfo(double *x, double *y, unsigned int count, char *name, char *xlabel, char *ylabel);

#endif

