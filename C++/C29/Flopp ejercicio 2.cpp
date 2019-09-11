#include <iostream>
#define N 3
using namespace std;

int main()
{
	int vec[N], men=0;
	int *v;
	int i;
	
	for (i=0;i<N;i++)
	{
		cout<<"Ingrese el elemento -->["<<i<<"] : ";
		cin>>vec[i];
	}
	
	v = &vec[0];
	
	for (i=0;i<N;i++)
	{
		if (i==0)
		{
			men = *v;
		}
		if (men>*v)
		{
			men = *v;
		}
		v++;
	}
	cout<<"\nEl menor es: "<<men<<endl;
	return 0;
}
