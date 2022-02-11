// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 3
// Exercicio 1
// 13/11/2021

#ifndef PONTO_HPP
#define PONTO_HPP

#include <list>
#include <iostream>

class Ponto {
    private:
        float _x;
        float _y;
        int* _id;
        static std::list<int> _ids;
        static int* getNextId();

    public:
        // Construtor
        Ponto(float x = 0.0, float y = 0.0);

        // destrutor
        ~Ponto();   
    
        // basic getters
        float getX() const;
        float getY() const;
        int getID() const;
        void setX(const float);
        void setY(const float);
        void setID(const int);

        //other
        void print() const;
        double distToOrig() const;
        double distTo(const Ponto&) const;
        void soma(const Ponto&);
        Ponto sumOf(const Ponto&);
};

#endif