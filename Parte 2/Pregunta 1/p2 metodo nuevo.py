from sympy import *
import math
import warnings
warnings.filterwarnings("ignore")

# Funcion para calcular ceros de funcion
# Entradas: 
#       funcion : la funcion
#       valorInicial : estimacion del cero
#       tolerancia : error maximo
#       iterMax : iteraciones maximas
# Salidas:
#       [cero aproximado, iteraciones, error]
def metodo_nuevo(funcion, valorInicial, tolerancia, iterMax):
    # Se establece el simbolo x
    x = symbols("x")
    # Se calcula la derivada
    funcion = sympify(funcion)
    derivada = diff(funcion, x)

    # Se convierten a funciones de python
    funcion = lambdify(x, funcion)
    derivada = lambdify(x, derivada)

    # Se inicializan los valores de la iteración
    x_n = valorInicial
    k = 0
    try:
        while abs(funcion(x_n)) > tolerancia and k<iterMax:
            
            # Se realiza un calculo auxiliar
            xdx = funcion(x_n)/derivada(x_n)
            # Se calcula y_n
            y_n = x_n-xdx*(1-xdx**5)
            # Se realizan calculos auxiliares
            ydx = funcion(y_n)/derivada(x_n)
            yx = funcion(y_n)/funcion(x_n)
            # Se calcula z_n
            z_n = y_n-ydx*(1-yx)**-2
            # Se realizan calculos auxiliares
            zdx = funcion(z_n)/derivada(x_n)
            zy = funcion(z_n)/funcion(y_n)
            zx = funcion(z_n)/funcion(x_n)
            # Se calcula x_n
            x_n= z_n-zdx*(1+yx**2+zy)/(1-yx-zx)**2
            # Se aumenta el numero de iteracion
            k+=1
    except:
        pass

    # Se intenta devolver los valores, si hay un "OverFlow" es porque el error es muy grande
    try:
        if(not math.isnan(x_n)):
            return [x_n, k, funcion(x_n)]
        else:
            return [float('inf'), k, float('inf')]
    except OverflowError:
        return [x_n, k, float('inf')]

def prueba():
    # Prueba con 10x*exp(-x^2)-1
    [xn, k, error] = metodo_nuevo("10*x*exp(-x^2)-1", 1.5, 10**-8,100)
    print("Error: " + str(error) + " | Iteraciones : " + str(k) + " |  Cero: " + str(xn))
    # Prueba con x^5+x^4+4*x^2-15
    [xn, k, error] = metodo_nuevo("x^5+x^4+4*x^2-15", 1.5, 10**-8,100)
    print("Error: " + str(error) + " | Iteraciones : " + str(k) + " |  Cero: " + str(xn))
    # Prueba con x*exp(x^2)-(sin(x))^2+3*cos(x)+5
    [xn, k, error] = metodo_nuevo("x*exp(x^2)-(sin(x))^2+3*cos(x)+5", 0, 10**-8,100)
    print("Error: " + str(error) + " | Iteraciones : " + str(k) + " |  Cero: " + str(xn))
    # Prueba con 11*x^11-1
    [xn, k, error] = metodo_nuevo("11*x^11-1", 1.5, 10**-8,100)
    print("Error: " + str(error) + " | Iteraciones : " + str(k) + " |  Cero: " + str(xn))
    # Prueba con sin(3*x)+x*cos(x)
    [xn, k, error] = metodo_nuevo("sin(3*x)+x*cos(x)", 1.5, 10**-8,100)
    print("Error: " + str(error) + " | Iteraciones : " + str(k) + " |  Cero: " + str(xn))

    return

def __main__():
    prueba()

__main__()