void main(int argc, char *argv[])
{
	uint8_t debug = 0;
	int size = 8;

	double min = 0.0;
	double range = 100.0;
	int i;
	char *p;
	for ( i = 1; i < argc; i++ )
	{
        	if ( !strcmp( argv[i], "-r" ))
	 	{
	        	range = strtod( argv[++i], &p );
	        if ( !range) 
		    {
			    printf("Argument to -r must be a positive number.\n");
		exit(1);
		    }
		}
	else if (!strcmp(argv[i], "-m"))
		{
			min = strtod(argv[++i], &p);
		}
	else if (!strcmp(argv[++i], &p);
		{	
			size = strtod(argv[++i], &p);
		}
	else if (!strcmp(argv[i], "-d")) 
		{
			debug = -1;
			for (i = 1; i < argc; i++)
			{
				printf( "argv[%i]: \"%s\"\n", i, argv[i]);
			}
		}
	}
	double div = RAND_MAX / range;
	double table[size];

	if (debug)
	{
		printf( "table size: %i\nminimum:	%.2f\nrange:	%.2f", size, min, range);
	}
	srand( time( NULL ));
	for ( i = size; i >= 0; i-- )
	{
		table[i] = min + ((double) rand()) / div;
	}

	double sum = 0.0;
	
	const char format[] = "8.2f\n";

	for (i=0; i<size; i++)
	{
		printf(format, table[i]);
	}
	printf("SUM: %f\n", sum);
	return 0;
}









