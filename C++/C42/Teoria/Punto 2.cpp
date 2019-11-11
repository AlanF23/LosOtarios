#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	FILE *pfile, *pfile2;
	long lSize;
	char *buffer;
	size_t result;
	pfile=fopen("/home/usuario/Documentos/imagen.jpg", "rb");
	if(pfile==NULL)
	{
		fputs("Error abriendo la imagen", stderr);
		exit(1);
	}
	fseek (pfile, 0, SEEK_END);
	lSize = ftell (pfile);//obtiene el tamaño del archivo
	rewind (pfile);
	//asigna memoria para contener el archivo entero
	buffer = (char*) malloc (sizeof(char)* lSize);
	if(buffer==NULL)
	{
		fputs ("Error en memoria", stdout);
		exit(2);
	}
	//copia el archivo al buffer
	result = fread (buffer, 1, lSize, pfile);
	if(result != lSize)
	{
		fputs ("Error leyendo.", stdout);
		exit(3);
	}
	//el archivo entero esta cargado en la memoria
	//copia lo que hay en el buffer a un archivo nuevo
	pfile2 = fopen ("/home/usuario/Documentos/copia.jpg", "wb");
	if(pfile2==NULL)
	{
		fputs("Error abriendo", stdout);
		exit(1);
	}
	result = fwrite(buffer, lSize, 1, pfile2);
	if(result != 1)
	{
		fputs("Error grabando", stdout);
		exit(4);
	}
	//terminado
	fclose(pfile);
	fclose(pfile2);
	free(buffer);
	return 0;
}
