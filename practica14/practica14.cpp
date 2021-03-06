// practica14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Jpg.h"
#include "Png.h"
#include "ImageUtils.h"

void PrintImageInfo(const CImagen &oImagen);

const unsigned int SIZE = 2;


int main()
{
	// Práctica Imagen
	CPng oPng;
	CJpg oJpg;

	oPng.SetPngFile("Fichero.png");
	oJpg.SetJpgFile("Fichero.jpg");

	PrintImageInfo(oPng);
	PrintImageInfo(oJpg);

	CImagen *imagenes[SIZE];
	imagenes[0] = &oPng;
	imagenes[1] = &oJpg;

	ImageUtils::removePNGsAlphaChannel(imagenes, SIZE);

	getchar();

	return 0;
}

// ***************************************************
//
// ***************************************************
void PrintImageInfo(const CImagen &oImagen)
{
	printf("NumPixes: %d \nSize: %d\n", oImagen.GetNumPixels(), oImagen.GetUncompressedSize());
}
