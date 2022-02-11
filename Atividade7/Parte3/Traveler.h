// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 7
// Exercicio 3
// 12/01/2022

#ifndef TRAVELER_H
#define TRAVELER_H

#include<iostream>
#include <string>
using namespace std;

class Traveler{
     public:
        Traveler(string s);
        Traveler(const Traveler& t);
        Traveler& operator= (const Traveler &t);          
        string s;
};

#endif