#include <iostream>
#define N 3

using namespace std;

void cambio (int vec[],int);

int main()
{
	int vec[N], i;
	
	for (i=0;i<N;i++)
	{
		cout<<"Ingrese el elemento -->["<<i<<"] : ";
		cin>>vec[i];
	}
	
	cambio(vec,N);
	
	for (i=0;i<N;i++)
	{
		cout<<vec[i]<<" ";
	}
	return 0;
}
void cambio (int *v, int x)
{
	for (int i=0;i<x;i++)
	{
		*v = ((*v)*(-1));
		v++;
	}
}
