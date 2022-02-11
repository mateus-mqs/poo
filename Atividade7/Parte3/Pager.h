// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 7
// Exercicio 3
// 12/01/2022

#ifndef PAGER_H
#define PAGER_H

#include<iostream>
#include <string>
using namespace std;

class Pager{
     public:
        Pager(string s);
        Pager(const Pager& p);
        Pager& operator= (const Pager &p);               
        string s;
};

#endif