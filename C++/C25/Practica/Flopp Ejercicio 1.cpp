/*Ejercicio 1.
Escribir un programa en lenguaje C que permita cargar un vector de N elementos enteros,
los muestre, los ordene de menor a mayor y lo vuelva a mostrar. Utilizar cualquier método
de ordenamiento.*/

#include <iostream>
#define N 5
using namespace std;

int main()
{
	int i, aux=0;
	int vec[N];
	int *pvec[N];



	for (i=0;i<N;i++)
	{
		cout<<"Ingrese el elemento-->["<<i<<"]: ";
		cin>>vec[i];
		cout<<endl;
		pvec[i]=&vec[i];
	}

	for (i=0;i<N-1;i++)
	{
		if (vec[i] > vec[i+1])
		{
			aux = vec[i];
			vec[i] = vec[i+1];
			vec[i+1] = aux;
			i = -1;
		}
	}
	cout<<endl;

	for (i=0;i<N;i++)
	{
		cout<<*pvec[i]<<" "<<"con posicion-->"<<pvec[i]<<endl;
	}

	return 0;
}
