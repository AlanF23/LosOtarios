#include <iostream>
#include <fstream>


using namespace std;

void cargar();
void cargar1();
void mostrar();
void ingresar();

int main()
{
	char opc;
	
	do
	{
		cout<<"1.Ingresar un texto en el archivo."<<endl;
		cout<<"2.Mostrar el texto del archivo."<<endl;
		cout<<"3.Ingresar texto al final del archivo."<<endl;
		cout<<"4.Copiar un archivo en otro. (en mantenimiento)"<<endl;
		cout<<"5.Salir."<<endl;
		cout<<"\nIngrese una opcion: ";
		cin>>opc;
		getchar();
		switch (opc)
		{
		case '1':
		{
			cargar();
			break;
		}
		case '2':
		{
			mostrar();
			break;
		}
		case '3':
		{
			ingresar();
			break;
		}
		case '4':
		{
			//cargar1();
			break;
		}
		case '5':
		{
			cout<<"\nGracias.";
			break;
		}
		default:
		{	
			cout<<"Opcion mala."<<endl;
			break;
		}
		}
	} while(opc!='5');
	
	
	return 0;
}
void cargar()
{
	ofstream archivo;
	string linea, contenido;
	
	ifstream archivo1;
	string contenido1, nombre;
	
	archivo.open("Minombre");
	
	if(archivo.fail())
	{
		cout<<"Ha habido un error al crear el archivo."<<endl;
	}
	cout<<"Ingrese su nombre: ";
	getline(cin, linea);
	archivo<<linea<<endl;
	
	archivo.close();
}
void cargar1()
{
	ofstream archivo;
	string linea, contenido;
	
	ifstream archivo1;
	string contenido1, nombre;
	
	archivo.open("Minombre1");
	
	if(archivo.fail())
	{
		cout<<"Ha habido un error al crear el archivo."<<endl;
	}
	cout<<"Ingrese su nombre1: ";
	getline(cin, linea);
	archivo<<linea<<endl;
	
	archivo.close();
}
void mostrar()
{
	ifstream archivo1;
	string nombre, contenido1;
	cout<<"Ingrese la ubicacion y nombre del archivo para abrir: ";
	cin>>nombre;
	
	archivo1.open(nombre,ios::in);
	
	while(!archivo1.eof())
	{
		getline(archivo1, contenido1);
		cout<<endl<<contenido1;
	}
}
void ingresar()
{
	string nombre, contenido;
	ofstream archivo;
	
	
	cout<<"	Ingrese la direccion y el nombre del archivo para ingresar el nuevo texto al final."<<endl;
	cout<<"-->";
	cin>>nombre;
	
	archivo.open(nombre, ios::app);
	cin.get();
	
	if(archivo.fail())
	{
		cout<<"\nNo se pudo abrir el archivo."<<endl;
	}
	cout<<"\nIngrese el texto a agregar el final del archivo: ";
	getline(cin, contenido);
	archivo<<contenido<<endl;
	
	archivo.close();
	
}
/*void copiar()
{
	ofstream archivo, archivo2, archivo3;
	string contenido;
	
	archivo.open("Minombre.txt");
	archivo2.open("Minombre1.txt");
	archivo2.open("Minombre1.txt", ios::app);
	while(!archivo.eof())
	{
		getline(archivo2, contenido);
		archivo3<<contenido<<endl;
	}
	
	
}*/
