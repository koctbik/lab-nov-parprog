#include "description.h"

#include <stdio.h>
#include <stdlib.h>

#include "vtk.h"
#include "common.h"

#ifdef BLOOD
#include "blood.h"
#endif

#ifdef BRUSSELATOR
#include "brusselator.h"
#endif

#ifdef MORFOGENES
#include "morfogenes.h"
#endif


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
