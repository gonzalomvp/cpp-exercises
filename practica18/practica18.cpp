// practica18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "TList.h"
#include "IElement.h"
#include "TElement1.h"
#include "TElement2.h"

int main()
{

	TElement1 e1(100);
	TElement2 e2("Hola");
	TElement1 e3(200);
	TElement2 e4("Caracola");
	TList list1;

	list1.Push(&e1);
	list1.Push(&e2);
	list1.Push(&e3);
	list1.Push(&e4);

	list1.printList();

	list1.Pop()->PrintElement();
	list1.Pop()->PrintElement();

	list1.printList();

	TList list2 = list1;
	list1.Reset();

	list1.printList();
	list2.printList();

	getchar();
    return 0;
}

