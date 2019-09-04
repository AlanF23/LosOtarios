#include <iostream>
using namespace std;

int res(int);

int main(int argc, char *argv[]) 
{
	int i,x,a;
	int cont=0;
	//int cont2=0;
	
	for (i=0;i<10;i++)
	{
		cin>>x;
		a = res(x);
		
		if (a!=0)
		{
			cont++;
		}
	}
	
	cout<<"La cantidad divisibles por 2 y 3 es de: "<<cont<<endl;
	
	return 0;
}
int res(int z)
{
	int D;
	if (z%2==0)
	{
		D++;
	}
	else
	{
		if(z%3==0)
		{
			
			D++;
		}
	}
	return (D);
}
