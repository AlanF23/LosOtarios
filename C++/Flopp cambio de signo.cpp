#include <iostream>
#define N 3

using namespace std;

void cambiar (int vec[], int);

int main() 
{
	int vec[N];
	int i;
	
	for (i=0;i<N;i++)
	{
		cin>>vec[i];
		cout<<endl;
	}
	
	cambiar(vec,N);
	
	for (i=0;i<N;i++)
	{
		cout<<vec[i]<<" ";
	}
	return 0;
}
void cambiar (int *v, int x)
{
	
	for (int i=0;i<x;i++)
	{
		*v=((*v)*(-1));
		v++;
	}
}
