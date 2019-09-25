#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

struct nodo1
{
	int num1;
	nodo1 *siguiente1;
};
struct nodo2
{
	int num2;
	nodo2 *siguiente2;
};
struct nodo3
{
	int num3;
	nodo3 *siguiente3;
};
void agregar(nodo1 *&, int);
void agregar1(nodo2 *&, int);
void agregar3(nodo3 *&, int);

void eliminar(nodo1 *&);
void eliminar2(nodo2 *&);
void eliminar3(nodo3 *&);
int main() 
{
	nodo1 *pila1;
	nodo2 *pila2;
	nodo3 *pila3;
	
	pila1=NULL;
	pila2=NULL;
	pila3=NULL;
	
	int x, cont=0;
	
	do
	{
		cout<<"Ingrese un numero: ";
		cin>>x;
		if(x%2==0 && x!=0)
		{
			agregar(pila1,x);
		}
		if(x%2!=0 && x!=0)
		{
			agregar1(pila2, x);
		}
		for(int i=1;i<=x;i++)
		{
			if(x%i==0 && x!=0)
			{
				cont++;
			}
		}
		cout<<" "<<cont<<endl;
		if(cont==2)
		{
			agregar3(pila3, x);
		}
		cont=0;
	} while(x!=0);
	cout<<"\nEliminando la pila..."<<endl;
	while(pila1!=NULL)
	{
		eliminar(pila1);
	}
	cin.get();
	cout<<"\nEliminando la pila 2..."<<endl;
	while(pila2!=NULL)
	{
		eliminar2(pila2);
	}
	cout<<"\nEliminando la pila 3..."<<endl;
	while(pila3!=NULL)
	{
		eliminar3(pila3);
	}
	cin.get();
	return 0;
}
void agregar(nodo1 *&pila, int n)
{
	nodo1 *nuevo;
	nuevo = (nodo1 *) malloc (sizeof(nodo1));
	if(nuevo!=NULL)
	{
		nuevo->num1=n;
		nuevo->siguiente1=pila;
		pila=nuevo;
	}
	else
	{
		cout<<"\nNo hay memoria suficiente."<<endl;
	}
}
void eliminar(nodo1 *&pila1)
{
	int aux2=0;
	nodo1 *aux=pila1;
	aux2=aux->num1;
	pila1=aux->siguiente1;
	free(aux);
	cout<<"Elemento eliminado : "<<aux2<<endl;
}
void agregar1(nodo2 *&pila2, int n)
{
	nodo2 *nuevo;
	nuevo = (nodo2 *) malloc (sizeof(nodo2));
	if(nuevo!=NULL)
	{
		nuevo->num2=n;
		nuevo->siguiente2=pila2;
		pila2=nuevo;
	}
	else
	{
		cout<<"\nNo hay memoria suficiente."<<endl;
	}
}
void eliminar2(nodo2 *&pila2)
{
	int aux2=0;
	nodo2 *aux=pila2;
	aux2=aux->num2;
	pila2=aux->siguiente2;
	free(aux);
	cout<<"Elemento eliminado : "<<aux2<<endl;
}
void agregar3(nodo3 *&pila3, int n)
{
	nodo3 *nuevo;
	nuevo = (nodo3 *) malloc (sizeof(nodo3));
	if(nuevo!=NULL)
	{
		nuevo->num3=n;
		nuevo->siguiente3=pila3;
		pila3=nuevo;
	}
	else
	{
		cout<<"\nNo hay memoria suficiente."<<endl;
	}
}
void eliminar3(nodo3 *&pila3)
{
	int aux2=0;
	nodo3 *aux=pila3;
	aux2=aux->num3;
	pila3=aux->siguiente3;
	free(aux);
	cout<<"Elemento eliminado : "<<aux2<<endl;
}
