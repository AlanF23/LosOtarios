#include<iostream>

using namespace std;

int main ()
{
	
	int A[10], i, j, b, c;
	for (i=0; i<10; i++)
	{
		cout<<"Asigne un valor en la posiciÃ³n "<<i+1<<": ";
		cin>>A[i];
	}
	b = 0;
	for (i=0; i<10; i++)
	{
		c = 0;
		for (j=i+1; j<10; j++)
		{
			cout<<"El valor de J es: "<<j<<endl;
			if (A[i] == A[j])
			{
				c++;
			}
			else
			{
				b++;
			}
		}
		if (c > 1)
		{
			c++;
			cout<<"El valor en la posicion "<< i+1 <<" se repite "<< c <<" veces."<<endl;
		}
		else
		   if (c == 1)
			   cout<<"El valor en la posicion "<< i+1 <<" se repite con el valor en la posicion "<< j <<"."<<endl;
	}
	if (b == 45)
	{
		cout<<"Ningun valor se repite";
	}
	
	return(0);
	
} 
