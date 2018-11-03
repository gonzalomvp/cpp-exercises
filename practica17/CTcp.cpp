#include "stdafx.h"

#include "CTcp.h"
#include "windows.h"

int CTcp::Open()
{
	printf("CTcp Open()\n");
	return 0;
}

int CTcp::Close()
{
	printf("CTcp Close()\n");
	return 0;
}

int CTcp::Read()
{
	printf("CTcp Read()\n");
	return 0;
}

int CTcp::Write()
{
	printf("CTcp Write()\n");
	return 0;
}

void CTcp::AsyncRead(IObserver *pObserver)
{
	printf("Leyendo conexion TCP...\n");
	Sleep(7000);
	printf("conexion TCP leida\n");

	if (pObserver)
	{
		pObserver->onReadEnd();
	}
}
