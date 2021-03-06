// practica15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class CBase
{
public:
	int m_i;

	CBase()
	{
		//Llamada a un metodo virtual desde el constructor
		printf("Llamada a un metodo virtual desde el constructor CBase\n");
		printVirtualTableAddress();
	}

	virtual void printVirtualTableAddress()
	{
		int **pVirtualTable = reinterpret_cast<int **>(this);
		printf("la tabla de funciones virtuales de CBase esta en: %08X\n", reinterpret_cast<int>(*pVirtualTable));

		//Si intento modificarla para ver donde esta situada me lanza una excepcion
		//**pVirtualTable = NULL;
	}
	
};

class CDerivada : public CBase
{
public:

	CDerivada()
	{
		//Llamada a un metodo virtual desde el constructor
		printf("Llamada a un metodo virtual desde el constructor CDerivada\n");
		printVirtualTableAddress();
	}

	virtual void printVirtualTableAddress()
	{
		int **pVirtualTable = reinterpret_cast<int **>(this);
		printf("la tabla de funciones virtuales de CDerivada esta en: %08X\n", reinterpret_cast<int>(*pVirtualTable));
	}
	virtual void foo()
	{

	}
	void foo2()
	{

	}
};

class CMyClass
{
public:
	int m_i;

	CMyClass(int i)
	{
		m_i = i;
	}

	void printVirtualTableAddress()
	{
		int **pVirtualTable = reinterpret_cast<int **>(this);
		//En realidad va a mostrar el valor de m_i ya que no tiene tabla de funciones virtuales
		printf("el valor de m_i de CMyClass es: %08X\n", reinterpret_cast<int>(*pVirtualTable));
	}
};


int main()
{
	
	CBase oBase;
	CDerivada oDerivada;
	CMyClass oMyClass(2);

	CBase *pBase = &oBase;
	CDerivada *pDerivada = &oDerivada;
	CMyClass *pMyClass = &oMyClass;

	// La tabla de funciones virtuales almacena punteros a las funciones virtuales de la clase
	// por tanto su tamaño será el tamaño del puntero multiplicado por el numero de funciones virtuales
	// ver pantallazo adjunto

	// La tabla de funciones virtuales esta en una zona de memoria de solo lectura ya que no se puede
	// escribir en ella
	pBase->printVirtualTableAddress();
	pDerivada->printVirtualTableAddress();
	pMyClass->printVirtualTableAddress();

	//Ocupa 4 bytes mas (el tamaño de puntero a la tabla de funciones virtuales)
	printf("Tamano objeto CBase: %d\n", sizeof(oBase));
	printf("Tamano objeto CDerivada: %d\n", sizeof(oDerivada));
	printf("Tamano objeto CMyClass: %d\n", sizeof(oMyClass));

	//Comparacion entre una llamada a funcion virtual y no virtual
	pDerivada->foo();
	pDerivada->foo2();

	getchar();
    return 0;
}

