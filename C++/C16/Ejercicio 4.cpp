//a:datos del medidor de energia
//cd:consumos diarios
//dia:dia
//ca:contador de datos del medidor de energia
#include<iostream>
using namespace std;
int main () {
	int a,aax,cd,dia,ca;
	
	cd=0;
	dia=1;
	do {
		cout<<"Dia "<<dia<<endl;
		ca=a;
		a=0;
		cin>>a;
		cd=a+cd;
		dia++;
		cout<<aax<<endl;
		if (a<ca){
			cout<<"Los datos ingresados son menores a los del dia anterior"<<endl;
			cd=cd-a;
			dia=dia-1;
			a=aax;
		}
		aax=a;
	}
	while (a>0);
	cout<<"Consumo total "<<cd;
	return 0;
} 
