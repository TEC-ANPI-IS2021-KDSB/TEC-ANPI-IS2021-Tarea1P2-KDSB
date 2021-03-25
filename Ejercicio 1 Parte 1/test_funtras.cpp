#include <iostream>
#include "funtras.h"

//Esos includes permiten utilizar funciones declaradas en el archivo cabecera
using namespace std;


///////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    //Script para prueba
    //Composicion de la funcion de prueba
    double test_function, a, b, c, d, e, f, g, h, j, k;
    g = 0.4285714286;           //g = 3/7
    h = sqrt_t(2);
    a = sin_t(g);
    b = ln_t(2.0);
    c = root_t((a+b), 3.0);
    d = sinh_t(h);
    e = c/d;
    d = exp_t(-1.0);
    f = atan_t(d);

    j = div_1t(2);    // Probando funcion a^-1

    test_function = e + f;
    cout << "El valor de la función de prueba es = " << test_function;
    std::cin.ignore();
    cout << "El valor de la función de prueba es = " << sqrt_t(100);

    return 0;
}
