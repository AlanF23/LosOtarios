/*1) Ingresar un número e informar si es primo o no y su
posición de memoria utilizando punteros.*/

#include <iostream>
using namespace std;

int main() {
	int nro, *puntero;
	cout<<"Ingrese un numero: "<<endl;
	cin>>nro;
	puntero=&nro;
	cout<<"La posicion es: "<<puntero;

	return 0;
}
