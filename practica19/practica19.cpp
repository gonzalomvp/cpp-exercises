// practica19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MEMORY_LEAKS_MONITOR
#include "leaks.h"


int main()
{
	int* pi = NEW_ARRAY int[3];
	double* pd = NEW double;
	//DELETE_ARRAY pi;
	DELETE pd;

	DUMP_UNFREED

	getchar();
    return 0;
}

