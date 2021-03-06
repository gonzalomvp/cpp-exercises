// practica1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "practica1.h"
#pragma warning( disable : 4710)

int main()
{
	//Personaje inicial con 200 balas y el modo de municion infinita desactivado
	unsigned int personaje = 0xABC8CDFD;

	printf("personaje inicial: %08X\n", personaje);
	printf("balas iniciales: %d\n", getBullets(personaje));

	//Se añaden 20 balas
	printf("el personaje ahora tiene %d balas\n", addBullets(personaje, 20));

	//Se añaden 40 balas
	printf("el personaje ahora tiene %d balas\n", addBullets(personaje, 40));

	printf("Municion infinita activa: %d\n", isInfiniteAmmoEnabled(personaje));

	//Se activa el modo balas infinitas
	enableInfiniteAmmo(personaje);
	printf("personaje con municion infinita: %08X\n", personaje);
	printf("Municion infinita activa: %d\n", isInfiniteAmmoEnabled(personaje));
	getchar();
	return 0;
}

unsigned int getBullets(unsigned int personaje)
{
	return (personaje & BULLETS_MASK) >> 16;
}

unsigned int addBullets(unsigned int &personaje, unsigned int bullets)
{
	unsigned int currentBullets = getBullets(personaje);
	unsigned int newBullets = currentBullets + bullets;
	if (newBullets > MAX_BULLETS)
	{
		newBullets = MAX_BULLETS;
	}
		
	personaje &= ~BULLETS_MASK;
	personaje |= newBullets << 16;

	return newBullets;
}

bool isInfiniteAmmoEnabled(unsigned int personaje)
{
	return personaje & INFINITE_AMMO_MASK;
}

void enableInfiniteAmmo(unsigned int &personaje)
{
	personaje |= INFINITE_AMMO_MASK;
}