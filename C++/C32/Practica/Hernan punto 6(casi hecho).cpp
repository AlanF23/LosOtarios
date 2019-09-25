#include <iostream>
#include <stdlib.h>
using namespace std;
struct nodo{
	int num;
	nodo *p;
};
void Agregar(int,nodo *&);
void Imprimir(nodo *&);
void Ultimo(int,nodo *&);
void NumeroDeElemento(int &,nodo *&);
void EliminarElemento(int, nodo *&);

int main(int argc, char *argv[]) {
	int a;
	char z;
	
	nodo *pila;
	pila = NULL;
	cout<<"Que desea hacer"<<endl;
	do{
		cout<<endl<<"/////////MENU/////////"<<endl;
		cout<<endl<<"Desea agregar elementos? (1)"<<endl;
		cout<<endl<<"Desea imprimir los elementos? (2)"<<endl;
		cout<<endl<<"Desea agregar un elemento al final? (3)"<<endl;
		cout<<endl<<"Desea contar los elementos? (4)"<<endl;
		cout<<endl<<"Desea eliminar uno de los elementos? (5)"<<endl;
		cout<<endl<<"Salir (0)"<<endl;
		cout<<endl<<"----------------------"<<endl;
		cin>>z;
		switch(z){
			
		case '1':{
			cout<<"Cuantos Elementos desea cargar? ";
			cin>>a;
			for(int i = 0; i<a; i++){
				int b;
				cout<<"Ingrese nuevo elemento: ";
				cin>>b;
				Agregar(b,pila);
			}
		}break;
			
		case '2':{
			cout<<endl;
			cout<<"Los elementos de la pila son: ";
			Imprimir(pila);
			cout<<endl;
			cin.get();
			cin.get();
		}break;
			
		case '3':{
			Ultimo(a,pila);
			Imprimir(pila);
			cout<<endl;
			cin.get();
			cin.get();
		}break;
			
		case '4':{
			int c=0;
			NumeroDeElemento(c,pila);
			cout<<"La cantidad de elementos es: "<<c;
			cout<<endl;
			cin.get();
			cin.get();
		}break;
			
		case '5':{
			int d;
			cout<<"Que elemento desea eliminar"<<endl;
			cin>>d;
			EliminarElemento(d,pila);
			Imprimir(pila);
			cout<<endl;
			cin.get();
			cin.get();
		}break;
		default:
			break;
		}
	}while(z != '0');
	return 0;
}
void Agregar(int a,nodo *&pila){
	nodo *nuevo;
	nuevo = (nodo *) malloc(sizeof(nodo));
	nuevo->num = a;
	nuevo->p = pila;
	pila = nuevo;
}
void Imprimir(nodo *&pila){
	nodo *pilaaux = pila;
	while(pilaaux != NULL){
		int n;
		nodo *aux = pilaaux;
		n=aux->num;
		pilaaux = aux->p;
		cout<<n<<"  ";
	}
}
void Ultimo(int a,nodo *&pila){
	nodo *pilaaux = pila;
	for(int i = 0; i<a-1;i++){
		nodo *aux = pilaaux;
		pilaaux = aux->p;
	}
	nodo *nuevo;
	nuevo = (nodo *) malloc(sizeof(nodo));
	cout<<"Nuevo elemento?";
	cin>>nuevo->num;
	nuevo->p = NULL;
	pilaaux->p = nuevo;
	
	
}

void NumeroDeElemento(int &c,nodo *&pila){
	nodo *pilaaux = pila;
	while(pilaaux != NULL){
		nodo *aux = pilaaux;
		pilaaux = aux->p;
		c++;
	}
}
void EliminarElemento(int d,nodo *&pila){
	nodo *pilaaux1 = pila;
	nodo *pilaaux2 = pila;
	int cont = 0;
	while(pila != NULL and pilaaux1 != NULL){
		if(pila->num == d){
			nodo *aux = pila;
			pila = aux->p;
			free(aux);
			pilaaux1=pila;
			pilaaux2=pila;
		}
		else{
			if(pilaaux1->num == d){
				pilaaux2->p = pilaaux1;
				nodo *aux1 = pilaaux1;
				pilaaux1 = aux1->p;
				pilaaux2->p=pilaaux1;
				free(aux1);
			}
			else{
				nodo *aux1 = pilaaux1;
				pilaaux1 = aux1->p;
				if(cont !=0){
					nodo *aux2 = pilaaux2;
					pilaaux2 = aux2->p;
				}
				cont++;
			}
		}
	}
}
