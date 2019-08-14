#include <iostream>
using namespace std;
/*Realice un programa en lenguaje C que permita cargar tres vectores con las calificaciones
de tres asignaturas para 10 alumnos. Cada vector se utiliza para una asignatura. Validar
los datos cargados.
Una vez finalizada la carga, calcular y mostrar el promedio de las 3 materias para cada
alumno.*/
#define N 4
#define M 3
int main() {
	int materias[N][M], i, j, nul, *primero, *segundo, *tercero;
	nul=0;
	for (i=0; i<N; i++){
		for (j=0; j<M; j++){
			cin>>materias[i][j];
			while(materias[i][j]<0||materias[i][j]>10){
				cout<<"Invalido. Volver a ingresar: ";
				cin>>materias[i][j];
			}
		}
	}
	
	for (i=0; i<N; i++){
		for (j=0; j<M; j++){
			cout<<materias[i][j]<<"  ";
		}
		cout<<endl;
	}
	
	primero=&nul;
	
	for (i=0; i<N; i++){
		*primero=*primero+materias[i][0];
	}
	*primero=*primero/N;
	
	cout<<"Promedio del primero: "<<*primero<<endl;
	
	segundo=&nul;
	
	for (i=0; i<N; i++){
		*segundo=*segundo+materias[i][1];
	}
	*segundo=*segundo/N;
	
	cout<<"Promedio del segundo: "<<*segundo<<endl;
	
	tercero=&nul;
	
	for (i=0; i<N; i++){
		*tercero=*tercero+materias[i][0];
	}
	*tercero=*tercero/N;
	
	cout<<"Promedio del tercero: "<<*tercero;
	return 0;
}
