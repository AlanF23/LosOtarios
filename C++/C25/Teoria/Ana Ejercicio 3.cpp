/*3) Cargar un arreglo con N números y luego, utilizando
punteros, determinar el menor elemento del arreglo.
Mostrar el menor, su posición en el arreglo y su
dirección en memoria.*/

#include <iostream>
using namespace std;
#define N 4

int main() {
	int vec[N],i, *max, *puntero, posv, lim;
	lim=101;
	max=&lim;
	for (i=0; i<N; i++){
		cin>>vec[i];
		while (vec[i]<0||vec[i]>100){
			cout<<"Reingrese un nro > 0 o < 100:"<<endl;
			cin>>vec[i];}
		if (vec[i]<*max){
			max=&vec[i];
			posv=i;
			puntero=&vec[i];}
	}
		cout<<"el menor numero es "<<*max<<" en el vector esta en la pos "<<posv+1<<" y en la memoria, "<<puntero;
	return 0;
}
