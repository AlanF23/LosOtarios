#include <iostream>
#define N 3

using namespace std;

void carga(int [], int);
int suma(int [], int);
int main()
{
	int vec[N],i,a=0;
	
	carga(vec,N);
	cout<<endl;
	
	for (i=0;i<N;i++)
	{
		cout<<vec[i]<<" ";
	}
	
	a = suma (vec, N);
	cout<<endl;
	cout<<"\nLa suma de los digitos es: "<<a<<endl;
	return 0;
}
void carga (int vec2[], int x)
{
	for (int i=0;i<x;i++)
	{
		cout<<"Ingrese el elemento-->["<<i<<"] : ";
		cin>>vec2[i];
		cout<<endl;
	}
}
int suma (int vec2[], int x)
{
	int acu=0;
	
	for (int i=0;i<x;i++)
	{
		acu = acu +vec2[i];
	}
	return (acu);
}
