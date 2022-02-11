// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 8
// Exercicio 1
// 26/01/2022

#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <string>
#include <vector>
#include "Pessoa.h"
#include "Amigo.h"
#include "Conhecido.h"
using namespace std;

class Agenda{
    public:
        Agenda(int quant);
        void addInformacoes();
        void imprimeAniversarios();
        void imprimeEmail();
        int get_amigos();
        int get_conhecidos();

    private:                
        int q_amigos;
        int q_conhecidos;
        vector<Pessoa*> list;
};

#endif