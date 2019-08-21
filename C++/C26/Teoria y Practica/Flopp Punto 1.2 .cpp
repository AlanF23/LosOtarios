#include <iostream>
using namespace std;

void Mayor(int,int,int);

int main() 
{
	int a,b,c;
		
	cout<<"Ingrese a: ";
	cin>>a;
	cout<<endl;
	cout<<"Ingrese b: ";
	cin>>b;
	cout<<endl;
	cout<<"Ingrese c: ";
	cin>>c;
	cout<<endl;
	
	Mayor (a,b,c);
	
	return 0;
}
void Mayor (int x, int y, int z)
{
	if (x>y && x>z)
	{
		cout<<"El mayor es: "<<x<<endl;
	}
	if (y>x && y>z)
	{
		cout<<"El mayor es: "<<y<<endl;
	}
	if (z>x && z>y)
	{
		cout<<"El mayor es: "<<z<<endl;
	}
}
