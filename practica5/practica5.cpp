// practica5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma warning( disable : 4710)

#include "file.h"

int main()
{
	const unsigned int n = 100;
	char buffer[n];

	void * file1 = OpenFile("test.txt", "r");
	
	unsigned int readBytes = ReadFile(file1, buffer, n);
	printf("Bytes leidos: %d\n", readBytes);
	printf("Cadena leida: %.*s\n", readBytes, buffer);

	printf("Resultado de cerrar el fichero:%d\n", CloseFile(file1));

	file1 = OpenFile("test2.txt", "w");
	printf("Bytes escritos: %d\n", WriteFile(file1, buffer, readBytes));
	printf("Resultado de cerrar el fichero:%d\n", CloseFile(file1));

	getchar();
    return 0;
}

