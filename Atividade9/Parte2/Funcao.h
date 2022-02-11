#ifndef FUNCAO_H
#define FUNCAO_H

#include <iostream>
#include <cmath>
using namespace std;

class Funcao
{
    public:

    //funcao que obtem a integral da funcao pela regra do trapezio
    double getIntegral(double limiteInferior, double limiteSuperior, double intervalos);

    // funcao virtual representando a funcao cuja integral deve ser calculada
    virtual double func(double input) = 0;

    // destrutor
    //virtual ~Funcao(){}

};

class Quadratica : public Funcao {
    private:
        double a, b, c;

    public:
        Quadratica(double aa, double bb, double cc):a(aa),b(bb),c(cc){}
        double func(double input);
};

class Senoide : public Funcao {
    public:
        //Senoide();
        double func(double input);

};

class Linear : public Funcao {
    private:
        double a, b;

    public:
        Linear(double aa, double bb):a(aa),b(bb){}
        double func(double input);

};

#endif