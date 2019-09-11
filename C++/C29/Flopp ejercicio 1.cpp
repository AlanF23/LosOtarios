#include <iostream>
using namespace std;
int vec1[10];
int * a;
int main(int argc, char *argv[]) {
	for (int i = 0;i<10;i++){
		vec1[i]=i;
	}
	a = vec1;
	
	for (int i = 0;i<10;i++){
		if(vec1[i]%2==0){
			cout<<"El elemento: "<<*a<<" es par, con posicion: "<<a<<endl;
			a++;
		}
		else{
			cout<<"El elemento: "<<*a<<" es impar, con posicion: "<<a<<endl;
		a++;
		}
	}
	
	return 0;
}
