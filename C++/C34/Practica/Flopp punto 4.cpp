#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct nodo
{
	int uno;
	nodo *siguiente;
};

void cargar(nodo *&, int);
void contar(nodo *);
int main() 
{
	int x, i=0;
	nodo *lista=NULL;
	
	cout<<"Ingrese numeros 000 para salir"<<endl;
	do
	{
		cout<<"\nIngrese el elemento ["<<i+1<<"] ";
		cin>>x;
		cargar(lista, x);
		i++;
	} while(x!=000);
	
	contar(lista);
	
	return 0;
}
void cargar(nodo *&lista, int z)
{
	nodo *nuevo=(nodo *) malloc (sizeof(nodo));
	nuevo->uno=z;
	nodo *aux=lista;
	nodo *aux1;
	
	while (aux!=NULL)
	{
		aux1=aux;
		aux=aux->siguiente;
	}
	if(lista==aux)
	{
		lista=nuevo;
	}
	else
	{
		aux1->siguiente=nuevo;
	}
}
void contar(nodo *lista)
{
	nodo *aux1;
	aux1=lista;
	int cont=0;
	
	while(aux1!=NULL)
	{
		cont++;
		lista=lista->siguiente;
		aux1=lista;
	}
	cout<<"\nSe repite :"<<cont-1<<" veces "<<endl;
}
