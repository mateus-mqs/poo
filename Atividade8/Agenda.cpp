// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 8
// Exercicio 1
// 26/01/2022


#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Pessoa.h"
#include "Amigo.h"
#include "Conhecido.h"
#include "Agenda.h"

Agenda::Agenda(int quant){
    this->q_amigos = 0;
    this->q_conhecidos = 0;
    srand((unsigned int) time (NULL));
    for(int i = 0; i < quant; i++){
        double c = rand() % 2;
        if (c == 1){
            this->q_amigos++;
            list.insert(list.begin(), new Amigo());
        } else {
            this->q_conhecidos++;
            list.push_back(new Conhecido());
        }
    }
}

void Agenda::addInformacoes(){
    cout << this->q_amigos + this->q_conhecidos << endl;
    for (int i = 0; i < this->q_amigos + this->q_conhecidos; i++){
        this->list[i]->set_info();
    }
}

void Agenda::imprimeAniversarios(){
    for (int i = 0; i < this->q_amigos; i++){
        cout << this->list[i]->get_info() << endl;
    }
}

void Agenda::imprimeEmail(){
    for (int i = this->q_amigos; i < this->q_amigos + this->q_conhecidos; i++){
        cout << this->list[i]->get_info() << endl;
    }
}

int Agenda::get_amigos(){
    return this->q_amigos;
}

int Agenda::get_conhecidos(){
    return this->q_amigos;
}