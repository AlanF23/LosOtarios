#include <iostream>
using namespace std;

int main ()
{
	int i,p;
	int a[10];
	int r = 0;
	int m = 0;
	for (i = 0; i < 5; i ++)
	{
		cout << "Ingrese un numerete: ";
		cin >> a[i];
	}
	for (i = 0; i < 5; i++)
	{
	r = r + a[i];
	}
	cout << "el resultado de la suma es: "<< r <<endl;
	p = r%5;
	cout << "el promedio es: " << p <<endl;
	for (i = 0; i < 5; i++)
	{
	if (a[i] > p)
	{
		m=m+1;
	}
	}
	cout << "hay " << m << " numeros mayor que " << p;
	return 0;
} 
