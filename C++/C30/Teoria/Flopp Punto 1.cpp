#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

struct nodo
{
	int num;
	nodo *siguiente;
};
void agregar(nodo *&, int);
void eliminar(nodo *&);

int main(int argc, char *argv[]) 
{
	nodo *pila;
	pila=NULL;
	char opc;
	int x;
	
	do
	{
		do
		{
			cout<<"Quiere ingresar elementos a la pila?"<<endl;
			cout<<"[S] para si, [N] para no : ";
			cin>>opc;
		} while(opc!='s' && opc!='n');
		
		if (opc=='s')
		{
			cout<<"\nIngrese un numero : ";
			cin>>x;
			agregar(pila,x);
		}
		else
		{
			cout<<"\nEligio no cargar la pila."<<endl;
		}
		
	} while(opc!='n');
	cout<<"\nEliminando la pila..."<<endl;
	while(pila!=NULL)
	{
		eliminar(pila);
	}
	cin.get();
	return 0;
}
void agregar(nodo *&pila, int n)
{
	nodo *nuevo;
	nuevo = (nodo *) malloc (sizeof(nodo));
	if(nuevo!=NULL)
	{
		nuevo->num=n;
		nuevo->siguiente=pila;
		pila=nuevo;
	}
	else
	{
		cout<<"\nNo hay memoria suficiente."<<endl;
	}
}
void eliminar(nodo *&pila)
{
	int aux2=0;
	nodo *aux=pila;
	aux2=aux->num;
	pila=aux->siguiente;
	free(aux);
	cout<<"Elemento eliminado : "<<aux2<<endl;
}
