// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 8
// Exercicio 1
// 26/01/2022

#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
using namespace std;


class Pessoa{
     public:
        Pessoa(string nom, int id):nome(nom),idade(id){};
        Pessoa():nome("indefinido"),idade(0){};
        int get_idade();
        void set_idade(int idade);
        string get_nome();
        void set_nome(string nome);
        virtual void set_info();
        virtual string get_info();
    
    private:                
        string nome;
        int idade;
};

#endif