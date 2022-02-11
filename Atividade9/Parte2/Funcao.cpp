#include <iostream>
#include <cmath>
#include "Funcao.h"
using namespace std;

double Quadratica::func(double input){
    return a*input*input + b*input + c;
}

double Senoide::func(double input){
    return (sin(input))/input;
}

double Linear::func(double input){
    return a*input + b;
}

double Funcao::getIntegral(double limiteInferior, double limiteSuperior, double intervalos){
    double deltaX = (limiteSuperior - limiteInferior ) / intervalos;
    double soma = 0;
    double trap = 0;
    for (int i = 0; i < intervalos - 1; i++){
        trap = (func(limiteInferior + deltaX * i) + func(limiteInferior + deltaX * (i+1))); //base menor + base maior
        trap *= (deltaX/2); //vezes altura dividio por 2
        soma += trap;
    }
    return soma;
}