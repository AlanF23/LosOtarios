#include <iostream>
using namespace std;

int main() 
{
	int num;
	int *pnum;
	int suma=0;
	int i;
	cout<<"Ingrese un numero: ";
	cin>>num;
	cin.get();
	
	for (i=1;i<(num+1);i++)
	{
		if (num%i==0)
		{
			suma++;
			pnum = &num;
		}
	}
	if (suma!=2)
	{
		cout<<"No es Numero primo"<<endl;
		cout<<"En la posicion: "<<pnum;
	}
	else
	{
		cout<<"Numero primo"<<endl;
		cout<<"En la posicion: "<<pnum;
	}
	return 0;
}
