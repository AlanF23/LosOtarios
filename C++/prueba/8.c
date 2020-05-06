#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int N, M, **mat, i, j, cpos=0, cneg=0, ccero=0, may=0, cmay=0;
	
	printf("Ingrese la cantidad de filas: ");
	scanf("%d",&N);
	printf("Ingrese la cantidad de columnas: ");
	scanf("%d",&M);
	
	mat=(int **)malloc(N*sizeof(int *));
	for(i=0;i<N;i++){
		mat[i]=(int *)malloc(M*sizeof(int));
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("Elemento[%d][%d]: ",i+1,j+1);
			scanf("%d",&mat[i][j]);
		}
	}
	printf("\nMatriz:\n");
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%d\t",mat[i][j]);
			if(mat[i][j]<0)
				cneg++;
			if(mat[i][j]>0)
				cpos++;
			if(mat[i][j]==0)
				ccero++;
			
			if(may<mat[i][j]){
				may=mat[i][j];
				cmay=0;
			}
			if(may==mat[i][j])
				cmay++;
		}
		printf("\n");
	}
	
	printf("Cantidad de elementos POSITIVOS: %d\n",cpos);
	printf("Cantidad de elementos NEGATIVOS: %d\n",cneg);
	printf("Cantidad de CEROS: %d\n",ccero);
	printf("El mayor elemento es %d y se repite %d veces.\n",may,cmay);
	
	for(i=0;i<N;i++){
		free(mat[i]);
	}
	free(mat);
}
