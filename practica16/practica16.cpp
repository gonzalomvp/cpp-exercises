// practica16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CStream.h"
#include "CFile.h"
#include "CCom.h"
#include "CTcp.h"


int main()
{
	CStream* tablaStreams[3];

	CFile file;
	CCom ccom;
	CTcp ctcp;

	tablaStreams[0] = &file;
	tablaStreams[1] = &ccom;
	tablaStreams[2] = &ctcp;

	for (size_t i = 0; i < 3; i++)
	{
		CStream* pStream = tablaStreams[i];
		pStream->Open();
		pStream->Read();
		pStream->Write();
		pStream->Close();
	}

	getchar();
    return 0;
}

