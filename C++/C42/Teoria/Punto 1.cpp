#include <iostream>
#include <stdlib.h>
#define BUFFER_TAMANIO 1024
#include <cstdio>

using namespace std;

FILE * origen, * destino;
int n;
int contador=0;
int escrito=0;

int main()
{
	unsigned char buffer[BUFFER_TAMANIO];
	origen = fopen("/home/usuario/Documentos/imagen.jpg", "rb");
	if(origen!=NULL)
	{
		destino=fopen("/home/usuario/Documentos/copia.jpg", "wb");
		while(!feof(origen))
		{
			n = fread(buffer, 1, BUFFER_TAMANIO, origen);
			contador += n;
			cout<<"--> "<<n<<endl;
			fwrite(buffer, 1, n, destino);
		}
		cout<<"Bytes leidos del archivo: "<<contador<<endl;
	}
	else
	{
		cout<<"Hubo un fallo."<<endl;
	}
	
	fclose(origen);
	fclose(destino);
	
	return 0;
}
