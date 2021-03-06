// practica10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma warning( disable : 4710)

#include "TList.h"

int main()
{
	TList list;
	const char *string;
	printf("size: %d\n", list.Size());
	list.Push("cadena1");
	list.Push("cadena2");
	list.Push("cadena3");
	
	printf("size: %d\n", list.Size());

	string = list.First();
	while (string) {
		printf("%s\n", string);
		string = list.Next();
	}

	list.Push("cadena4");
	printf("size: %d\n", list.Size());
	string = list.First();
	while (string) {
		printf("%s\n", string);
		string = list.Next();
	}
	printf("POP: %s\n", list.Pop());
	printf("size: %d\n", list.Size());
	string = list.First();
	while (string) {
		printf("%s\n", string);
		string = list.Next();
	}

	list.Reset();
	printf("size: %d\n", list.Size());
	string = list.First();
	while (string) {
		printf("%s\n", string);
		string = list.Next();
	}

	list.Push("cadena1");
	list.Push("cadena2");
	list.Push("cadena3");
	printf("size: %d\n", list.Size());
	string = list.First();
	while (string) {
		printf("%s\n", string);
		string = list.Next();
	}
	printf("POP: %s\n", list.Pop());
	printf("POP: %s\n", list.Pop());
	printf("size: %d\n", list.Size());
	string = list.First();
	while (string) {
		printf("%s\n", string);
		string = list.Next();
	}

	getchar();
    return 0;
}

