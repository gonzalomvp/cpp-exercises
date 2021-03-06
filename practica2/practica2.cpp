// practica2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#pragma warning( disable : 4710)

const int MIN_INT = -2147483647;
const unsigned char MIN_BYTE = 0x00;

int main()
{
	unsigned int i = 0xA4F012D4;
	unsigned char *p = reinterpret_cast<unsigned char *>(&i);
	unsigned char byte1 = *p;
	unsigned char byte2 = *(p + 1);
	unsigned char byte3 = *(p + 2);
	unsigned char byte4 = *(p + 3);

	printf("integer:%08X\n", i);
	printf("byte1:%02hhX\n", byte1);
	printf("byte2:%02hhX\n", byte2);
	printf("byte3:%02hhX\n", byte3);
	printf("byte4:%02hhX\n", byte4);

	int tabla[] = { 1, 3, 2, 5, 3, static_cast<int>(0xFFFFFFFF), 2 };

	int *pInt = tabla;
	int maxInt = MIN_INT;

	for (int index = 0; index < sizeof(tabla) / sizeof(*pInt); index++)
	{
		if (*(pInt + index) >= maxInt)
		{
			maxInt = *(pInt + index);
		}
	}
	printf("El mayor entero es: %d\n", maxInt);

	unsigned char *pChar = reinterpret_cast<unsigned char *>(tabla);
	unsigned char maxByte = MIN_BYTE;

	for (int index = 0; index < sizeof(tabla) / sizeof(*pChar); index++)
	{
		if (*(pChar + index) >= maxByte)
		{
			maxByte = *(pChar + index);
		}
	}
	printf("El mayor byte es: %02hhX\n", maxByte);

	//Invert string
	char cadena[] = "Hola Mundo";
	printf("%s\n", cadena);

	unsigned int j = 0;
	unsigned int k = strlen(cadena) - 1;

	while (j < k)
	{
		char aux;
		aux = *(cadena + j);
		*(cadena + j) = *(cadena + k);
		*(cadena + k) = aux;
		j++;
		k--;
	}
	printf("%s\n", cadena);

	getchar();
	return 0;
}

