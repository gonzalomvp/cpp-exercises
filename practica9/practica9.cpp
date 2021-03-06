// practica9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma warning( disable : 4710)

#include "TFile.h"


int main()
{
	const unsigned int n = 100;
	char buffer[n];
	unsigned int readBytes = 0;

	TFile file("test.txt");

	if (file.OpenFile("r") != TFile::FILE_ERROR) {
		readBytes = file.ReadFile(buffer, n);

		printf("Bytes leidos: %d\n", readBytes);
		printf("Cadena leida: %.*s\n", readBytes, buffer);

		printf("Resultado de cerrar el fichero:%d\n", file.CloseFile());
	}
	
	TFile file2("test2.txt");

	if (file2.OpenFile("w") != TFile::FILE_ERROR)
	{
		printf("Bytes escritos: %d\n", file2.WriteFile(buffer, readBytes));
		printf("Resultado de cerrar el fichero:%d\n", file2.CloseFile());
	}

	getchar();
    return 0;
}

