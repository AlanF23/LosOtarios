#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct nodo
{
	int dato;
	nodo *siguiente;
}hola;
void cargarlista(nodo *&, int);
void mostrar(nodo *&);
void buscar(nodo *&, int);
void eliminar(nodo *&, int);
void borrartodo(nodo *&);
int main()
{
	int n, opc, cant, x, e;
	char opn;
	nodo *lista=NULL;
	
	cout<<"\t"<<"MENU"<<endl;
	cout<<"1. Insertar elementos a la lista"<<endl;
	cout<<"Y  mostrar elementos de la lista"<<endl;
	cout<<"2. Buscar elementos de la lista"<<endl;
	cout<<"3. Eliminar elementos de la lista"<<endl;
	cout<<"4. Dejar vacia la lista"<<endl;
	cin>>opc;
	do
	{
		switch(opc)
		{
			case 1:
					cout<<"\nCuantos elementos desea agregar? ";
					cin>>cant;
					for(int i=0;i<cant;i++)
					{
						cin>>n;
						cargarlista(lista,n);
					}
					cin.get();
					mostrar(lista);
					break;
			case 2:
					cout<<"\nEligio buscar un numero "<<endl;
					cout<<"Ingrese el numero: ";
					cin>>x;
					cin.get();
					buscar(lista, x);
					break;
			case 3:
					cout<<"\nEligio eliminar un numero"<<endl;
					cout<<"Ingrese un numero: ";
					cin>>e;
					eliminar(lista, e);
			case 4:
					cout<<"\nEligio vaciar la lista"<<endl;
					borrartodo(lista);
		}
		cout<<"\nDesea seguir?"<<endl;
		cout<<"[s] o [n]"<<endl;
		cin>>opn;
		if(opn=='s' or opn=='S')
		{
			cout<<"\tMENU"<<endl;
			cout<<"1. Insertar elementos a la lista"<<endl;
			cout<<"Y  mostrar elementos de la lista"<<endl;
			cout<<"2. Buscar elementos de la lista"<<endl;
			cout<<"3. Eliminar elementos de la lista"<<endl;
			cout<<"4. Dejar vacia la lista"<<endl;
			cout<<"5. Salir"<<endl;
			cin>>opc;
		}
	}
	while(opn!='n');
	
	return 0;
}
void cargarlista(nodo *&lista, int n)
{
	nodo *nuevo_nodo=(nodo *) malloc(sizeof(nodo));
	nuevo_nodo->dato=n;
	nodo *aux1=lista;
	nodo *aux2;
	while(aux1!=NULL and aux1->dato<n)
	{
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	if(lista==aux1)
	{
		lista=nuevo_nodo;
	}
	else
	{
		aux2->siguiente=nuevo_nodo;
	}
	nuevo_nodo->siguiente=aux1;
	cout<<"\nEl elemento ingresado fue: "<<n<<endl;
}
void mostrar(nodo *&lista)
{
	nodo *actual=lista;
	while(actual!=NULL)
	{
		cout<<actual->dato<<"->"<<endl;
		actual=actual->siguiente;
	}
}
void buscar(nodo *&lista, int n)
{
	bool band=false;
	nodo *actual=lista;
	while(actual!=NULL and actual->dato <=n)
	{
		if(actual->dato==n)
		{
			band=true;
		}
		actual=actual->siguiente;
	}
	if(band==true)
	{
		cout<<"\nEl elemento se repite"<<endl;
	}
	else
	{
		cout<<"\nEl elemento no se repite"<<endl;
	}
}
void eliminar(nodo *&lista, int x)
{
	if(lista!=NULL)
	{
		nodo *auxborrar;
		nodo *anterior=NULL;
		auxborrar=lista;
	while ((auxborrar!=NULL) and (auxborrar->dato !=x))
	{
		anterior=auxborrar;
		auxborrar=auxborrar->siguiente;
	}
	if(auxborrar==NULL)
	{
		cout<<"\nElemento no encontrado"<<endl;
	}
	else if(anterior==NULL)
	{
		lista=lista->siguiente;
		free(auxborrar);
	}
	else
	{
		anterior->siguiente=auxborrar->siguiente;
		free(auxborrar);
	}
	}
	cout<<"\nLa lista quedo: "<<endl;
	mostrar(lista);
}
void borrartodo(nodo *&lista)
{
	int z=0;
	while(lista!=NULL)
	{
		nodo *aux=lista;
		z=aux->dato;
		lista=aux->siguiente;
		cout<<"\nElemento borrado: "<<z<<endl;
		free(aux);
	}
}
