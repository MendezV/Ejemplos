#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float *load_matrix(char *filename, int *n, int *m);
int main(int argc, char **argv){
  float *matrixCH;
  float *Lematrix;
  int n, n1;
  int i, j,k;
  double sum;

  matrixCH = load_matrix(argv[1], &n, &n1);
  Lematrix = malloc (n*n*sizeof(double));
 
  Lematrix[0*n +0]= sqrt(matrixCH[0*n + 0]);
 for(i=0;i<n;i++){
    Lematrix[i*n + 0]= matrixCH[i*n + 0]/Lematrix[0*n +0];
    }


 for(i=1;i<n;i++){
    for(j=1;j<i+1;j++){
      
      sum=0;
      for(k=0;k<j;k++){
	sum= sum +  Lematrix[i*n + k]* Lematrix[j*n + k];
      }
  
      if(j==i){
	Lematrix[i*n + j]=sqrt(matrixCH[i*n + j]-sum);
    }
      else{
	Lematrix[i*n + j]=(matrixCH[i*n + j]-sum)/Lematrix[j*n + j];
      }
 
   }
  }


for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf(" %f ", Lematrix[i*n + j]);
    }
    printf("\n");
  }
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
