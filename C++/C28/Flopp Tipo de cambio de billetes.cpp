#include <iostream>

using namespace std;

void cambio (int, int&, int&, int&, int&, int&, int&);

int main()
{
	int dola;
	int c=100, ci=50, v=20, d=10, g=5, u=1;
	
	cout<<"Ingrese un monto grande, en dolares: ";
	cin>>dola;
	cambio(dola,c,ci,v,d,g,u);
	cout<<"\nEn billetes de 100 hay: "<<c<<endl;
	cout<<"\nEn billetes de 50 hay: "<<ci<<endl;
	cout<<"\nEn billetes de 20 hay: "<<v<<endl;
	cout<<"\nEn billetes de 10 hay: "<<d<<endl;
	cout<<"\nEn billetes de 5 hay: "<<g<<endl;
	cout<<"\nEn billetes de 1 hay: "<<u<<endl;
	return 0;
}
void cambio (int dola, int &z, int &x, int &b, int &n, int &m, int &a)
{
	if(dola%z==0)
	{
		z = (dola/z);
	}
	if(dola%x==0)
	{
		x = (dola/x);
	}
	if(dola%b==0)
	{
		b = (dola/b);
	}
	if(dola%n==0)
	{
		n = (dola/n);
	}
	if(dola%m==0)
	{
		m = (dola/m);
	}
	if(dola%a==0)
	{
		a = (dola/a);
	}
}
