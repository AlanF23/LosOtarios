#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
	int peso;
	nodo *siguiente;
};

nodo *lista = NULL;

void Menu();
void Cargar(nodo *&, int, int &);
void Mostrar(nodo *);
void Eliminar(nodo *&, int);
void buscar(nodo *, int);
int main(int argc, char *argv[]) {
	
	Menu();
	
	return 0;
}

void Menu(){
	int posi=0;
	char op;
	int bus;
	do{
		cout<<"///////////////"<<endl;
		cout<<"1. Agregar peso"<<endl;
		cout<<"2. Eliminar peso"<<endl;
		cout<<"3. MOstrar"<<endl;
		cout<<"4. BUscar un elemento por su posicion"<<endl;
		cout<<"S. Salir"<<endl;
		cout<<"///////////////"<<endl;
		cin>>op;
		
		switch(op){
		case '1':
			int peso1;
			cout<<"Cual es el peso que desea agregar: ";
			cin>>peso1;
			Cargar(lista, peso1, posi);
			break;
		case '2':
			cout<<"Que peso desea eliminar: ";
			cin>>peso1;
			Eliminar(lista, peso1);
			break;
		case '3':
			Mostrar(lista);
			break;
		case '4':
			cout<<"\nLa lista tiene: "<<posi<<" posiciones."<<endl;
			do
			{
				cout<<"Ingrese que posicion desea buscar: ";
				cin>>bus;
			} while(bus<posi or bus>posi);
			
			buscar(lista, posi);
			break;
		default:
			break;
		}
		
		
	} while(op != 'S');
	
}

void Cargar(nodo *&lista, int peso1, int &pos){
	nodo *nuevo;
	nuevo = (nodo *) malloc(sizeof(nodo));
	
	nuevo->peso = peso1;
	
	nodo *actual = lista;
	nodo *anterior;
	if(lista !=NULL){
		
		do{
			anterior = actual;
			actual = actual->siguiente;
		} while(actual != lista);
		
		nuevo->siguiente = lista;
		anterior->siguiente = nuevo;
		
		
	}
	else{
		lista = nuevo;
		nuevo->siguiente = lista;
	}
	pos++;
}

void Mostrar(nodo *lista){
	nodo *aux = lista;
	if(lista != NULL){
		cout<<"Los pesos son: "<<endl;
		
		do{
			cout<<" "<<aux->peso<<" "<<endl;
			cout<<"posicion: "<<aux<<" "<<endl;
			aux = aux->siguiente;
		} while(aux != lista);
		cout<<endl;
	}
	else{
		cout<<"La lista esta vacia"<<endl;
	}
}

void Eliminar(nodo *&lista, int peso1){
	nodo *actual = lista;
	nodo *anterior = NULL;
	if(lista != NULL){
		if(actual->peso == peso1){
			if(lista->siguiente == lista){
				lista = NULL;
			}
			else{
				do{
					anterior = actual;
					actual = actual->siguiente;
				} while(actual != lista);
				anterior->siguiente = actual->siguiente;
				lista = anterior;
			}
		}
		else{
			do{
				anterior = actual;
				actual = actual->siguiente;
			} while(actual != lista && actual->peso != peso1);
			anterior->siguiente = actual->siguiente;
			
		}
		free(actual);
		cout<<endl;
	}
	else{
		cout<<"La lista esta vacia"<<endl;
	}
	
}
void buscar(nodo *lista, int posicion)
{
	nodo *aux = lista;
	if(lista != NULL){
		cout<<"Los pesos son: "<<endl;
		
		/*do{
			cout<<" "<<aux->peso<<" "<<endl;
			cout<<"posicion: "<<aux<<" "<<endl;
			aux = aux->siguiente;
		} while(aux != lista);*/
		for(int i=0;i<posicion;i++)
		{
			if(i==posicion)
			{
				cout<<"\nEl dato es: "<<aux->peso<<endl;
			}
			aux=aux->siguiente;
		}
		cout<<endl;
	}
	else{
		cout<<"La lista esta vacia."<<endl;
	}
}
