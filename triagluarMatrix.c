#include <stdio.h>
#include <stdlib.h>
float *load_matrixA(char *filename, int *n, int *m);
float *load_matrixB(char *filename, int *n, int *m);

int main(int argc, char **argv){
  float *matrix_A;
  float *matrix_B;
  float *x;
  int n_rowA, n_colsA;
  int i, j;
 int n_rowB, n_colsB;
 double producto=0;

  matrix_A = load_matrixA(argv[1], &n_rowA, &n_colsA);
  matrix_B = load_matrixB(argv[2], &n_rowB, &n_colsB);
  x=malloc(n_colsA*sizeof(double));

for(i=0;i<n_colsA;i++)
{
  x[i]=0;
}

 x[n_colsA-1]=(matrix_B[n_rowB-1])/matrix_A[(n_rowA-1)*n_colsA +(n_colsA-1)];
   
 for(i=1;i<n_rowA;i++){
   producto=0;
   for(j=0;j<n_colsA;j++){
     producto= producto + x[j]*matrix_A[(n_rowA-1-i)*n_colsA +j];
   }
   x[n_rowA-1-i]=(matrix_B[n_rowB-1-i]-producto)/matrix_A[(n_rowA-1-i)*n_colsA +(n_colsA-1-i)];
}

for(i=0;i<n_colsA;i++)
{
printf("%f \n", x[i]);  
 
}

}


float *load_matrixA(char *filename, int *n, int *m){
  float *matrix;
  FILE *in;
  int n_rowA, n_colsA;
  int i;
  int j;

  if(!(in=fopen(filename, "r"))){
    printf("Problem opening file %s\n", filename);
    exit(1);
  }

  fscanf(in, "%d %d\n", &n_rowA, &n_colsA);
  printf("%d %d\n", n_rowA, n_colsA);

  matrix = malloc(n_rowA * n_colsA * sizeof(float));

  for(i=0;i<n_rowA;i++){
    for(j=0;j<n_colsA;j++){
      fscanf(in, "%f", &matrix[i*n_colsA + j]);
    }
  }    
  *n = n_rowA;
  *m = n_colsA;
  return matrix;
}
float *load_matrixB(char *filename, int *n, int *m){
  float *matrix;
  FILE *in;
  int n_rowB, n_colsB;
  int i;
  int j;

  if(!(in=fopen(filename, "r"))){
    printf("Problem opening file %s\n", filename);
    exit(1);
  }

  fscanf(in, "%d %d\n", &n_rowB, &n_colsB);
  printf("%d %d\n", n_rowB, n_colsB);

  matrix = malloc(n_rowB * n_colsB * sizeof(float));

  for(i=0;i<n_rowB;i++){
    for(j=0;j<n_colsB;j++){
      fscanf(in, "%f", &matrix[i*n_colsB + j]);
    }
  }    
  *n = n_rowB;
  *m = n_colsB;
  return matrix;

}

