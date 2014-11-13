#include <stdio.h>
#include <stdlib.h>
float *load_matrix(char *filename, int *n, int *m);
int main(int argc, char **argv){
  float *matrix_A;
  float *matrix_B;
  float *matrix_C;
  int n_rowA, n_colsA;
  int i, j,k;

  matrix_A = load_matrix(argv[1], &n_rowA, &n_colsA);
  matrix_C = malloc(n_colsA * n_rowA * sizeof(float));
    

for(i=0;i<n_rowA;i++){
    for(j=0;j<n_colsA;j++){
      matrix_C[j*n_rowA + i]=matrix_A[i*n_colsA + j];
      printf(" %f ", matrix_C[j*n_rowA + i]);
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

