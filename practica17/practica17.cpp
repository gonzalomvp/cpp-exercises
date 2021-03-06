// practica17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CStream.h"
#include "CFile.h"
#include "CCom.h"
#include "CTcp.h"
#include "CMyObserver.h"

int main()
{
	CFile file;
	CCom com;
	CTcp tcp;
	CStream *pStream;

	CMyObserver myObserver;
	IObserver *pObserver = &myObserver;

	pStream = &file;
	pStream->AsyncRead(pObserver);

	pStream = &com;
	pStream->AsyncRead(pObserver);

	pStream = &tcp;
	pStream->AsyncRead(pObserver);

	getchar();
    return 0;
}

