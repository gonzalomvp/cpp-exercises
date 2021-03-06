// practica4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma warning( disable : 4668)

#include "stdio.h"
#include "windows.h"
#include "entity.h"
#include "consola.h"




// ***************************************************************************************
// MAIN
// ***************************************************************************************
int main()
{
	TEntity * tEntities[4];
	
	//Entity 1
	funcEntity tFuncs1[2] = { &draw1 , &move1 };
	tEntities[0] = new TEntity(tFuncs1, 0, 0);

	//Entity 2
	funcEntity tFuncs2[2] = { &draw2 , &move2 };
	tEntities[1] = new TEntity(tFuncs2, 0, 0);

	//Entity 3
	funcEntity tFuncs3[2] = { &draw3 , &move3 };
	tEntities[2] = new TEntity(tFuncs3, 0, 0);

	//Entity 4
	funcEntity tFuncs4[2] = { &draw4 , &move4 };
	tEntities[3] = new TEntity(tFuncs4, 0, 0);

	while (true)
	{
		clear();
		for (unsigned int i = 0; i < sizeof(tEntities)/sizeof(*tEntities); i++)
		{
			TEntity *entity = tEntities[i];
			funcEntity pDraw = entity->m_funcs[0];
			funcEntity pMove = entity->m_funcs[1];

			pDraw(entity);
			hidecursor();
			pMove(entity);
			hidecursor();
		}
		Sleep(100);
	}

	getchar();
}