#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool cargar();
bool mostrar();

bool cargarA();
bool mostrarA();

int main()
{
	char opc;
	bool bandera=false, bandera1=false;
	
	do
	{
		cout<<"1.-Cargar archivo."<<endl;
		cout<<"2.-Aprobados."<<endl;
		cout<<"S.-Salir"<<endl;
		cout<<endl<<"Digite una opcion: ";
		cin>>opc;
		
		cin.get();
		
		switch (opc)
		{	
			case '1':
			{
				bandera = cargar();
				
				if(bandera==true)
				{
					cout<<"Gestion exitosa."<<endl<<endl;
				}
				else
				{
					cout<<"Error en la gestion."<<endl;
				}
				
				break;
			}
			case '2':
			{
				bandera=false;
				
				bandera = cargarA();
				
				bandera1 = mostrarA();
				
				if(bandera==true and bandera1==true)
				{
					cout<<"Gestion exitosa."<<endl<<endl;
				}
				else
				{
					cout<<"Error en la gestion."<<endl;
				}
				
				break;
			}
			case 's':
			{
				cout<<endl<<"Gracias."<<endl;
				break;
			}
			case 'S':
			{
				cout<<endl<<"Gracias."<<endl;
				break;
			}
			default:
			{
				cout<<endl<<"Opcion incorrecta."<<endl;
				break;
			}
		}
		
	} while(opc!='s' and opc!='S');
	
	return 0;
}

bool cargar()
{
	bool bandera=false;
	ofstream archivo;
	string texto;
	
	archivo.open("registro.txt");
	
	if(archivo.fail())
	{
		cout<<"\nHubo un error al crear el archivo."<<endl;
	}
	else
	{
		cout<<endl<<"Ingrese el texto que desea agregar..."<<endl<<"Terminara cuando ingrese la palabra [fin] "<<endl<<endl;
		do
		{
			cout<<"--> ";
			getline(cin,texto);
			
			if(texto!="fin")
			{
				archivo<<texto<<endl;
			}
			
		} while(texto!="fin");
	}
	
	archivo.close();
	
	return (bandera = mostrar());
	
}
bool mostrar()
{
	ifstream archivo;
	string contenido;
	
	archivo.open("registro.txt", ios::in);
	
	if(archivo.fail())
	{
		cout<<"\nHubo un error al abrir el archivo."<<endl;
		return (false);
	}
	else
	{
		cout<<endl<<endl<<"El contenido del archivo es: "<<endl;
		while(!archivo.eof())
		{
			getline(archivo,contenido);
			cout<<"---> "<<contenido<<endl;
		}
		return (true);
	}
	
	archivo.close();
	
}

bool cargarA()
{
	ofstream alumnos;
	string nombre;
	int nota;
	
	alumnos.open("aprobados.txt");
	
	if(alumnos.fail())
	{
		cout<<"\nHubo un error al crear el archivo."<<endl;
		return (false);
	}
	else
	{
		cout<<endl;
		
		alumnos<<"NOMBRE:"<<"\t"<<"NOTA:"<<endl;
		
		for(int i=0;i<3;i++)
		{
			cout<<endl<<"Ingrese el nombre del alumno ["<<i+1<<"] "<<endl; cout<<"---> ";
			getline(cin, nombre);
			
			cout<<endl<<"Digite su nota: ";
			cin>>nota;
			
			cin.get();
			
			if(nota>=6)
			{
				alumnos<<nombre<<"\t"<<nota<<endl;
			}
		}
		return (true);
	}
	
	alumnos.close();
	
}

bool mostrarA()
{
	ifstream alumno;
	string contenido;
	
	alumno.open("aprobados.txt", ios::in);
	
	if(alumno.fail())
	{
		cout<<"\nHubo un error al abrir el archivo."<<endl;
		return (false);
	}
	else
	{
		cout<<endl<<endl<<"El contenido del archivo es: "<<endl;
		while(!alumno.eof())
		{
			getline(alumno, contenido);
			cout<<contenido<<endl;
		}
		return (true);
	}
	
	alumno.close();
	
}
