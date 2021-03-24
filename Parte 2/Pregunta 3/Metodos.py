import numpy as np
from sympy import *
from math import *
import warnings
warnings.filterwarnings("ignore")
'''Implementacion del metodo de Biseccion para aproximar el cero de una funcion
   Entradas:
     --->f: Funcion de la cual se quiere saber el 0.
     --->a:Limite inferior del intervalo a considerar.
     --->b:Limite superior del intervalo a considerar
     --->tol:Valor maximo que puede alcanzar f(xk) para considerarse una aproximacion satisfactoria.
     --->iterMax: Maximo de iteraciones que puede ejecutar el metodo para llegar a la aproximacion.
   Salidas:
     --->xk: Aproximacion obtenida por el metodo
     --->iteraciones: Iteraciones realizadas para llegar a la aproximacion anterior
     --->|f(x)|: Error de f(xk) respecto al valor real de x que hace que f(x) sea 0.
'''
def biseccion(f,a,b,tol,iterMax):
    # Verificacion para saber si la tolerancia es negativa.
    if (tol <= 0):
        print("La tolerancia debe de ser mayor a 0")
        return (None, None, None)

    # Bloque de codigo para convertir la funcion F en simbolica.
    x = Symbol('x')
    f= lambdify(x,f)
    iteraciones,xk=0,0

    #Verificacion inicial del Teorema de Bolzano
    if(f(a)*f(b)<0):
        # Ciclo iterativo que permite realizar las iteraciones del metodo.
        while(iteraciones<iterMax):
            xk=(a+b)/2
            #Verificacion de xk como solucion
            if(abs(f(xk))<tol):
                break
            #Verificacion del teorema de Bolzano para los nuevos intervalos
            if(f(a)*f(xk)<0):
                b=xk
            elif(f(xk)*f(b)<0):
                a=xk
            iteraciones+=1
        return (xk,iteraciones,abs(f(xk)))
    else:
        print("No se puede aplicar el metodo de la biseccion a esta funcion")
        return(None,None,None)


'''Implementacion del metodo de Falsa Posicion para aproximar el cero de una funcion
   Entradas:
     --->f: Funcion de la cual se quiere saber el 0.
     --->a:Limite inferior del intervalo a considerar.
     --->b:Limite superior del intervalo a considerar
     --->tol:Valor maximo que puede alcanzar f(xk) para considerarse una aproximacion satisfactoria.
     --->iterMax: Maximo de iteraciones que puede ejecutar el metodo para llegar a la aproximacion.
   Salidas:
     --->xk: Aproximacion obtenida por el metodo
     --->iteraciones: Iteraciones realizadas para llegar a la aproximacion anterior
     --->|f(x)|: Error de f(xk) respecto al valor real de x que hace que f(x) sea 0.
'''
def falsa_posicion(f,a,b,tol,iterMax):
    # Verificacion para saber si la tolerancia es negativa.
    if (tol <= 0):
        print("La tolerancia debe de ser mayor a 0")
        return (None, None, None)
    #Bloque de codigo para convertir f en una funcion simbolica y verificar que la funcion no sea una cosntante.
    f = sympify(f)
    if (f.diff() == 0):
        print("Esta funcion no tiene cero")
        return (str(f), 0, str(f))

    #Bloque de codigo para definir fAux que sera la funcion iterativa del metodo de la Secante.
    x_0, x_1, x = symbols("x_0,x_1,x")
    fx0, fx1 = f.subs(x, x_0), f.subs(x, x_1)
    fAux = lambdify([x_0, x_1], x_1 - ((x_1 - x_0) / (fx1 - fx0)) * fx1)

    f = lambdify(x, f)

    #Verificacion inical del teorema de Bolzano
    if(f(a)*f(b)<0):
        xk,iteraciones=0,0

        # Ciclo iterativo que permite realizar las iteraciones del metodo.
        while(iteraciones<iterMax):
            '''Verificacion para saber si sellego a una solucion satisfactoria o para saber si el denominador de la funcion iterativa se indefiniria 
               en la presente iteracion'''
            if (abs(f(xk)) < tol or f(b) - f(a) == 0):
                break;

            xk = fAux(a, b)

            #Verificacion del teorema de Bolzano para los nuevos intervalos.
            if (f(a) * f(xk) < 0):
                b = xk
            elif (f(xk) * f(b) < 0):
                a = xk
            iteraciones += 1

        return (xk,iteraciones,abs(f(xk)))

    else:
        print("No se puede aplicar el metodo de la falsa posicion a esta funcion")
        return (None, None, None)


