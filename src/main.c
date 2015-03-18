#include <stdio.h>
#include <stdlib.h>

#include "description.h"

#define ARGPAR 2

int main( int argc, char *argv[] )
{
	int isPar = 0;
	double *funcVect;
	if ( argc > 2 )
	{
		isPar = atoi( argv[ARGPAR]);
	}

	if ( !isPar )
	{
		sercalc();
	}
	else
	{
		parcalc();
	}


	return 0;
}
