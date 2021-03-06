// practica12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "TList.h"
#include "ListUtils.h"

int main()
{
	TList list1;
	const char *string;
	list1.Push("cadena1");
	list1.Push("cadena2");

	printf("size: %d\n", list1.Size());

	string = list1.First();
	while (string) {
		printf("%s\n", string);
		string = list1.Next();
	}

	printf("Lista invertida\n");

	//	LLama dos veces al constructor de copia:
	//	1. Al hacer la copia del parametro que se le pasa a la funcion
	//	2. Al devolver por copia el valor de retorno de la funcion
	//TList invertedList = ListUtils::GetReverseList(list1);

	// De esta manera se evitan llamadas al constructor de copia y por tanto mejora el rendimiento.
	TList invertedList;
	ListUtils::GetReverseListEnhanced(list1, invertedList);


	printf("size: %d\n", invertedList.Size());

	string = invertedList.First();
	while (string) {
		printf("%s\n", string);
		string = invertedList.Next();
	}


	getchar();
    return 0;
}

