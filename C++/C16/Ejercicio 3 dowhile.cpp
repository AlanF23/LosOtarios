#include<iostream>
using namespace std;
int main (){
	int a, l, s;
	do
		{
	cout<<"Olah viemvbenido d nuebo"<<endl;	
	cout<<"Ingrese el ancho: "<<endl;
	cin>>a;
	cout<<"Ingrese el largo: "<<endl;
	cin>>l;
	s=a*l;
	cout<<"La superficie es de: "<<s<<endl;
	if (s<250)
		cout<<"PROBABILIDAD DE VENTA: Baja"<<endl;
	else
		if (s==250 or s<1000)
			cout<<"PROBABILIDAD DE VENTA: Media"<<endl;
		else
			if (s>=1000)
				cout<<"PROBABILIDAD DE VENTA: Alta"<<endl;
	}while (s>0);
} 
