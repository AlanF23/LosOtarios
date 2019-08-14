#include <iostream>
#include <stdlib.h>
#define N 10
using namespace std;

int main() 
{
	char name[N];
	int i, cont=0, cont2=0;
	char *pname[N];
	cout<<"Ingrese su name: ";
	cin.get(name,N);
	
	for (i=0;i<N;i++)
	{
		pname[i] = &name[i];
	}
	
	cout<<'\n'<<"Your name is: "<<*pname;
	
	for (i=0;i<N;i++)
	{
		if (name[i]=='a' or name[i]=='e' or name[i]=='i' or name[i]=='o' or name[i]=='u')
		{
		cont++;
		}
		if (name[i]=='A' or name[i]=='E' or name[i]=='I' or name[i]=='O' or name[i]=='U')
		{
			cont2++;
		}
	}
	cout<<'\n'<<"Your name tiene: "<<(cont+cont2)<<" vocales";
	return 0;
}
