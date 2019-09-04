#include <iostream>

int ing (void);
int ver(int,int);

using namespace std;

int main()
{
	int a,b;
	int correcto = 3;
	
	while(a!=correcto)
	{
		a = ing ();
		b = ver (a,correcto);
			
		cout<<"["<<b<<"]"<<endl;
	}
	return 0;
}
int ing()
{
	int x;
	
	cout<<"Adivina el numero"<<endl;
	cout<<"Si es correcto vera un 0, si es mayor un 1 y si es menor un -1"<<endl;
	cout<<"Ingrese un numero entre 1 y 100: "<<endl;
	
	cin>>x;
	while (x<1 or x>100)
	{
		cin>>x;
	}
	return (x);
}
int ver (int f, int g)
{
	int d;
	if (f==g)
	{
		d = 0;
	}
	else
		{
		if (f<g)
		{
			d = -1;
		}
		else
			{
			if (f>g)
			{
				d = 1;
			}
		}
	}
	return (d);
}
