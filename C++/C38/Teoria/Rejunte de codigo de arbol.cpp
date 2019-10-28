#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo
{
	int dato;
	Nodo *dere, *izq, *padre;
};

void agregar (Nodo *&, int, Nodo *);
Nodo *crear(int, Nodo *);
bool buscar(Nodo *, int);
void mostrar(Nodo *, int);
void eliminar (Nodo *, int);
void preorden(Nodo *);
void inorden(Nodo *);
void posorden(Nodo *);
void eliminarnodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *, Nodo *);
void borrar(Nodo *);

int main()
{
	Nodo *arbol=NULL;
	char opc;
	int num=0, espacio=0;
	do
	{
		cout<<"1.Agregar un nodo al arbol."<<endl;
		cout<<"2.Buscar un nodo del arbol."<<endl;
		cout<<"3.Mostrar el arbol completo."<<endl;
		cout<<"4.Eliminar un nodo del arbol."<<endl;
		cout<<"5.Recorrer el arbol en modo PreOrden."<<endl;
		cout<<"6.Recorrer el arbol en modo InOrden."<<endl;
		cout<<"7.Recorrer el arbol en modo PosOrden."<<endl;
		cout<<"8.Salir."<<endl;
		cout<<"\nDigite una opcion: ";
		cin>>opc;
		
		switch (opc)
		{
			case '1':
			{
				cout<<"\nDigite un numero: ";
				cin>>num;
				agregar(arbol, num, NULL);
				break;
			}
			case '2':
			{
				num=0;
				cout<<"\nIngrese el valor a buscar: ";
				cin>>num;
				if(buscar(arbol, num))
				{
					cout<<"El nodo existe."<<endl;
				}
				else
				{
					cout<<"El nodo no existe."<<endl;
				}
				break;
			}
			case '3':
			{
				cout<<"\nArbol completo: "<<endl<<endl;
				mostrar(arbol,espacio);
				cout<<endl;
				break;
			}
			case '4':
			{
				num=0;
				cout<<"\nIngrese el valor a eliminar: ";
				cin>>num;
				eliminar(arbol, espacio);
				mostrar(arbol, espacio);
				break;
			}
			case '5':
			{
				cout<<"Recorrido del arbol en PreOrden."<<endl;
				preorden(arbol);
				cout<<endl;
				break;
			}
			case '6':
			{
				cout<<"Recorrido del arbol en InOrden."<<endl;
				inorden(arbol);
				break;
			}
			case '7':
			{
				cout<<"Recorrido del arbol en PosOrden."<<endl;
				posorden(arbol);
				cout<<endl;
				break;
			}
		}
		
	} while(opc != '8');
	
	
	return 0;
}
void agregar (Nodo *&arbol, int dato1, Nodo *padre)
{
	if(arbol==NULL)
	{
		Nodo *nuevo = crear (dato1, padre);
		arbol=nuevo;
	}
	else
	{
		int raiz = arbol->dato;
		if(dato1 < raiz)
		{
			agregar(arbol->izq, dato1, arbol);
		}
		else if(dato1 > raiz)
		{
			agregar(arbol->dere, dato1, arbol);
		}
		else
		{
			cout<<endl<<endl<<"El nodo ya existe..."<<endl;
			//system("pause");
		}
	}
}
Nodo *crear (int valor, Nodo *padre)
{
	Nodo *nuevo=(Nodo *) malloc (sizeof(Nodo));
	nuevo->dato=valor;
	nuevo->izq=NULL;
	nuevo->dere=NULL;
	nuevo->padre=padre;
	return(nuevo);
}
bool buscar (Nodo *arbol, int valor)
{
	if(arbol==NULL)
	{
		return false;
	}
	else if(valor < arbol->dato)
	{
		return buscar(arbol->izq, valor);
	}
	else if(valor > arbol->dato)
	{
		return buscar(arbol->dere, valor);
	}
	else
	{
		return true;
	}
}
void mostrar (Nodo *arbol, int espacio)
{
	if(arbol==NULL)
	{
		return;
	}
	else
	{
		mostrar(arbol->dere, espacio +1);
		for(int i=0;i<espacio;i++)
		{
			cout<<"		";
		}
		cout<<arbol->dato<<endl;
		mostrar(arbol->izq, espacio +1);
	}
}
void preorden(Nodo *arbol)
{
	if(arbol==NULL)
	{
		return;
	}
	else
	{
		cout<<arbol->dato<<" - ";
		preorden(arbol->izq);
		preorden(arbol->dere);
	}
}
void inorden(Nodo *arbol)
{
	if(arbol==NULL)
	{
		return;
	}
	else
	{
		inorden(arbol->izq);
		cout<<arbol->dato<<" - ";
		inorden(arbol->dere);
	}
}
void posorden(Nodo *arbol)
{
	if(arbol==NULL)
	{
		return;
	}
	else
	{
		posorden(arbol->izq);
		posorden(arbol->dere);
		cout<<arbol->dato<<" - ";
	}
}
void eliminar(Nodo *arbol, int valor)
{
	if(arbol==NULL)
	{
		return;
	}
	else if(valor < arbol->dato)
	{
		eliminar(arbol->izq, valor);
	}
	else if(valor > arbol->dato)
	{
		eliminar(arbol->dere, valor);
	}
	else
	{
		eliminarnodo(arbol);
	}
}
void eliminarnodo(Nodo *nodo)
{
	if(nodo->izq && nodo->dere)
	{
		Nodo *menor = minimo(nodo->dere);
		nodo->dato = menor->dato;
		
		eliminarnodo(menor);
	}
	else if(nodo->izq)
	{
		reemplazar(nodo, nodo->izq);
		borrar(nodo);
	}
	else if(nodo->dere)
	{
		reemplazar(nodo, nodo->dere);
		borrar(nodo);
	}
	else
	{
		reemplazar(nodo, NULL);
		borrar(nodo);
	}
}
Nodo *minimo(Nodo *arbol)
{
	if(arbol == NULL)
	{
		return NULL;
	}
	else if(arbol->izq)
	{
		return minimo(arbol->izq);
	}
	else
	{
		return arbol;
	}
}
void reemplazar(Nodo *arbol, Nodo *nodo)
{
	if(arbol->padre)
	{
		if(arbol->padre->izq)
		{
			if(arbol->dato == arbol->padre->izq->dato)
			{
				arbol->padre->izq=nodo;
			}
		}
		if(arbol->padre->dere)
		{
			if(arbol->dato == arbol->padre->dere->dato)
			{
				arbol->padre->dere=nodo;
			}
		}
	}
	if(nodo)
	{
		nodo->padre=arbol->padre;
	}
}
void borrar(Nodo *nodo)
{
	nodo->izq=NULL;
	nodo->dere=NULL;
	nodo->padre=NULL;
	
	free(nodo);
}