'''Implementacion del metodo de Newton-Raphson para aproximar el cero de una funcion
   Entradas:
     --->f: Funcion de la cual se quiere saber el 0
     --->x0:Valor inicial con el que se quiere inciar las iteraciones
     --->tol:Valor maximo que puede alcanzar f(xk) para considerarse una aproximacion satisfactoria.
     --->iterMax: Maximo de iteraciones que puede ejecutar el metodo para llegar a la aproximacion.
   Salidas:
     --->xk: Aproximacion obtenida por el metodo
     --->iteraciones: Iteraciones realizadas para llegar a la aproximacion anterior
     --->|f(x)|: Error de f(xk) respecto al valor real de x que hace que f(x) sea 0.
'''
def newton_raphson(f,x0,tol,iterMax):
    #Verificacion para saber si la tolerancia es negativa.
    if(tol<=0):
        print("La tolerancia debe de ser mayor a 0")
        return (None,None,None)
    #Bloque de codigo para convertir la funcion F en simbolica.
    x=Symbol('x')
    f=sympify(f)

    #Bloque de codigo para verificar que la funcion no sea una constante.
    if (f.diff(x) == 0):
        print("Esta funcion no tiene cero")
        return (str(f), 0, str(f))

    #Bloque para definir fAux que sera la ecuacion iterativa de Newton-Raphson
    fAux,f=lambdify(x,x-(f/f.diff(x))),lambdify(x,f)

    x,iteraciones=x0,0

    #Ciclo iterativo que permite realizar las iteraciones del metodo.
    while(iteraciones<iterMax):
        x=fAux(x)

        #Evaluacion para saber si ya se llego a una solucion satisfactoria
        if(abs(f(x))<tol):
            break
        iteraciones+=1
    return(x,iteraciones,abs(f(x)))


'''Implementacion del metodo de Falsa Posicion para aproximar el cero de una funcion
   Entradas:
     --->f: Funcion de la cual se quiere saber el 0.
     --->x0:Valor incial desde el cual se quiere empezar el proceso de aproximacion 1/2.
     --->x1:Valor incial desde el cual se quiere empezar el proceso de aproximacion 2/2. 
     --->tol:Valor maximo que puede alcanzar f(xk) para considerarse una aproximacion satisfactoria.
     --->iterMax: Maximo de iteraciones que puede ejecutar el metodo para llegar a la aproximacion.
   Salidas:
     --->xk: Aproximacion obtenida por el metodo
     --->iteraciones: Iteraciones realizadas para llegar a la aproximacion anterior
     --->|f(x)|: Error de f(xk) respecto al valor real de x que hace que f(x) sea 0.
'''
def secante(f,x0,x1,tol,iterMax):
    # Verificacion para saber si la tolerancia es negativa.
    if (tol <= 0):
        print("La tolerancia debe de ser mayor a 0")
        return (None, None, None)

    #Bloque de codigo para convertir f en una funcion simbolica
    x_0,x_1,x=symbols("x_0,x_1,x")
    f=sympify(f)

    #Verificacion para determinar si la funcion es una cosntante
    if (f.diff() == 0):
        print("Esta funcion no tiene cero")
        return (str(f), 0, str(f))

    # Bloque de codigo para definir fAux que sera la funcion iterativa del metodo de la Secante.
    fx0,fx1=f.subs(x,x_0),f.subs(x,x_1)
    fAux=lambdify([x_0,x_1],x_1-((x_1-x_0)/(fx1-fx0))*fx1)
    f = lambdify(x, f)

    xk,iteraciones=0,0

    # Ciclo iterativo que permite realizar las iteraciones del metodo.
    while(iteraciones<iterMax):
        '''Verificacion para saber si sellego a una solucion satisfactoria o para saber si el denominador de la funcion iterativa se indefiniria 
           en la presente iteracion'''
        if (abs(f(xk)) < tol or f(x1) - f(x0) == 0):
            break;

        xk=fAux(x0,x1)
        x0,x1=x1,xk
        iteraciones+=1
    return (xk,iteraciones,abs(f(xk)))


# Funcion para calcular ceros de funcion con un metodo no visto en clase
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
    temp= sympify(funcion)
    derivada = diff(temp, x)

    # Se convierten a funciones de python
    funcion = lambdify(x, funcion)
    derivada = lambdify(x, derivada)

    # Se inicializan los valores de la iteración
    x_n = valorInicial
    k = 0
    try:
        while abs(funcion(x_n)) > tolerancia and k < iterMax:
            # Se realiza un calculo auxiliar
            xdx = funcion(x_n) / derivada(x_n)
            # Se calcula y_n
            y_n = x_n - xdx * (1 - xdx ** 5)
            # Se realizan calculos auxiliares
            ydx = funcion(y_n) / derivada(x_n)
            yx = funcion(y_n) / funcion(x_n)
            # Se calcula z_n
            z_n = y_n - ydx * (1 - yx) ** -2
            # Se realizan calculos auxiliares
            zdx = funcion(z_n) / derivada(x_n)
            zy = funcion(z_n) / funcion(y_n)
            zx = funcion(z_n) / funcion(x_n)
            # Se calcula x_n
            x_n = z_n - zdx * (1 + yx ** 2 + zy) / (1 - yx - zx) ** 2
            # Se aumenta el numero de iteracion
            k += 1
    except:
        pass

    # Se intenta devolver los valores, si hay un "OverFlow" es porque el error es muy grande
    try:
        if (not isnan(x_n)):
            return [x_n, k, funcion(x_n)]
        else:
            return [float('inf'), k, float('inf')]
    except OverflowError:
        return [x_n, k, float('inf')]
