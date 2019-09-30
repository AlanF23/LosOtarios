#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct nodo
	{
	int v;
	nodo *otro;
};
void cargar(nodo *&, int);
void trasladar(nodo *&);
int main() 
{
	nodo *lista=NULL;
	
	int x,q;
	
	cout<<"Cuantos numeros quiere ingresar? ";
	cin>>x;
	
	for(int i=0;i<x;i++)
	{
		cout<<"Ingrese el elemento : ";
		cin>>q;
		cargar(lista, q);
	}
	trasladar(lista);
	return 0;
}
void cargar(nodo *&lista, int z)
{
	nodo *nuevo=(nodo *) malloc (sizeof(nodo));
	nuevo->v=z;
	nodo *aux1=lista;
	nodo *aux2;
	
	while (aux1!=NULL)
	{
		aux2=aux1;
		aux1=aux1->otro;
	}
	if(lista==aux1)
	{
		lista=nuevo;
	}
	else
	{
		aux2->otro=nuevo;
	}
}
void trasladar(nodo *&lista)
{
	nodo *nuevo;
	nodo *aux=lista;
	
	while(aux!=NULL)
	{
		nuevo=(nodo *) malloc (sizeof(nodo));
		nuevo->v=aux->v;
		aux=aux->otro;
		lista=aux;
	}
	nodo *aux2=nuevo;
	
	cout<<"\nLa lista ahora esta asi : "<<endl;
	while(aux2!=NULL)
	{
		cout<<aux2->v<<endl;
		nuevo=nuevo->otro;
		aux2=nuevo;
	}
}
