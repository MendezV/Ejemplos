#include <stdio.h>
#include <stdlib.h>

void print_walk(double *walk, int npoints);

  /*
en fopen se recibe el nombre del archivo y w,write r,read  a,apendice
   */
void print_walk(double *walk, int npoints){  
  FILE *fileout;
  int i;  
  fileout = fopen("my_walk.dat", "w");
  for(i=0;i< npoints;i++){
    fprintf(fileout, "%f\n", walk[i]);
  } 
  fclose(fileout);
}
Int main(int argc, char **argv){
  double random;
  int i,k;
  double x=0;
  int semilla;
  double *pasos;

semilla = atoi(argv[1]);
srand48(semilla);

 pasos =malloc(NPOINTS*sizeof(double));

    for(i=0;i<NPOINTS;i++){
      random = 2.0*drand48() - 1.0;
      x = x + random;
      pasos[i]=x;
    }
   
  
    void print_walk(pasos, NPOINTS);

  return 0;
}
