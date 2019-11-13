#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;



void menu();
int ingdes();
void ingresar(int);
void desencr(int);
int main()
{
	
	menu();
	
	return 0;
}

void menu()
{
	char opc;
	int a;
	do
	{
		cout<<endl;
		cout<<"1.-Ajustar clave de encriptado."<<endl;
		cout<<"2.-Encriptar un archivo de texto."<<endl;
		cout<<"3.-Desencriptar un archivo de texto."<<endl;
		cout<<"S.-SALIR."<<endl;
		cout<<"\nIngrese una opcion: ";
		
		cin>>opc;
		cin.get();
		
		switch (opc)
		{
			case '1':
			{
				a=ingdes();
				break;
			}
			case '2':
			{
				ingresar(a);
				break;
			}
			case '3':
			{
				desencr(a);
				break;
			}
			case 's':
			{
				cout<<"\nGRACIAS."<<endl;
				break;
			}
			case 'S':
			{
				cout<<"\nGRACIAS."<<endl;
				break;
			}
		}
	}
	while(opc!='s' or opc!='S');
}

int ingdes()
{
	int desplazamiento;
	
	cout<<"\nIngrese el desplazamiento para encripar el texto: ";
	cin>>desplazamiento;
	cin.get();
	return(desplazamiento);
}

void ingresar(int x)
{
	string texto, contenido, texto1;
	ofstream archivo;
	
	archivo.open("texto.txt");
	
	if(archivo.fail())
	{
		cout<<endl<<"Ha habido un error al crear el archivo."<<endl;
	}
	
	cout<<"\nIngrese el texto que desea encriptar."<<endl;
	cout<<"-->";
	getline(cin,texto);
	archivo<<texto<<endl;
	
	archivo.close();
	
	ifstream archivo3;
	archivo3.open("texto.txt", ios::in);
	
	ofstream archivo1;
	archivo1.open("encriptado.txt",ios::out);
	
	
	while(!archivo3.eof())
	{
		getline(archivo3, texto1);
		for(int i=0; i<texto.size();i++)
		{
			//cout<<char((texto[i]+(x)));
			texto1[i]=char(int(texto[i])+(x));
			//cout<<endl<<texto1[i]<<endl;
		}
		archivo1<<texto1<<endl;
	}

	archivo1.close();
	archivo3.close();
}
void desencr(int x)
{
	string nombre, contenido, la;
	/*cout<<"Ingrese el nombre del archivo encriptado."<<endl;
	cout<<"--> ";
	getline(cin, nombre);*/
	
	ifstream archivo;
	archivo.open("encriptado.txt", ios::in);
	
	getline(archivo, contenido);
	
	ofstream archivo1;
	archivo1.open("desencriptado.txt", ios::out);
	
	while(!archivo.eof())
	{
		getline(archivo, la);
		for(int i=0;i<contenido.size();i++)
		{
			//cout<<endl<<contenido;
			la[i]=char(int(contenido[i])-x);
			//cout<<endl<<la;
		}
		archivo1<<la<<endl;
	}
	
	archivo.close();
	archivo1.close();
	
}
