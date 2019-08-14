/*3) Cargar un arreglo con N números y luego, utilizando
punteros, determinar el menor elemento del arreglo.
Mostrar el menor, su posición en el arreglo y su
dirección en memoria.*/

#include <iostream>
#define N 5
using namespace std;

int main()
{
	int vec[N];
	int i,aux;
	int *pvec;

	for(i=0;i<N;i++)
	{
	cout<<"Ingrese una serie de numeros: ";
	cin>>vec[i];
	}

	cout<<endl;

	for(i=0;i<N;i++)
	{
		if (i==0)
		{
			aux=vec[i];
		}
		if (vec[i]<aux)
		{
			aux=vec[i];
		}
		pvec = &aux;
	}
	cout<<endl;
	cout<<"El menor es: "<<*pvec<<" con posicion: "<<pvec;
	return 0;
}
