#include <iostream>
using namespace std;

int main() {
	int n, a, m, pn, sn, nn, s;
	a=0;
	m=0;
	s=0;
	nn=0;
	sn=0;
	do 
	{
		cout<<"Ingresar numero: ";
		cin>>n;
		a++;
		if (n==1000)
		m++;
		if (n<0)
		{nn++;
		sn=(sn+n);
		}
		else
		s=s+n;
	} while (n!=999);
	if (nn!=0)
	pn=sn/nn;
	cout<<"Se ingresaron "<<a<<" numeros"<<endl;
	cout<<"Se ingresaron "<<m<<" MIL"<<endl;
	if (nn>0)
	cout<<"El promedio de los numeros negativos es "<<pn<<endl;
	else{
	cout<<"No se ingresaron numeros negativos"<<endl;}
	cout<<"La suma de los positivos es "<<s;
	return 0;
} 
