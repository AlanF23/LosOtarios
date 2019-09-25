#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct nodo {
	int num;
	nodo *p;
};

int main(int argc, char *argv[]) {

	
	int a,n;
	cout<<"cuantos elementos necesita?"<<endl;
	cin>>a;
	nodo *pila;
	pila=NULL;
	for(int i=0;i<a;i++){
		nodo *nuevo;
		nuevo=(nodo *) malloc(sizeof (nodo));
		cout<<"ingrese valor"<<endl;
		cin>>nuevo -> num;
		nuevo -> p =pila;
		pila=nuevo;
	}
	nodo *pilaux=pila;
	nodo *aux;
	cout<<"los elementos de la pila son: ";
	
	for(int i=0;i<a;i++){
		aux=(nodo *) malloc(sizeof(nodo));
		aux= pilaux;
		n=aux->num;
		pilaux=aux -> p;
		cout<<n<<"   ";
	}
	fflush(stdin);
	pilaux = pila;
	aux= pilaux;
	cout<<"\nEl ultimo elemento es: ";
	while(aux->p!=NULL)
	{
		aux= pilaux;
		if(aux->p!=NULL);
		{
			pilaux=aux -> p;
		}
		n=aux->num;
	};
	cout<<n;
	
	nodo *nuevo2;
	nuevo2 = (nodo *) malloc (sizeof(nodo));
	nuevo2->num = aux->num;
	nuevo2->p=aux->p;
	pilaux->p=nuevo2;
	pilaux=pila;
	cout<<endl;
	
	for(int i=0;i<a;i++){
		aux=(nodo *) malloc(sizeof(nodo));
		aux= pilaux;
		n=aux->num;
		pilaux=aux -> p;
		cout<<n<<"   ";
	}
	return 0;
}
