#include <iostream>
#define N 3

using namespace std;

void carga (int[], int);
void verificar (int [], int);

int main() 
{
	int vec[N],i;
	carga (vec, N);
	for(i=0;i<N;i++)
	{
		cout<<vec[i]<<" ";
	}
	verificar(vec,N);
	return 0;
}
void carga (int vec2[], int x)
{
	for (int i=0;i<x;i++)
	{
		cout<<"Ingrese el elemento --> ["<<i<<"] : ";
		cin>>vec2[i];
		cout<<endl;
	}
}
void verificar (int vec2[], int x)
{
	if(vec2[0]>vec2[1] && vec2[1]>vec2[2])
	{
		cout<<"\n"<<"\nEsta ordenado"<<endl;
	}
}
