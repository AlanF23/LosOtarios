#include <iostream>
#include <stdlib.h>

using namespace std;

void cargar();
int mayor();
int fil,col;
int **mat;
int main()
{
	int a=0;
	
	cargar();
	
	for(int i=0;i<fil;i++)
	{
		for (int j=0;i<col;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	a=mayor();
	
	return 0;
}
void cargar ()
{
	cout<<"Ingrese el tamaño de la fila: ";
	cin>>fil;
	cout<<"\nIngrese el tamaño de la columna: ";
	cin>>col;
	cout<<endl;
	mat=(int **) malloc (fil * sizeof(int *));
	for (int i=0;i<fil;i++)
	{
		mat[i]=(int *) malloc (col *sizeof(int *));
	}
	cout<<"\nIngresa los elementos de la matriz: "<<endl;
	for (int i=0;i<fil;i++)
	{
		for (int j=0;j<col;j++)
		{
			cout<<"Ingrese el elemento -->["<<i<<"]["<<j<<"] : ";
			cin>>*(*(mat+j)+i);
		}
	}
}
int mayor()
{
	int aux=0;
	for (int i=0;i<fil;i++)
	{
		for (int j=0;j<col;j++)
		{
			if (i==0 &&j==0)
			{
				aux=(*(*(mat+i)+j));
			}
			if ((*(*(mat+i)+j))>aux)
			{
				aux=(*(*(mat+i)+j));
			}
		}
	}
	return (aux);
}
