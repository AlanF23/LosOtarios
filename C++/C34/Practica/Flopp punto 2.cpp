#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

struct nodo
{
	int sueldo;
	nodo *siguiente;
};

void sueldo1(nodo *&, int);
void mostrar(nodo *&);

int main() 
{
	int suel;
	
	nodo *lista=NULL;
	nodo *lista2=NULL;
	
	for(int i=0;i<3;i++)
	{
		cout<<"Ingrese el sueldo de los trabajadores de la mañana"<<endl;
		cin>>suel;
		sueldo1(lista, suel);
	}
	for(int j=0;j<3;j++)
	{
		cout<<"\nIngrese el sueldo de los trabajadores de la noche"<<endl;
		cin>>suel;
		sueldo1(lista2, suel);
	}
	cin.get();
	cout<<"\nSueldo de los trabajadores de la mañana"<<endl;
	mostrar(lista);
	cout<<"\nEl sueldo de los trabajadores de la noche"<<endl;
	mostrar(lista2);
	
	return 0;
}
void sueldo1(nodo *&lista, int sueldo2)
{
	nodo *nuevo=(nodo *) malloc (sizeof(nodo));
	nuevo->sueldo=sueldo2;
	nodo *aux1=lista;
	nodo *aux2;
	
	while(aux1!=NULL)
	{
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	if(lista==aux1)
	{
		lista=nuevo;
	}
	else
	{
		aux2->siguiente=nuevo;
	}
}
void mostrar(nodo *&lista)
{
	nodo *aux=lista;
	
	while(aux!=NULL)
	{
		cout<<"\nEl sueldo es :"<<aux->sueldo<<endl;
		aux=aux->siguiente;
	}
}
