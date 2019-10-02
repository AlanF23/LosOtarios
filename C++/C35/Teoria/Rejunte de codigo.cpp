/*MAS DE MEDIA HORA ENTENDIENDO LAS LLAVES DEL PDF PARA QUE ANDE BIEN LPM*/

#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

struct nodo
{
	int num;
	nodo *siguiente;
	nodo *atras;
};
nodo *primero=NULL;
nodo *ultimo=NULL;

void cargar(int);
void mostrar();
void mostrar2();
void buscar();
void modificar();
void eliminar();

int main() 
{
	int opc, x, cant;
	
	do
	{
		cout<<"1-Insertar un nodo"<<endl;
		cout<<"2-Buscar un nodo"<<endl;
		cout<<"3-Modificar un nodo"<<endl;
		cout<<"4-Eliminar un nodo"<<endl;
		cout<<"5-Mostrar lista de adelante hacia atrás"<<endl;
		cout<<"6 Mostrar lista de atrás hacia adelante"<<endl;
		cout<<"7 Salir"<<endl;
		cout<<"\nIngrese una opcion: ";
		cin>>opc;
		switch (opc)
		{
			case 1:
			{
				cout<<"\nCuantos numeros desea cargar? ";
				cin>>cant;
				for(int i=0;i<cant;i++)
				{
					cout<<"\nIngrese el numero que desea cargar: ";
					cin>>x;
					cargar(x);
				}
				cout<<endl;
			}
			break;
			case 5:
			{
				mostrar();
				cout<<endl;
				break;
			}
			case 6:
			{
				mostrar2();
				cout<<endl;
				break;
			}
			case 2:
			{
				buscar();
				cout<<endl;
				break;
			}
			case 3:
			{
				modificar();
				break;
			}
			case 4:
			{
				eliminar();
				break;
			}
		}
	} while(opc!=7);
	return 0;
}
void cargar(int w)
{
	nodo *actual=(nodo *) malloc (sizeof(nodo));
	actual->num=w;
	
	if(primero==NULL)
	{
		primero=actual;
		primero->siguiente=NULL;
		primero->atras=NULL;
		ultimo=primero;
		cout<<"\nPrimer nodo Ingresado "<<endl;
	}
	else
	{
		ultimo->siguiente=actual;
		actual->siguiente=NULL;
		actual->atras=ultimo;
		ultimo=actual;
		cout<<"\nNodo Ingresado"<<endl;
	}
}
void mostrar()
{
	nodo *actual=(nodo *) malloc (sizeof(nodo));
	actual=primero;
	
	if(primero!=NULL)
	{
		while(actual!=NULL)
		{
			cout<<"\nSe muestra de adelante para atras "<<actual->num<<endl;
			actual=actual->siguiente;
		}
	}
	else
	{
		cout<<"La lista esta vacia"<<endl;
	}
}
void mostrar2()
{
	nodo *actual=(nodo *) malloc (sizeof(nodo));
	actual=ultimo;
	
	if(primero!=NULL)
	{
		while(actual!=NULL)
		{
			cout<<"\nSe muestra de atras para delante "<<actual->num<<endl;
			actual=actual->atras;
		}
	}
	else
	{
		cout<<"La lista esta vacia"<<endl;
	}
}
void buscar()
{
	nodo *actual=(nodo *) malloc (sizeof(nodo));
	actual=primero;
	bool encontrado=false;
	int buscado=0;
	cout<<"Ingrese el valor a buscar: ";
	cin>>buscado;
	
	if(primero!=NULL)
	{
		while((actual!= NULL) and (encontrado==true))
		{
			if(actual->num==buscado)
			{
				cout<<"\nNodo encontrado: "<<buscado<<endl;
				encontrado=true;
			}
			actual=actual->siguiente;
		}
		if(encontrado==false)
		{
			cout<<"\nNodo no encontrado"<<endl;
		}
		else
		{
			cout<<"\nLista vacia"<<endl;
		}
	}
}
void modificar()
{
	nodo *actual=(nodo *) malloc (sizeof(nodo));
	actual=primero;
	bool encontrado=false;
	int buscado=0;
	cout<<"Ingrese el numero que desea modificar: ";
	cin>>buscado;
	
	if(primero!=NULL)
	{
		while(actual!=NULL)
		{
			if(actual->num==buscado)
			{
				cout<<"\nNodo encontrado: "<<buscado<<endl;
				cout<<"\nIngrese el nuevo numero: ";
				cin>>actual->num;
				cout<<"\nNodo modificado"<<endl;
				encontrado=true;
			}
			actual=actual->siguiente;
		}
		if(encontrado==false)
		{
			cout<<"\nNodo no encontrado"<<endl;
		}
		else
		{
			cout<<"\nLa lista esta vacia"<<endl;
		}
	}
}
void eliminar()
{
	nodo *actual=(nodo *) malloc (sizeof(nodo));
	actual=primero;
	nodo *anterior=(nodo *) malloc (sizeof(nodo));
	anterior=NULL;
	bool encontrado=false;
	int buscado=0;
	cout<<"\nIngrese el nodo a buscar: ";
	cin>>buscado;
	
	if(primero!=NULL)
	{
		while(actual!=NULL)
		{
			if(actual->num==buscado)
			{
				cout<<"\nNodo encontrado: "<<buscado<<endl;
				if(actual==primero)
				{
					primero=primero->siguiente;
					primero->atras=NULL;
				}
				else if(actual==ultimo)
				{
					anterior->siguiente=NULL;
					ultimo=anterior;
				}
				else
				{
					anterior->siguiente=actual->siguiente;
					actual->siguiente->atras=anterior;
				}	
				cout<<"\nNodo eliminado"<<endl;
				encontrado=true;
			}
			anterior=actual;
			actual=actual->siguiente;
		}
		free(actual);
	}
	
	if(encontrado==false)
	{
		cout<<"\nNodo no encontrado"<<endl;
	}
	else
	{
		cout<<"La lista esta vacia"<<endl;
	}
}
