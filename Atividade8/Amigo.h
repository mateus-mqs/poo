// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 8
// Exercicio 1
// 26/01/2022

#ifndef AMIGO_H
#define AMIGO_H

#include <iostream>
#include <string>
#include "Pessoa.h"
using namespace std;

class Amigo : public Pessoa{
     public:
        //Amigo(string nom, int id, string dat):Pessoa(nom,id),data(dat){};
        Amigo():Pessoa(),data("indefinido"){}
        string get_data();
        void set_data(string data);
        void set_info();
        string get_info();
    
    private:                
        string data;
};

#endif