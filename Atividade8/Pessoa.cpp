// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 8
// Exercicio 1
// 26/01/2022

#include <iostream>
#include <string>
#include "Pessoa.h"
using namespace std;

void Pessoa::set_idade(int idade){
    this->idade = idade;
}

int Pessoa::get_idade(){
    return this->idade;
}

void Pessoa::set_nome(string nome){
    this->nome = nome;
}

string Pessoa::get_nome(){
    return this->nome;
}
void Pessoa::set_info(){}

string Pessoa::get_info(){}