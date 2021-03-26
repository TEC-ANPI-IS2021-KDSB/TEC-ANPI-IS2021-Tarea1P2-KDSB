#include <iostream>
#include<math.h>
#include <iomanip>
#include"funtras.h"
using namespace std;

/*
Metodo que aproxima el valor del numero pi haciendo uso de la serie de Nilakantha
Entradas:-
Salidas: Numero pi como float
*/
double pi_t()
{
    //Se definen los valores inciales
    float piT=3;
    float error=1;
    int n=1;

    //Ciclo que permite iterar hasta encontrar una aproximacion satisfactoria
    while(n<2500)
    {
        //Variable para almacenar el valor d epi en la iteracion anterior.
        float piT0=piT;

        //Asignacion de pi para esta iteracion
        piT+=4*((pow(-1,n+1))/((2*n)*(2*n+1)*(2*n+2)));

        //Calculo del error en esta iteracion
        error=(abs(piT-piT0)/abs(piT));

        //Verificacion del error para saber si en esta iteracion debe detenerse el ciclo
        if(error<10e-8)
        {
            return piT;
        }
        n+=1;
    }
}
/*
Metodo que calcula el valor del coseno inverso de un valor x dado
Entradas: Valor x del cual se quiere calcular el coseno inverso en formato de float
Salidas: El valor del coseno inverso del valor x provisto en formato de float
*/
float acos_t(float x)
{
    return (pi_t()/2)-asin_t(x);
}
int main()
{
    cout<<setprecision(10)<<"El valor de acos_t es: "<<acos_t(1)<<endl;
    return 0;
}
