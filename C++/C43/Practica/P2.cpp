//#include <iostream>
//#include <stdio.h>
//#include <fstream>
//#include <locale.h>
//#include <ctype.h>
#include <cstring>

#define C 41 // MAXIMA CANTIDAD DE CARACTERES POR FILA DEL REGISTRO

using namespace std;

void menuPrincipal();
void especificarNombre(char cad[],int);
int generarArchivoCSV(char vector[], int);
void fOpcion2(int &);
/*void fOpcion3(char cad1[], int, char cad2[],int,int&);*/
void fOpcion3(char cad1[],int, int&);
/*int agregarRegistro(char vector1[], int, char vector2[], int);*/

int main()
{
	setlocale(LC_ALL, "spanish"); /* Permite imprimir caracteres con tilde */
	menuPrincipal();
	return 0;
}

void menuPrincipal()
{
	const int T = 51;//tama�o maximo del nombre del archivo .csv
	/*const int L = 15; */
	int nro_inReg;
	char nombreArchivo[T];
	/*char linea[L];*/
	
	char opc;
	do{
		cout<<"\t MENU:"<<endl;
		cout<<"\t 1: Especificar el nombre del archivo .csv ."<<endl;
		cout<<"\t 2: Ajustar valor inicial."<<endl;
		cout<<"\t 3: Cargar un registro de datos."<<endl;
		cout<<"\t S: Salir."<<endl;
		cout<<"\t Ingrese opci�n: [ ]\b\b";//ESTO PERMITE ESCRIBIR LA OPCION ENTRE LOS CORCHETES
		cin>>opc;
		cin.get();
		
		opc = tolower(opc);
		
		switch(opc){
		case '1':
			especificarNombre(nombreArchivo,T);
			break;
		case '2':
			fOpcion2(nro_inReg);
			break;
		case '3':
			/*fOpcion3(nombreArchivo,T, linea,L , nro_inReg);*/
			fOpcion3(nombreArchivo,T, nro_inReg);
			break;
		case 's':
			cout<<"\n\t **PROGRAMA TERMINADO**"<<endl;
			break;
		default: 
			cout<<"ERROR: Opcion no existente."<<endl;
		}
	} while(opc != 's');
}
void especificarNombre(char nombreArchivo[],int T) 
{
	int retorno;
	cout<<endl<<"\t Ingrese el nombre del nuevo archivo .csv :"<<endl<<"\t ";
	cin.getline(nombreArchivo, T-1);
	cin.get();
	
	retorno = generarArchivoCSV(nombreArchivo, T);
	
	if(retorno == 0)
	{
		cout<<"\n\t Error generando nuevo archivo."<<endl;
	}else{
		cout<<"\n\t Archivo .csv generado exitosamente."<<endl;
	}
}
int generarArchivoCSV(char nombArch[], int T)
{
	FILE *archivoGen;
	
	archivoGen= fopen(nombArch, "ab");
	if(archivoGen == NULL){
		return 0;
	}else{
		fwrite("Numero de lectura,Lectura\n", sizeof("Numero de lectura,Lectura\n"),1, archivoGen);
		fclose(archivoGen);
		return 1;
	}
}
void fOpcion2(int &nro_inReg) 
{
	cout<<"\t Ingrese el numero de la primera lectura."<<endl<<"\t ";
	do{
		cin>>nro_inReg;
		if(nro_inReg < 0)
		{
			cout<<"\t El numero de registro debe ser un entero positivo."<<endl;
		}
	} while(nro_inReg < 0);
}

/*void fOpcion3(char nombreArchivo[],int T, char linea[],int L, int &nro_inReg)*/
void fOpcion3(char nombreArchivo[],int T, int &nro_inReg)
{
	FILE *archivoSalida;
	char c, cad[C], linea[C];
	int i=0,j=0;
	
	/* 
	Para pasar de car�cter a n�mero: int n = (int) (c - 48);
	Para pasar de n�mero a car�cter: char c = (char) (n + 48);
	*/
	c = (char)(nro_inReg + 48);
	
	cout<<"\t Ingrese el dato al registro: "<<endl<<"\t ";
	cin.getline(cad,T-1);
	cin.get();
	
	//------------------------------------
	while(isprint(cad[j]))
	{
		if(i==0){
			linea[i] = c;
			i++;
			linea[i]=',';
			i++;
		}else{
			linea[i]=cad[j];
			i++;
			j++;
		}
	}
	linea[i]='\n';
	linea[i+1]='\0';
	//------------------------------------
	archivoSalida = fopen(nombreArchivo, "ab"); //APERTURA DE UN BINARIO EN MODO "AGREGAR AL FINAL"
	if(archivoSalida == NULL)
	{
		cout<<"Error."<<endl;
	}
	else{
		fwrite(&linea,strlen(linea), 1 , archivoSalida);
		fclose(archivoSalida);
		nro_inReg++;
	}
}
