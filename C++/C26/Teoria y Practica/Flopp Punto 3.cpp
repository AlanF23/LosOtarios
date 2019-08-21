#include <iostream>
#define N 10
using namespace std;

void carga();
void muestra();
void ordena();
void muestraOrde();
int i;
int vec[N];

int main() 
{
	cout<<"carga el vector:"<<endl;
	
	carga();
	muestra();
	ordena();
	muestraOrde();
	
	return 0;
}

void carga ()
{
	for (i=0;i<N;i++)
	{
		cin>>vec[i];
	}
}
void muestra ()
{
	cout<<"El vector es: "<<endl;
	for (i=0;i<N;i++)
	{
		cout<<vec[i]<<" ";
	}
}
void ordena()
{
	int aux=0;
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
}
void muestraOrde ()
{
	cout<<endl;
	cout<<"El vector ordenado es: "<<endl;
	for (i=0;i<N;i++)
	{
		cout<<vec[i]<<" ";
	}
}
