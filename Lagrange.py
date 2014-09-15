import numpy as np 

G=6.673*(10**(-11))
Mt=5.972*(10**24)
Ms=1.988*(10**30)
Rt=149598261000
w=((2*np.pi)/31556926)**2
Gl=G/(Rt**(3))

def my_funky(x):
    return ((Gl*Mt)/((1-x)**2)) - ((Gl*Ms)/(x**2))  + x*w**2
def funky_prime(x,h):
    return (my_funky(x+h) - my_funky(x-h))/(2.0*h)

n_points=10000000
x= np.linspace(-2, 2, n_points)
h=(x[1]-x[0])/1000000;
print h
print "\n"

print " el cero en L2 y su valor en la funcion"

x_guessL2 = 1.0000000001
while (abs(my_funky(x_guessL2)) > 1E-22):
    delta_x = -my_funky(x_guessL2)/funky_prime(x_guessL2,h)
    x_guessL2 = x_guessL2 + delta_x
print x_guessL2
print my_funky(x_guessL2)
print "\n"

print " el cero en L1 y su valor en la funcion"

x_guessL1 = 0.9999999999
while (abs(my_funky(x_guessL1)) > 1E-22):
    delta_x = -my_funky(x_guessL1)/funky_prime(x_guessL1,h)
    x_guessL1 = x_guessL1 + delta_x
print x_guessL1
print my_funky(x_guessL1)
print "\n"

print " el cero en L3 y su valor en la funcion"

x_guessL3 = -0.9999
while (abs(my_funky(x_guessL3)) > 1E-13):
    delta_x = -my_funky(x_guessL3)/funky_prime(x_guessL3,h)
    x_guessL3 = x_guessL3 + delta_x
print x_guessL3
print my_funky(x_guessL3)
print "\n"

L2=str(x_guessL2)
L1=str(x_guessL1)
L3=str(x_guessL3)
fo = open("puntos_lagrange.dat", "w")

fo.write(L1)
fo.write("\t")
fo.write("0 \n")
fo.write(L2)
fo.write("\t")
fo.write("0 \n")
fo.write(L3)
fo.write("\t")
fo.write("0 \n")

fo.close()
