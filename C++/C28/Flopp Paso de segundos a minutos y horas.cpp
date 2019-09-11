#include <iostream>

using namespace std;

void cambio (double, int&, int&, int&);

int main()
{
	double t;
	int q=0,w=0,e=0;
	
	cout<<"Ingrese los segundos a calcular: ";	
	cin>>t;
	cout<<"\nLos segundos que ingreso fueron: "<<t<<endl;
	cout<<"\nAhora se va a convertir en sus respecivos minutos y horas...";
	cambio(t,q,w,e);
	cout<<"\nSon: "<<w<<" Horas, "<<q<<" Minutos, "<<e<<" segundos. "<<endl;
	
	return 0;
}
void cambio(double S, int &z, int &x, int &c)
{
	do
	{
		if(S>60)
		{
			z++;
			S=S-60;
		}
		if(z>60)
		{
			x++;
			z=z-60;
		}
		if(x>60)
		{
			c++;
			c=c-60; 
		}
	}while(S>60);
}
