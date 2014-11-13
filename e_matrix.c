/*recibe un archivo en el que hay una matriz
la primera fila del archivo contiene el numero de filas y de columnas de la matriz,exponencia la matriz*/

#include <stdio.h>
#include <stdlib.h>
float *load_matrix(char *filename, int *n, int *m);
int main(int argc, char **argv){
  float *matrix_A;
  float *matrix_C;
  float *matrix_e;
  float *matrix_M;
  int n_row, n_cols;
  int i, j, k,l,r, n,h;

  /*trampa para generar tres matrices del mismo tamaño con el mismo archivo*/

  matrix_A = load_matrix(argv[1], &n_row, &n_cols);
  matrix_C = load_matrix(argv[1], &n_row, &n_cols);
  matrix_e = load_matrix(argv[1], &n_row, &n_cols); 
  matrix_M = load_matrix(argv[1], &n_row, &n_cols);


for(i=0;i<n_row;i++){
    for(j=0;j<n_cols;j++){
      matrix_e[i*n_cols + j]=0.0;
      matrix_M[i*n_cols + j]=0.0;
 }
}


for(i=0;i<n_row;i++){
    
     matrix_e[i*n_cols + i]=1.0;
     matrix_C[i*n_cols + i]=1.0;
 
}


/*suma l terminos en la exponencial que van despues de la identidad*/
for(l=0;l<19;l++){
  n=1;
 
 for(i=0;i<n_row;i++){
    for(j=0;j<n_cols;j++){
      matrix_C[i*n_cols + j]=0.0;
 }
}
for(i=0;i<n_row;i++){

     matrix_C[i*n_cols + i]=1.0;
 
}


  /*genera la matriz a la r */
  for(r=0;r<(l+1);r++){
    for(i=0;i<n_row;i++){
      for(j=0;j<n_cols;j++){
       
	for(k=0;k<n_cols;k++){
             matrix_M[i*n_cols + j] =matrix_M[i*n_cols + j] + matrix_C[i*n_cols + k]*matrix_A[k*n_cols + j];
	    }
   
      }
     } 
    
    
    for(h=0;h<n_row;h++){
	  for(k=0;k<n_cols;k++){
	    matrix_C[h*n_cols + k]= matrix_M[h*n_cols + k];	
       	    matrix_M[h*n_cols + k]=0.0;
	  }
	}
  }

  
/*genera el factorial*/
  for(i=1;i<(l+2);i++){
    n=n*i;
   }
 
 /*suma el termino a la exponencial*/
  for(i=0;i<n_row;i++){
      for(j=0;j<n_cols;j++){ 
	matrix_e[i*n_cols + j]= matrix_e[i*n_cols + j]+ matrix_C[i*n_cols + j]/n;
    }   
  }

}

/*imprime*/
 for(i=0;i<n_row;i++){
    for(j=0;j<n_cols;j++){
      printf(" %f ", matrix_e[i*n_cols + j]);
    }
    printf("\n");
  }
    printf("\n");

}

float *load_matrix(char *filename, int *n, int *m){
  float *matrix;
  FILE *in;
  int n_row, n_cols;
  int i;
  int j;

  if(!(in=fopen(filename, "r"))){
    printf("Problem opening file %s\n", filename);
    exit(1);
  }

  fscanf(in, "%d %d\n", &n_row, &n_cols);
  /*
  printf("%d %d\n", n_row, n_cols);
  */
  matrix = malloc(n_row * n_cols * sizeof(float));

  for(i=0;i<n_row;i++){
    for(j=0;j<n_cols;j++){
      fscanf(in, "%f", &matrix[i*n_cols + j]);
    }
  }    
  *n = n_row;
  *m = n_cols;
  return matrix;
}
