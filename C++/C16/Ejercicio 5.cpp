#include<iostream>
#include<cmath>
using namespace std;
int main (){
	char o;
	int na, cont, n, ap, des, pr, su, nn;
	cont=0;
	ap=0;
	des=0;
	nn=0;
	do
	{
	cout<<"MENU"<<endl;
	cout<<"1. Cantidad de aprobados y desaprobados."<<endl<<"2. Promedio de notas"<<endl<<"S. Salir."<<endl<<"Ingrese su opcion: ";
	cin>>o;
	
	switch (o)
		{
		
	case '1':
		cout<<"Ingrese la cantidad de alumnos: ";
		cin>>na;
		for (na; cont<na; cont++)
		{
		cout<<"Ingrese una nota: ";
		cin>>n;
		if (n<0 or n>10)
		{
		do
		{cout<<"Reingrese la nota"<<endl;
			cin>>n;
		}while (n<0 or n>10);
		}
		if (n>=6)
			ap=ap+1;
		else
			des=des+1;}
		cout<<"La cantidad de aprobado(s) es "<<ap<<endl;
		cout<<"La cantidad de desaprobado(s) es "<<des<<endl;
		break;
		
	case '2':
		do{
			cout<<"Ingrese la nota (para salir ingrese 99):";
			cin>>n;
			if (n<0 or n>10 and n!=99)
			{
				do
				{cout<<"Reingrese la nota"<<endl;
				cin>>n;
				}while (n<0 or n>10);
			}
			nn=nn+1;
			su=su+n;
		}while (n!=99);
		su=su-99;
		nn=nn-1;
		pr=(su/nn);
		cout<<"El promedio es "<<pr<<endl;
		break;
	case 'S':
		cout<<"Aiosh";	
		break;
	case 's':
		cout<<"Aiosh";
	default:
			cout<<"No wei no mms"<<endl;
		break;
	
		}
	}while (o!='S' and o!='s');
		return(0);
} 
