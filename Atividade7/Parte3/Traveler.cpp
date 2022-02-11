// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 7
// Exercicio 3
// 12/01/2022

#include "Traveler.h"

Traveler::Traveler(const string s){
    this->s = s;
}

Traveler::Traveler(const Traveler& p){
    this->s = p.s;
}

Traveler& Traveler::operator= (const Traveler &p){
    this->s = p.s;
    return *this;
}