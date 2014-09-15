import numpy as np
import random

try:
    n_points=int(raw_input('Input:'))
except ValueError:
    print "Not a number"

Num = np.zeros(50)
Mean=np.zeros(50)
Meancuad=np.zeros(50)
stdev=np.zeros(50)

for i in range (0, n_points):
    s=0
    sx=0
    sy=0
    sz=0
    N=0
    k=0
    
    while (s<501):
        
        N+=1
        x = np.random.random()
        y = np.random.random()
        z = np.random.random()
    
        Norm= (x**2 +y**2+z**2)**(0.5)
    
        x=x/Norm
        y=y/Norm
        z=z/Norm
    
        sx= sx+x
        sy= sy+y
        sz= sz+z
    
        s=(sx**2 +sy**2 +sz**2)**0.5
        
        
        if ( s>=((k+1)*10)  ):
                   Meancuad[k]=Meancuad[k]+ (N**2)/n_points
                   Mean[k]=Mean[k]+ N/n_points
                   k+=1
                
                
    


for k in range (50):
    stdev[k]=(Meancuad[k] - Mean[k]**2)**(0.5)

for k in range (50):
    Num[k]=10*(k+1)



fo = open("Marcha3D.dat", "w")

for k in range (50):
    L1=str(Num[k])
    L2=str(Mean[k])
    L3=str(stdev[k])
    fo.write(L1)
    fo.write("\t")
    fo.write(L2)
    fo.write("\t")
    fo.write(L3)
    fo.write("\n")

fo.close()
