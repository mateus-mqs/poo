// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 7
// Exercicio 3
// 12/01/2022

#include "Pager.h"

Pager::Pager(const string s){
    this->s = s;
}

Pager::Pager(const Pager& p){
    this->s = p.s;
}

Pager& Pager::operator= (const Pager &p){
    this->s = p.s;
    return *this;
}