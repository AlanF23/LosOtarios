/*Ejercicio 2.
Escribir un programa en lenguaje C que permita cargar un vector de N elementos
de tipo float, luego ingrese un número e informe si ese número está presente
en el vector y cuántas veces aparece.*/

#include <iostream>
#define N 10



using namespace std;

int main()
{
	float vec[N],x;
	float *pvec[N];
	int i,cont;
	cont = 0;

	for(i=0;i<N;i++)
	{
		cout<<"ingrese un valor: ";
		cin>>vec[i];
		pvec[i] = &vec[i];
	}
	cout<<'\n'<<"ingrese valor a verificar: ",
		cin>>x;
	for(i=0;i<N;i++)
	{
		if(vec[i]==x)
		{
			cont++;
		}
	}
	if(cont>0)
	{
		cout<<'\n'<<"El valor que se encuentra en el vector "<<cont<<" veces."<<endl;
	}
	cout<<endl;

	cout<<"Y ya que estamos"<<'\n'<<'\n';

	for(i=0;i<N;i++)
	{
		cout<<"Las posiciones del vector son: "<<pvec[i]<<endl;
	}

  return 0;
}
