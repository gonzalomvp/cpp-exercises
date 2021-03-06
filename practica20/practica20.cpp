// practica20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <list>
#include <windows.h>
#include "entity.h"
#include "consola.h"

// ***************************************************************************************
// MAIN
// ***************************************************************************************
int main()
{
	std::list<TEntity*> entitiesList;

	while (true)
	{
		clear();

		//Si hay menos de 5 entidades genera las que faltan
		while (entitiesList.size() < 5) {
			entitiesList.push_back(new TEntity());
		}

		//Itera sobre los elementos de la lista
		std::list<TEntity*>::iterator itEntity = entitiesList.begin();
		while (itEntity != entitiesList.end()) {
			TEntity* entity = *itEntity;
			funcEntity pDraw = entity->m_funcs[0];
			funcEntity pMove = entity->m_funcs[1];
			
			pDraw(entity);
			hidecursor();
			pMove(entity);
			hidecursor();

			//decrementa la vida
			entity->m_life--;

			//si la vida llega a cero saca la entidad de la lista y libera memoria
			if (entity->m_life == 0) {
				itEntity = entitiesList.erase(itEntity);
				delete entity;
			}
			else {
				itEntity++;
			}
		}

		Sleep(100);
	}

	getchar();
}