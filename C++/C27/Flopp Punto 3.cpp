#include <iostream>

using namespace std;

int prod(int,int,int,int);

int main() 
{
	int x,y,z,q,a;
	
	cout<<"Ingrese 4 numeros: "<<endl;
	
	cin>>x;
	while (x==0)
	{
		cin>>x;
	}
	cin>>y;
	while (y==0)
	{
		cin>>y;
	}
	cin>>z;
	while (z==0)
	{
		cin>>z;
	}
	cin>>q;
	while (q==0)
	{
		cin>>q;
	}
	
	a = prod(x,y,z,q);
	
	cout<<endl;
	cout<<"El producto es: "<<a;
	return 0;
}
int prod(int s, int d, int f, int g)
{
	int l;
	
	l = (s*d*f*g);
	
	return (l);
}
