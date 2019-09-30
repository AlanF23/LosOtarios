#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct nodo
{
	int num;
	nodo *siguiente;
};

void cargar (nodo *&, int);
void comparar(nodo *&lista);
int main() 
{
	int z;
	
	nodo *lista=NULL;
	
	cout<<"Ingrese 10 numeros"<<endl;
	
	for(int i=0;i<10;i++)
	{
		cout<<"\nIngrese el elemento ["<<i+1<<"] ";
		cin>>z;
		cargar(lista, z);
	}
	cin.get();
	
	comparar(lista);
	
	return 0;
}
void cargar(nodo *&lista, int x)
{
	nodo *nuevo=(nodo *) malloc (sizeof(nodo));
	nuevo->num=x;
	nodo *aux1=lista;
	nodo *aux2;
	while(aux1!=NULL)
	{
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	if(aux1==lista)
	{
		lista=nuevo;
	}
	else
	{
		aux2->siguiente=nuevo;
	}
	nuevo->siguiente=aux1;
	cout<<"\nEl numero ingresado es: "<<x<<endl;
}
void comparar(nodo *&lista)
{
	nodo *aux1=lista;
	
	while(aux1!=NULL)
	{
		if(aux1->num > 100)
		{
			cout<<"\nEl valor :"<<aux1->num<<" es mayor a 100"<<endl;
		}
		else
		{
			cout<<"\nEl valor :"<<aux1->num<<" es menor a 100"<<endl;
		}
		lista=lista->siguiente;
		aux1=lista;
	}
}
