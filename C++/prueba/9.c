#include<stdio.h>
#define N 10
#define M 2
int main(){
	
	int mat[N][M]={0}, j, i, clib, total=0;
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(j==0){
				do{
					printf("Estado butaca [%d] (1/0): ",i+1);
					scanf("%d",&mat[i][j]);
					if(mat[i][j]!=0&&mat[i][j]!=1)
						printf("Error. Estado invalido.\n");
				} while(mat[i][j]!=0&&mat[i][j]!=1);
			}
			if(j==1){
				do {
					printf("Tarifa butaca [%d]: ",i+1);
					scanf("%d",&mat[i][j]);
					if(mat[i][j]<0)
						printf("Error. Tarifa invalida.\n");
				} while(mat[i][j]<0);
			}
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(j==0){
				if(mat[i][j]==0)
					clib++;
			}
			if(j==1){
				total+=mat[i][j];
			}
		}
	}
	printf("Cantidad de asientos ocupados: %d\n",N-clib);
	printf("Cantidad de asientos libres: %d\n",clib);
	printf("Importe total cobrado: %d\n",total);
}
