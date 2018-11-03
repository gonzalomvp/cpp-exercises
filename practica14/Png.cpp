#include "stdafx.h"
#include "Png.h"

// **************************************************************
//
// **************************************************************
CPng::CPng()
{
	type = Png;
}

// **************************************************************
//
// **************************************************************
int CPng::SetPngFile(const char *pszPngFile)
{
	printf("Lectura del fichero comprimido Png: %s\n", pszPngFile);
	UncompressImage();
	return 0;
}

// **************************************************************
//
// **************************************************************
int CPng::UncompressImage()
{
	printf("Descompresión de Imagen Png\n");
	m_uResX				= 480;
	m_uResY				= 320;
	m_uColorBytes	= 4;
	m_uSize				= m_uResX * m_uResY * m_uColorBytes;
	m_pBuffer			= new unsigned char[m_uSize];
	strcpy(reinterpret_cast<char *>(m_pBuffer), "Bytes del buffer descomprimido desde Png");
	return 0;
}

// **************************************************************
//
// **************************************************************
void CPng::RemoveAlphaChannel()
{
	printf("Eliminacion Canal Alpha\n");
}