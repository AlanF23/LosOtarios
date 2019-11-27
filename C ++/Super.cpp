#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

struct datos
{
	string nombre, estado;
	int cantidad;
	float preciou;
	datos *siguiente, *anterior;
}*primero, *ultimo;

void cargar(datos *&, string, string, int, float);
void mostrarm(datos *);
void mostrarp(datos *);
void cargarA(datos *);
void cargarM(datos *);
void cargarP(datos *);

int main()
{
	datos *lista=NULL;
	char opc;
	string nombre1, estado1;
	int cantidad1;
	float precio;
	int opc1=0;
	
	do
	{
		cout<<"1.-Ingresar datos de un cliente. "<<endl;
		cout<<"2.-Mostrar los morosos."<<endl;
		cout<<"3.-Mostrar los que han pagado pero con cantidad mayor a 20."<<endl;
		cout<<"4.-Cargar los datos en un archivo de texto."<<endl;
		cout<<"(S) o (s).-Salir."<<endl;
		
		cout<<endl<<"Ingrese una opcion: ";
		cin>>opc;
		
		cin.get();
		
		switch (opc)
		{
			case '1':
			{
				cout<<endl<<"Ingrese el nombre del cliente: ";
				getline(cin, nombre1);
				cout<<endl<<"Ingrese la cantidad de productos que compro: ";
				cin>>cantidad1;
				cin.get();
				cout<<endl<<"Ingrese el precio unitario del producto: ";
				cin>>precio;
				cin.get();
				do
				{
					cout<<endl<<"Ingrese el estado del cliente [moroso] o [pagado]: ";
					getline(cin,estado1);
				} while(estado1 != "moroso" and estado1 != "pagado");
				
				cargar(lista, nombre1, estado1, cantidad1, precio);
				break;
			}
			case '2':
			{
				mostrarm(lista);
				break;
			}
			case '3':
			{
				mostrarp(lista);
				break;
			}
			case '4':
			{
				cout<<endl<<endl<<"----> ¡PRECAUCION, SI ELIJE UNA OPCION EL RESTO YA NO FUNCIONA, DISCULPE LAS MOLESTIAS! <-----"<<endl<<endl;
				cout<<endl<<"1.-Cargar todos los clientes."<<endl;
				cout<<"2.-Cargar solo los morosos y pagados por separado."<<endl;
				
				do
				{
					cout<<endl<<"Ingrese una opcion: ";
					cin>>opc1;
				} while(opc1<1 and opc1>3);
				
				switch (opc1)
				{
					case 1:
					{
						cargarA(lista);
						break;
					}
					case 2:
					{
						cargarM(lista);
						break;
					}
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
				cout<<endl<<"Opcion Incorrecta."<<endl<<endl;
				break;
			}
		}
	} while(opc!='s' and opc!='S');
	
	return 0;
}
void cargar(datos *&lista1, string name, string esta, int cant, float pre)
{
	datos *nuevo=(datos *) malloc (sizeof(datos));//reserva espacio de memoria del tipo struct que creamos
	
	nuevo->nombre=name;
	nuevo->estado=esta;
	//asigna los datos de los clientes a la lista
	nuevo->cantidad=cant;
	nuevo->preciou=pre;
	
	if(primero==NULL)//pregunta si la lista esta vacia
	{
		primero=nuevo;
		nuevo->siguiente=NULL;
		//establece los extremos de la lista
		nuevo->anterior=NULL;
		ultimo=primero;
	}
	else//si no esta vacia
	{
		ultimo->siguiente=nuevo;
		nuevo->siguiente=NULL;
		nuevo->anterior=ultimo;
		ultimo=nuevo;
	}
	cout<<endl<<endl;
}
void mostrarm(datos *lista1)
{
	datos *aux=primero;//crea un auxiliar para recorrer la lista sin modificar ningun dato
	
	cout<<endl<<"Los clientes que han morosos son: "<<endl<<endl;
	
	if(primero!=NULL)//si la lista no esta vacia, recorre
	{
		while(aux!=NULL)//recorre mientras la lista no llegue al ultimo dato
		{
			if(aux->estado == "moroso")//pregunta si el estado del cliente es moroso, para mostrar
			{
				cout<<"Nombre: ";
				cout<<aux->nombre<<endl;
				cout<<"Cantidad de producto: ";
				cout<<aux->cantidad<<endl;
				cout<<"Precio unitario: ";
				cout<<aux->preciou<<endl;
			}
			aux=aux->siguiente;//avanza una posicion
			cout<<endl;
		}
	}
	cout<<endl<<endl;
}
void mostrarp(datos *lista1)
{
	datos *aux=primero;
	
	cout<<endl<<"Los clientes que han pagado son: "<<endl<<endl;
	
	if(primero!=NULL)
	{
		while(aux!=NULL)
		{
			if(aux->estado == "pagado")
			{
				cout<<"Nombre: ";
				cout<<aux->nombre<<endl;
				cout<<"Cantidad de producto: ";
				cout<<aux->cantidad<<endl;
				cout<<"Precio unitario: ";
				cout<<aux->preciou<<endl;
			}
			aux=aux->siguiente;
			cout<<endl;
		}
	}
	cout<<endl<<endl;
}
void cargarA(datos *lista2)
{
	datos *aux=primero;//crea un auxiliar para recorrer la lista
	
	ofstream archivo;//crea un archivo
	
	string uno, cuatro;
	int dos=0; float tres=0;
	
	archivo.open("Datos.txt");//abre el archivo con el nombre que le indiquemos
	
	if(archivo.fail())//pregunta si hubo algun problema al abrir el archivo
	{
		cout<<endl<<"Hubo un problema al abrir el archivo."<<endl<<endl;
		exit(1);
	}
	else
	{
		archivo<<"Nombre: "<<"\t"<<"Cantidad: "<<"\t"<<"Precio Unitario: "<<"\t"<<"Estado: "<<endl;//pone un titulo 
		
		while(aux!=NULL)//recorre la lista
		{
			uno=aux->nombre;
			dos=aux->cantidad;
			//asigna los datos de la lista a variables auxiliares
			tres=aux->preciou;
			cuatro=aux->estado;
			
			archivo<<uno<<"\t"<<"\t"<<dos<<"\t"<<"\t"<<tres<<"\t"<<"\t"<<"\t"<<cuatro<<"\t"<<endl;//ingresa los datos al archivo de texto
			
			primero=primero->siguiente;//avanza una posicion
			aux=primero;
		}
	}
	archivo.close();
}
void cargarM(datos *lista2)
{
	datos *aux=primero;
	
	ofstream archivo, archivo1;
	
	string uno, cuatro;
	int dos=0; float tres=0;
	
	archivo.open("Morosos.txt");
	//abre dos archivos para acomodar los morosos y pagados
	archivo1.open("Pagados.txt");
	
	if(archivo.fail() or archivo1.fail())//pregunta si no hubo ningun problema al abrir
	{
		cout<<endl<<"Hubo un problema al abrir el archivo."<<endl<<endl;
		exit(1);
	}
	else
	{
		archivo<<"Nombre: "<<"\t"<<"Cantidad: "<<"\t"<<"Precio Unitario: "<<"\t"<<"Estado: "<<endl;
		//asigna un titulo a los archivos
		archivo1<<"Nombre: "<<"\t"<<"Cantidad: "<<"\t"<<"Precio Unitario: "<<"\t"<<"Estado: "<<endl;
		
		while(aux!=NULL)//recorre la lista
		{
			if(aux->estado == "moroso")//si el cliente esta moroso, lo agrega a un archivo
			{	
				uno=aux->nombre;
				dos=aux->cantidad;
				tres=aux->preciou;
				cuatro=aux->estado;
				
				archivo<<uno<<"\t"<<"\t"<<dos<<"\t"<<"\t"<<tres<<"\t"<<"\t"<<"\t"<<cuatro<<"\t"<<endl;
			}
			else//si esta pago lo agrega a otro archivo
			{
				uno=aux->nombre;
				dos=aux->cantidad;
				tres=aux->preciou;
				cuatro=aux->estado;
				
				archivo1<<uno<<"\t"<<"\t"<<dos<<"\t"<<"\t"<<tres<<"\t"<<"\t"<<"\t"<<cuatro<<"\t"<<endl;
			}
			primero=primero->siguiente;
			aux=primero;
		}
	}
	archivo.close();
	//cierra los archivos
	archivo1.close();
}
