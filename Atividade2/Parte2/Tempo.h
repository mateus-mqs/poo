// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 2
// Exercicio 2
// 06/11/2021

#ifndef TEMPO_H
#define TEMPO_H


#include <iostream>

class Tempo {
    private:
        int dia;
        int hora;
        int min;
        int seg;

    public:
        // Construtor
        Tempo(int dia = 0, int hora = 0, int min = 0, int seg = 0);   

        // destrutor
        ~Tempo();   
    
        // basic getters
        int getDia() const;
        int getHora() const;
        int getMin() const;
        int getSeg() const;
        void setDia(int);
        void setHora(int);
        void setMin(int);
        void setSeg(int);


        //other
        void soma(Tempo t1);
        void consistencia();
        void imprime();
        void leitura();
        void incrementa();
        void decrementa();
};

#endif