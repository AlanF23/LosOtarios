#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

struct nodo{
	int dni;
	char nombre[25];
	int nota;
	nodo *siguiente;
	nodo *atras;
};
nodo *primero = NULL;
nodo *ultimo = NULL;

void Menu();
void Agregar();
bool Buscar(int);
void Eliminar();
void Total();
void Mostrar();

int main(int argc, char *argv[]) {
	
	Menu();
	
	return 0;
}

void Menu(){
	char op;
	do{
		cout<<endl<<"/////////////"<<endl;
		cout<<"a. Agregar un estudiante"<<endl;
		cout<<"b. Buscar un estudiante por DNI"<<endl;
		cout<<"c. Eliminar un estudiante"<<endl;
		cout<<"d. Total de estudiantes reprobados y aprobados"<<endl;
		cout<<"e. Mostrar lista."<<endl;
		cout<<"f. Salir"<<endl;
		cout<<endl<<"/////////////"<<endl;
		cin>>op;
		switch(op){
			case 'a':
				Agregar();
				break;
			case 'b':
				int dni1;
				do{										//validar dni
					cout<<"Ingrese DNI: "<<endl;
					cin>>dni1;
				} while(dni1<0);
				if(Buscar(dni1)){
					cout<<"Encontrado"<<endl;
				}
				break;
			case 'c':
				Eliminar();
				break;
			case 'd':
				Total();
				break;
			case 'e':
				Mostrar();
				break;
			case 'f':
				cout<<"Finalizado correctamente";
				break;
			default:
				cout<<"Opcion Incorrecta";
				break;
		}
		
	} while(op != 'f');
}

void Agregar(){
	int dni1,nota1;
	char nombre1[25];
	nodo *nuevo=(nodo *) malloc(sizeof(nodo));
	do{										//validar dni
		cout<<"Ingrese DNI: "<<endl;
		cin>>dni1;
	} while(dni1<0);
	cout<<"Ingrese Nombre: "<<endl;
	cin>>nombre1;
	do{										//validar nota
		cout<<"Ingrese Nota: "<<endl;
		cin>>nota1;
	} while(nota1<0 && nota1>10);
	
	nuevo->dni = dni1;
	strcpy(nuevo->nombre,nombre1);
	nuevo->nota = nota1;
	if(!(Buscar(dni1))){
		if(primero == NULL){
			primero = nuevo;
			primero->siguiente = NULL;
			primero->atras = NULL;
			ultimo = primero;
		}
		else{
			if(nota1>=6){
				primero->atras=nuevo;
				nuevo->atras=NULL;
				nuevo->siguiente = primero;
				primero = nuevo;
			}
			else{
				ultimo->siguiente = nuevo;
				nuevo ->siguiente = NULL;
				nuevo->atras = ultimo;
				ultimo = nuevo;
			}
		}
	}
	else{
		cout<<"El alumno ya ha sido cargado"<<endl;
	}
}
bool Buscar(int dni1){
	nodo *actual=(nodo *)malloc(sizeof(nodo));
	actual=primero;
	bool encontrado=false;
	if(primero !=NULL){
		while ((actual!=NULL) && (encontrado!= true)){
			if (actual->dni == dni1){
				encontrado=true;
			}
			actual=actual->siguiente;
		}
	}
	return encontrado;
	
}
void Eliminar(){
	int dni1;
	cout<<"Ingrese DNI del almuno a eliminar: "<<endl;
	cin>>dni1;
	if((Buscar(dni1))){
		nodo *actual=(nodo *) malloc(sizeof(nodo));
		actual = primero;
		nodo *anterior = (nodo *) malloc(sizeof(nodo));
		anterior = NULL;
		if(primero != NULL){
			while(actual != NULL){
				if(actual->dni == dni1){
					if(actual==primero){
						primero = primero->siguiente;
						primero->atras=NULL;
					}
					else if(actual == ultimo){
							anterior->siguiente = NULL;
							ultimo = anterior;
						}
						else{
							anterior->siguiente=actual->siguiente;
							actual->siguiente->atras=anterior;
						}
					
				}
				anterior=actual; 
				actual=actual->siguiente; 
			}
			cout<<"DNI: "<<actual->dni<<endl;
			cout<<"Nombre: "<<actual->nombre<<endl;
			cout<<"Nota: "<<actual->nota<<endl;
			free(actual);
			
		}
	}
	else{
		cout<<"EL alumno no existe"<<endl;
	}
}
void Total(){
	
}
void Mostrar(){
	nodo *actual=(nodo *)malloc(sizeof(nodo));
	actual=primero;
	if(primero !=NULL){
		while (actual!=NULL){
			cout<<"DNI: "<<actual->dni<<endl;
			cout<<"Nombre: "<<actual->nombre<<endl;
			cout<<"Nota: "<<actual->nota<<endl;
			actual=actual->siguiente;
		}
	}
	else
	   cout << "La lista esta vacia" << endl;
	
} 
