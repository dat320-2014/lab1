#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
// TODO: #include "l1.c"

int main( int argc, char *argv[] )
{
    uint8_t debug = 0;
    int size = 8;
    double min = 0.0;
    double range = 100.0;
    int i;
    char *p;
    for ( i = 1; i < argc; i++ )
    {
        if ( !strcmp( argv[i], "-r" )) // range
        {
            range = strtod( argv[++i], &p );
	    if ( !range )
            {
                printf( "Argument to -r must be a positive number.\n" );
		exit(1);
            }
        }
	else if ( !strcmp( argv[i], "-m" )) // minimum
        {
            min = strtod( argv[++i], &p );
        }
	else if ( !strcmp( argv[i], "-s" )) // table size
        {
            size = strtod( argv[++i], &p );
        }
	else if ( !strcmp( argv[i], "-d" )) // debug
        {
            debug = -1;
            for ( i = 1; i < argc; i++ )
            {
                printf( "argv[%i]: \"%s\"\n", i, argv[i] );
            }
        }
    }
    double div = RAND_MAX / range;
    double table[size];

    if ( debug )
    {
        printf( "table size: %i\nminimum:    %.2f\nrange:      %.2f", size, min, range );
    }

    srand( time( NULL )); // seed random generator
    for ( i = size; i >= 0; i-- )
    {
        table[i] = min + ((double) rand()) / div;
    }

    double sum = 0.0; //TODO: tab_sort_sum( &table, size );

    /*
    int cell_width = 4; // TODO: log_2( max ) + 3
    char *formatstr[6];
    sprintf( formatstr, '%%%dd\n', cell_width ); // e.g. '%10d'
    const char *format[] = (const char *) formatstr;
    */
    const char format[] = "%8.2f\n";

    for ( i = 0; i < size; i++ ) // each row
    {
        printf( format, table[i] );
    }
    printf( "SUM: %f\n", sum );
    return 0;
}
