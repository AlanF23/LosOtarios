#include <stdio.h>
#define N 3
#define M 5
int main(){
	
	int mat[N][M], i, j, mayor[N]={0}, menor[N]={0};
	for(i=0;i<N;i++){
		for (j=0;j<M;j++){
			printf("Ingrese el valor [%d][%d]: ",i+1,j+1);
			scanf("%d",&mat[i][j]);
		}
	}
	
	printf("\n Matriz cargada:\n");
	for(i=0;i<N;i++){
		
		for (j=0;j<M;j++){
			printf("%d\t",mat[i][j]);
			if(j==0){
				mayor[i]=mat[i][j];
				menor[i]=mat[i][j];
			}
			if(mayor[i]<mat[i][j]){
				mayor[i]=mat[i][j];
			}
			if(menor[i]>mat[i][j]){
				menor[i]=mat[i][j];
			}
		}
		printf("\n");
	}
	printf("\t\t Mayores \t Menores\n");
	for(i=0;i<N;i++){
		printf("Fila[%d]: \t %d \t\t %d\n",i+1,mayor[i],menor[i]);
	}
	
	return 0;
}
