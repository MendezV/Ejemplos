#include <stdio.h>
#include <stdlib.h>

void make_walk(double *walk, int npoints, int k);
void print_walk(double *walk, int numerodemarchas);

void print_walk(double *walk, int numerodemarchas){  
  FILE *fileout;
  int i;  
  fileout = fopen("my_walk.dat", "w");
  for(i=0;i< numerodemarchas;i++){
    fprintf(fileout, "%f\n", walk[i]);
  } 
  fclose(fileout);
}

int main(int argc, char **argv){
  double *walk;
  int n_points;
  int k;
  int numerodemarchas=100000;

  n_points = atoi(argv[1]);  

  walk = malloc(numerodemarchas * sizeof(double));
  
for(k=0;k<numerodemarchas;k++){
  make_walk(walk, n_points, k);
}
  print_walk(walk, numerodemarchas);

  return 0;
}
void make_walk(double *walk, int n_points, int k){
  double x=0.0;
  int i;  
  for(i=0;i<=n_points;i++){
    x = x + 2.0*(drand48()-0.5);
  } 
  walk[k]=x;
}
