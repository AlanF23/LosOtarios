#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int aux;
	struct alumno{
		char nombre[20];
		int promedio;
		int edad;
	}alum[3];
	
	for (int i = 0;i<3;i++){
		cout<<"ingrese nombre"<<"\n";
		cin.getline(alum[i].nombre,19);
		cout<<"ingrese promedio"<<"\n";
		cin>>(alum[i].promedio);
		cout<<"ingrese edad"<<"\n";
		cin>>(alum[i].edad);
		cin.get();
	}
	for (int i = 0;i<2;i++){
		for (int j = 1;j<3;j++){
			if (alum[i].promedio>alum[j].promedio){
				aux =i;
			}
			else
				aux =j; 
			}
	}
	
	cout<<"el mayor promdedio lo tiene: "<<alum[aux].nombre;
	return 0;
}

 
