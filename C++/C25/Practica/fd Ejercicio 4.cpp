/*Ejercicio 4.
Realice un programa en lenguaje C que permita cargar un vector de seis elementos
e intercambie las posiciones de sus elementos, de tal forma que el primer
elemento pase a ser el último y el último el primero, el segundo el penúltimo y
así sucesivamente, e imprima ese vector.*/

#include <iostream>
#define N 6

using namespace std;

int main()
{
	int vec1[N],vec2[N],i,j;
	int *p[N];

	for(i=0;i<N;i++)
	{
		cout<<"ingrese valor a ingresar: ";
		cin>>vec1[i];
		p[i] = &vec1[i];
	}

	cout<<'\n'<<"Los valores ingresados de vec[N] son: "<<'\n'<<endl;
	for(i=0;i<N;i++)
	{
		cout<<vec1[i]<<" con posicion de memoria: "<<p[i]<<endl;
	}

	cout<<'\n'<<"Ordenados al reves: "<<'\n'<<endl;

	//primero los ordeno
	for(i=0;i<N;i++)
	{
		for(j=N;j<2;j--)
		{
			vec2[i]=vec1[j];
		}
	}

	//ahora los muestro, pero imprime basura
	for(i=0;i<N;i++)
	{
		cout<<vec2[i]<<" con posicion de memoria: "<<p[i]<<endl;
	}

	return 0;
}
