// practica6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma warning( disable : 4710)

#include "fileUtils.h"

int main()
{
	printf("%d\n", countStringsInFile("test.txt", "non"));
	printf("%d\n", sumIntsInFile("ints.txt"));
	getchar();
	return 0;
}
