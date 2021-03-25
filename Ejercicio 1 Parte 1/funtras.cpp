using namespace std;
#include "iostream"
#include "math.h"
#include "funtras.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
double factorial (int n){
    //En la librería estándar de C++ no hay una función definida
    //que calcule el factorial, en este caso fue requerido escribirla
    double fact = 1; //Variable inicializada en 1
    if (n < 0) //Si el número n es menor que 0, no habrá factorial
        cout << "Error! No exste el factorial de un numero negativo";
    else { //Si el numero n es mayor que cero se entra a un for iniciado en 1, hasta que sea menor o igual al numero, y se va aumentando en 1
        for(int i = 1; i <=n; ++i) {
            fact *= i; //Se guarda el resultado en la variable fact donde se va multiplicando el valor de i
        }
    }

    return fact; //Se retorna el valor de fact
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
double div_1t(double a){
    //La funcion se aproxima utilizando el metodo iterativo x_(k+1)=x_k·(2-a·x_k ), declarando distintas variables
    // Xo = valor inicial o valor anterior, en este caso esta dado por los 5 valores posibles de Xo.
    // eps= Variable definida en octave y representa la presicion relativa de punto flotante que es 2.2204 × 10-16
    // check = variable para la condicion de parada
    // un criterio de parada es cuando |(xk+1 – xk )/xk+1 |  es menor a la tolerancia
    double xo, xn, f_a, eps = 2.2204E-16, check;
    int i = 0; //valor de i para el while
    //Calculo de Factoriales para las condicionales
    double f20 = factorial(20);
    double f40 = factorial(40);
    double f60 = factorial(40);
    double f80 = factorial(80);
    double f100 = factorial(100);

    f_a = factorial(a);

    //Primer condicional: Si a! es menor o igual a 20! y mayor a 0!, Xo es "eps" elevado a la 2
    if (f_a > 0 && f_a <= f20){
        xo = pow(eps, 2);
    }
        //Segundo condicional: Si a! es menor o igual a 40! y mayor a 20!, Xo es "eps" elevado a la 4

    else if (f_a > f20 && f_a <= f40){
        xo = pow(eps, 4);
    }
        //Tercer condicional: Si a! es menor o igual a 60! y mayor a 40!, Xo es "eps" elevado a la 8

    else if (f_a > f40 && f_a <= f60){
        xo = pow(eps, 8);
    }
        //Cuarta condicional: Si a! es menor o igual a 80! y mayor a 60!, Xo es "eps" elevado a la 11
    else if (f_a > f60 && f_a <= f80){
        xo = pow(eps, 11);
    }
        //Quinta condicional: Si a! es menor o igual a 100! y mayor a 80!, Xo es "eps" elevado a la 15
    else if (f_a > f80 && f_a <= f100){
        xo = pow(eps, 15);
    }

    do {
        xn = xo*(2-a*xo); //El ultimo valor sera x_(k+1)=x_k·(2-a·x_k )
        check = abs((xn - xo)/xn); // Condición de parada
        xo = xn; //Xo toma el valor de Xn
        i++; //se aumenta i para la condicional de parada
    } while(check > tol && i <= 2500); //Condicional de parada Si check es mayor a la tolerancia y la iteracion es menor a 2500

    return xn; //retorna el valor de Xn
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// La sumatoria se ejectua hasta que | eak – eak-1 | < tol
double exp_t(double x){
    int i = 0; //variable para parada del while
    double check, S = 0; // check es la variable utilizada para la condicion de parada  y S el resultado de la sumatoria

    do {
        check = S; //check toma el valor de S
        S += pow(x, i)/factorial(i); //se realiza la sumatoria
        i++; //incremento de i
    } while(abs((S - check)) > tol && i < 2500); //condicion de parada | eak – eak-1 | < tol con 2500 iteraciones maximas

    return S; //retorna el valor de la sumatoria
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
//La sumatoria se ejecuta hasta que | sin(a)k – sin(a)k-1 | < tol
double sin_t(double x){
    int i = 0; //variable para parada del while
    double check, S = 0;// check es la variable utilizada para la condicion de parada  y S el resultado de la sumatoria

    do {
        check = S;//check toma el valor de S
        S += pow(-1, i)*pow(x, (2*i+1))/factorial((2*i+1)); //se realiza la sumatoria
        i++; //incremento de i
    } while(abs((S - check)) > tol && i < 2500); //condicion de parada | sin(a)k – sin(a)k-1 | < tol con 2500 iteraciones maximas

    return S; //retorna el valor de la sumatoria
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
//La sumatoria se ejecutará hasta que la diferencia entre | cos(a)k – cos(a)k-1 | < tol
double cos_t(double x){
    int i = 0;//variable para parada del while
    double check, S = 0;// check es la variable utilizada para la condicion de parada  y S el resultado de la sumatoria

    do {
        check = S;//check toma el valor de S
        S += pow(-1, i)*pow(x, 2*i)/factorial(2*i);//se realiza la sumatoria
        i++;//incremento de i
    } while(abs((S - check)) > tol && i < 2500);//condicion de parada | cos(a)k – cos(a)k-1 | < tol con 2500 iteraciones maximas

    return S;//retorna el valor de la sumatoria
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
double ln_t(double x){
    int i = 1; //variable para parada del while
    double check, S = 0;// check es la variable utilizada para la condicion de parada  y S el resultado de la sumatoria

    if (x <= 0){ //Verifica que el numero introducido sea menor o igual a cero, de ser así muestra el siguiente mensaje
        cout << "No existe logaritmo natural de numero igual o menor a cero (0)" << endl;
    }

    else { //Si es mayor o igual a cero entra al do, check toma el valor de S, incrementando el valor de S al cociente de la potencia de x-1 elevado a i entre i multiplicado por la potencia del valor elevdo a i
        do {
            check = S; //check toma el valor de S
            S += pow((x-1), i)/(i*pow(x, i));//se realiza la sumatoria
            i++; //incremento de i
        } while( abs((S - check) > tol) && i < 2500);//condicion de parada | ln(a)k – ln(a)k-1 | < tol con 2500 iteraciones maximas
    }

    return S; //retorna el valor de la sumatoria
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
double sinh_t(double x){
    int i = 0;  //variable para parada del while
    double check, S = 0; // check es la variable utilizada para la condicion de parada  y S el resultado de la sumatoria

    do {
        check = S;//check toma el valor de S
        S += pow(x, 2*i+1)/factorial(2*i+1); //se realiza la sumatoria
        i++;//incremento de i
    } while(abs((S - check)) > tol && i < 2500);//condicion de parada | sinh(a)k – sinh(a)k-1 |  < tol con 2500 iteraciones maximas


    return S; //retorna el valor de la sumatoria
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
double cosh_t(double x){
    int i = 0; //variable para parada del while
    double check, S = 0; // check es la variable utilizada para la condicion de parada  y S el resultado de la sumatoria

    do {
        check = S;//check toma el valor de S
        S += pow(x, 2*i)/factorial(2*i); //se realiza la sumatoria
        i++;//incremento de i
    } while(abs((S - check)) > tol && i < 2500); //condicion de parada | cosh(a)k – cosh(a)k-1 |   < tol con 2500 iteraciones maximas

    return S; //retorna el valor de la sumatoria
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
double asin_t(double x){
    int i = 0; //variable para parada del while
    double check, S = 0; // check es la variable utilizada para la condicion de parada  y S el resultado de la sumatoria

    do {
        check = S; //check toma el valor de S
        S += factorial(2*i)/(pow(4,i)*pow(factorial(i), 2)*(2*i+1))*pow(x, 2*i+1); //se realiza la sumatoria
        i++; //incremento de i
    } while(abs((S - check)) > tol && i < 2500); //condicion de parada | asin(a)k – asin(a)k-1 |    < tol con 2500 iteraciones maximas

    return S; //retorna el valor de la sumatoria
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
double atan_t(double x){
    int i = 0; //variable para parada del while
    double check, S = 0; // check es la variable utilizada para la condicion de parada  y S el resultado de la sumatoria

    do {
        check = S; //check toma el valor de S
        S += pow(-1, i)*(pow(x, 2*i+1)/(2*i+1)); //se realiza la sumatoria
        i++;  //incremento de i
    } while(abs((S - check)) > tol && i < 2500); //condicion de parada | atan(a)k – atan(a)k-1 |     < tol con 2500 iteraciones maximas

    return S;  //retorna el valor de la sumatoria
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
double tan_t(double x){ //Se reliza la función de Tangente por definición
    return sin_t(x)/cos_t(x);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
double log_t(double x, double a){ //Se reliza la función de "log base a" por definición
    return ln_t(x)/ln_t(a);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
double tanh_t(double x){ //Se realiza la función de tangente hiperbolica por definición
    return sinh_t(x)/cosh_t(x);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
double root_t(double x, double a){
    //Raiz de indice "p"
    // La función se define al resolver la siguiente ecuación: g(x)= x^p-a
    //Para el valor de x que hace que g(x) = 0. Esto se logra empleando el
    // método de búsqueda de raíces de Newton – Raphson, el cual es:
    // x_(i+1)=x_i+(f(x_i))/(f'(x_i))
    //Donde:
    // xi es el valor inicial, o valor anterior, de prueba
    // f(xi) es la función evaluada en el punto xi
    // f’(xi) es la primera derivada de la función f(x) evaluada en el punto xi
    // De la función g(x) se puede deducir que:
    // g^' (x)= p·x^(p-1)
    // Sustutiyendo la función g(x) y g’(x) en la ecuación del método de Newton-Raphson:
    // x_(i+1)=x_i+(〖x_i〗^p-a)/( p·〖x_i〗^(p-1) )
    //Xn= Valor actual de la raiz (i)
    //Xo= Valor inicial o actual de la raíz (i - 1)
    // check: Cálculo del error entre xo y xn
    double xo = a/2, check, xn;

    if (x == 0){
        return 0;
    }

    else{
        do {
            xn = xo - (pow(xo, a) - x)/(a*pow(xo, a-1));
            check = abs((xn - xo)/xn);
            xo = xn;
        } while(check > tol);
    }

    return xn;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
double power_t(double x, double a){
    //La función propuesta posee la siguiente propiedad logarítmica: log_a⁡(a^x )=x
    // También se sabe que: log_a⁡(x)=ln⁡(x)/ln⁡(a)
    // Entonces: log_a⁡(a^x )=x=ln⁡(a^x )/ln⁡(a).....x=ln⁡(a^x )/ln⁡(a)
    // Despejando ln(ax): ln⁡(a^x )=x·ln⁡(a)
    // Aplicando exponencial a ambos lados:  a^x=e^(x·ln⁡(a) )
    // Donde, ya se tienen funciones definidas para el exponencial de un número,
    // y el logaritmo natural de un número
    return exp_t((x*ln_t(a)));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
double sqrt_t(double x){
    //Raiz cuadrada
    //Ya que la raíz cuadrada es un caso de la función raíz de índice p, donde p = 2,
    // el procedimiento se puede derivar como:
    // g(x)= x^2-a
    // g'(x)= 2·x
    // x_(i+1)=x_i+(〖x_i〗^2-a)/( 2·x_i )
    //Xn= Valor actual de la raiz (i)
    //Xo= Valor inicial o actual de la raíz (i - 1)
    // check: Cálculo del error entre xo y xn
    double xo = 1, xn, check;

    if (x < 0){ //veririca si el numero a sacar la raiz es negativo
        cout << "No existe raiz cuadrada de un numero negativo" << endl;
    }

    else if (x == 0){ //si el numero es 0, la raiz es 0
        xn = 0;
    }

    else {
        do {
            //Si el numero no es negativo ni cero entra al Calculo
            // el resultado sera el valor de la resta de
            // xo - el cosiente de la potencia de xo a la 2 menos x entree xo multiplicado por 2
            xn = xo - (pow(xo, 2) - x)/(2*xo);
            check = abs((xn - xo)/xn);
            xo = xn;
        } while(check > 1E-08); // el while se cumple hasta que el
    }

    return xn;
}