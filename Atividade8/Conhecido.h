// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 8
// Exercicio 1
// 26/01/2022

#ifndef CONHECIDO_H
#define CONHECIDO_H

#include <iostream>
#include <string>
#include "Pessoa.h"
using namespace std;

class Conhecido : public Pessoa{
     public:
        Conhecido():Pessoa(),email("indefinido"){};
        string get_email();
        void set_email(string email);
        void set_info();
        string get_info();
    
    private:                
        string nome;
        int idade;
        string email;
};

#endif