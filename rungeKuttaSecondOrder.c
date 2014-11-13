//
//  rungeKuttaSecondOrder.c
//  
//
//  Created by Juan Felipe Méndez on 14/10/14.
//
//

#include <stdio.h>
#include <stdlib.h>
#define BETA 8.0/3.0
#define RO 28
#define SIGMA 10

int main(void){
    
    double h, tmin,tmax;
    double *x;
    double *y;
    double *z;
    double *t;
    double xhalf, yhalf, zhalf, thalf;
    double xfunc, yfunc, zfunc;
    double xfuncmid, yfuncmid, zfuncmid;
    int j,i,n_points;
    

    
    h=0.01;
    tmin=0.0;
    tmax=3.0;
    n_points=(tmax-tmin)/h
    t=malloc(n_points*sizeof(double));
    x=malloc(n_points*sizeof(double));
    y=malloc(n_points*sizeof(double));
    z=malloc(n_points*sizeof(double));
    
    srand48(npoints);
    x[0]=10*drand48();
    y[0]=10*drand48();
    z[0]=10*drand48();
    
    for(i=1;i<n_points;i++){
        
        xfunc=SIGMA*(y[i-1]-x[i-1])
        yfunc =x[i-1]*(RO-z[i-1])-y[i-1]
        zfunc =x[i-1]*y[i-1]-BETA*z[i-1]
        
        thalf=x[i-1]+h/2.0;
        xhalf=x[i-1]+(h/2.0)*xfunc;
        yhalf=x[i-1]+(h/2.0)*yfunc;
        zhalf=x[i-1]+(h/2.0)*zfunc;
        
        xfuncmid =SIGMA*(yhalf-xhalf)
        yfuncmid =xhalf*(RO-zhalf)-yhalf
        zfuncmid =xhalf*yhalf-BETA*zhalf
        
        t[i]=t[i-1]+h;
        x[i]=x[i-1]+(h)*xfunc;
        y[i]=y[i-1]+(h)*yfunc;
        z[i]=z[i-1]+(h)*zfunc;
        
  
        
    }
    
    FILE *in;
    char filename[100]="solveEqi.dat";
    
    in =fopen(filename,"w");
    if(!in){
        printf("problems opening the file %s\n", filename);
        exit(1);
        
    }
    for(i=1;i<n_points;i++){
        
    fprintf(in, "%f\t%f\t%f \n", );
        
    
    }

}
