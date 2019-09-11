#include <iostream>

using namespace std;

void cambio (int&, int&);

int main()
{
	int a,b;
	
	cout<<"Ingrese un numero: ";
	cin>>a;
	cout<<"\nAhora ingrese otro numero: ";
	cin>>b;
	cout<<"\nLos numeros que ingreso fueron: "<<a<<", y "<<b<<endl;
	cambio(a,b);
	cout<<"\nLas nuevas posiciones son: "<<a<<", y "<<b<<endl;
	return 0;
}
void cambio (int &x, int &z)
{
	int aux=0;
	aux = x;
	x=z;
	z=aux;
}
