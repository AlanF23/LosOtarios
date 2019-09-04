#include <iostream>
#define N 3
using namespace std;

int mat (int m[N][N]);

int main() 
{
	int i,j;
	int vec [N][N];
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			cout<<"Ingrese el elemento ["<<i<<"]["<<j<<"] : ";
			cin>>vec[i][j];
		}
		cout<<endl;
	}
	
	mat(vec);
	
	return 0;
}
int mat (int m[N][N])
{
	int cont=0;
	int i,j;
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if (m[i][j]%2==0 or m[i][j]%3==0)
			{
				cont++;
			}
		}
	}
	cout<<"La catnidad divisible por 2 o 3 es de: "<<cont;
}
