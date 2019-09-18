#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

char *vec;
int cont=0;
struct nodo
{
	char num;
	nodo *siguiente;
};
void agregar(nodo *&, char);
void eliminar(nodo *&);
int main()
{
	nodo *pila;
	pila=NULL;
	int opc;
	char x;
	
	do
	{
		do
		{
			cout<<"Quiere ingresar una palabra a la pila?"<<endl;
			cout<<"[1] para si, [0] para no : ";
			cin>>opc;
		} while(opc!=1 && opc!=0);
		
		if (opc==1)
		{calif
			cout<<"\nIngrese una letra : ";
			cin>>x;
			agregar(pila,x);
			if(opc==1)
			{
				cont++;
			}
		}
		else
		{
			cout<<"\nEligio no cargar la pila."<<endl;
		}
		
	} while(opc!=0);
	cout<<"\nEliminando la pila..."<<endl;
	while(pila!=NULL)
	{
		eliminar(pila);
	}
	cin.get();
	cout<<endl;
	vec = (char *) malloc (cont * sizeof(int));
	for(int i=0;i<cont;i++)
	{
		cout<<"La palabra es: "<<vec[i]<<" ";
	}
}
void agregar(nodo *&pila, char n)
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
	while(
		nodo *aux=pila;
		vec[i]=aux->num;
		pila=aux->siguiente;
		free(aux);
		cout<<"Elemento eliminado : "<<endl;
	
}
