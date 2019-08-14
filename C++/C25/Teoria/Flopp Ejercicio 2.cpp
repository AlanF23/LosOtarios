/*2) Ingresar dos números, intercambiar y mostrar sus
valores utilizando punteros.*/

#include <iostream>
using namespace std;

int main()
{
	int a,b,i,aux=0;
	int *pa, *pb;

	cout<<"Ingrese dos numeros. "<<endl;
	cin>>a;
	cout<<endl;
	cin>>b;

	for (i=0;i<2;i++)
	{
		aux=b;
		b=a;
		a=aux;
	}

	{
	pa=&a;
	pb=&b;
	}

	cout<<endl;
	cout<<"El valor primero ahora es: "<<*pb<<" En la posicion: "<<pb<<endl;
	cout<<"El valor segundo ahora es: "<<*pa<<" En la posicion: "<<pa<<endl;

	return 0;
}
