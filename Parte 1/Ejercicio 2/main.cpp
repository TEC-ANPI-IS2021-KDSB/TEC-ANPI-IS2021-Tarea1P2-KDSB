#include <iostream>
#include<math.h>
#include <iomanip>
#include"fun_tras.h"
using namespace std;
double pi_t()
{
    float piT=3;
    float error=1;
    int n=1;
    while(n<2500)
    {
        float piT0=piT;
        float value=4*((pow(-1,n+1))/((2*n)*(2*n+1)*(2*n+2)));
        piT+=4*((pow(-1,n+1))/((2*n)*(2*n+1)*(2*n+2)));
        error=(abs(piT-piT0)/abs(piT));
        if(error<10e-8)
        {
            return piT;
        }
        n+=1;
    }
    int temp=0;
}
float acos_t(float x)
{
    return (pi_t()/2)-asin_t(x);
}
int main() {
    //pi_t();
    cout<<setprecision(10)<<"El valor de acos_t es: "<<acos_t(1)<<endl;
    return 0;
}
