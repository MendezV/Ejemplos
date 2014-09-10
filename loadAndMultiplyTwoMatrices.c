#include <stdio.h>
#include <stdlib.h>
float *load_matrix(char *filename, int *n, int *m);
int main(int argc, char **argv){
  float *matrix_A;
  float *matrix_B;
  float *matrix_C;
  int n_row, n_cols;
  int i, j,k;

  matrix_A = load_matrix(argv[1], &n_row, &n_cols);
  matrix_B = load_matrix(argv[2], &n_row, &n_cols);
  matrix_C = load_matrix(argv[2], &n_row, &n_cols);


for(i=0;i<n_row;i++){
    for(j=0;j<n_cols;j++){
      matrix_C[i*n_cols + j]=0.0;
        for(k=0;k<n_cols;k++){
             matrix_C[i*n_cols + j] =matrix_C[i*n_cols + j]+matrix_A[i*n_cols + k]*matrix_B[k*n_cols + j];
}
 printf(" %f ", matrix_C[i*n_cols + j]);
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
  printf("%d %d\n", n_row, n_cols);

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
