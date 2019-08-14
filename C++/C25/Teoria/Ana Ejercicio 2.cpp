#include <iostream>
using namespace std;
/*2) Ingresar dos números, intercambiar y mostrar sus
valores utilizando punteros.*/

int main() {
	int nro1, nro2, *pnum1, *pnum2, aux;
	cout<<"Ingrese dos numeros:"<<endl;
	cin>>nro1;
	cin>>nro2;
	aux=nro1;
	nro1=nro2;
	nro2=aux;
	pnum1=&nro1;
	pnum2=&nro2;
	cout<<"La posicion del 1er nro: "<<pnum1<<endl;
	cout<<"La posicion del 2do nro: "<<pnum2;
	return 0;
}
