#include <iostream>
#include <stdlib.h>
using namespace std;

void cargar();
void cargar2();
void mostrar();
void mostrar2();
void sumar();
int **pmat, **pmat2, **mat3;
int fil,col, fil2, col2;

int main() 
{
	cargar();
	cargar2();
	mostrar();
	sumar();
	mostrar2();
	
	for(int i=0;i<fil;i++)
	{
		free (pmat[i]);
	}
	free(pmat);
	
	for(int i=0;i<fil2;i++)
	{
		free (pmat2[i]);
	}
	free(pmat2);
	
	for(int i=0;i<fil;i++)
	{
		free (mat3[i]);
	}
	free(mat3);
	return 0;
}
void cargar()
{
	cout<<"Ingrese el numero de filas: ";
	cin>>fil;
	cout<<"\nIngrese el numero de columnas: ";
	cin>>col;
	cout<<endl;
	pmat=(int **) malloc (fil * sizeof(int *));
	for (int i=0;i<fil;i++)
	{
		pmat[i]=(int *) malloc (col *sizeof(int *));
	}
	cout<<"\nIngresa los elementos de la matriz: "<<endl;
	for (int i=0;i<fil;i++)
	{
		for (int j=0;j<col;j++)
		{
			cout<<"Ingrese el elemento -->["<<i<<"]["<<j<<"] : ";
			cin>>*(*(pmat+j)+i);
		}
	}
}
void cargar2()
{
	cout<<"Ingrese el numero de filas: ";
	cin>>fil2;
	cout<<"\nIngrese el numero de columnas: ";
	cin>>col2;
	cout<<endl;
	pmat2 = (int **) malloc (fil2 * sizeof(int *));
	for (int i=0;i<fil2;i++)
	{
		pmat2[i]=(int *) malloc (col2 *sizeof(int *));
	}
	cout<<"\nIngresa los elementos de la matriz: "<<endl;
	for (int i=0;i<fil2;i++)
	{
		for (int j=0;j<col2;j++)
		{
			cout<<"Ingrese el elemento -->["<<i<<"]["<<j<<"] : ";
			cin>>*(*(pmat2+j)+i);
		}
	}
}
void mostrar()
{
	cout<<"Mostrando las matrices. "<<endl;
	
	for(int i=0;i<fil;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<*(*(pmat+i)+j)<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int a=0;a<fil;a++)
	{
		for(int b=0;b<col;b++)
		{
			cout<<*(*(pmat2+a)+b)<<" ";
		}
		cout<<endl;
	}
}
void sumar ()
{
	mat3 = (int **) malloc (fil2 * sizeof(int *));
	for (int i=0;i<fil2;i++)
	{
		mat3[i]=(int *) malloc (col2 *sizeof(int *));
	}
	
	if(fil==fil2 && col==col2)
	{
		for(int i=0;i<fil;i++)
		{
			for(int j=0;j<col;j++)
			{
				*(*(mat3+i)+j)=(*(*(pmat+i)+j)+(*(*(pmat2+i)+j)));
			}
		}
	}
}
void mostrar2()
{
	cout<<"Mostrando las matrices. "<<endl;
	
	for(int i=0;i<fil;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<*(*(mat3+i)+j)<<" ";
		}
		cout<<endl;
	}
}
