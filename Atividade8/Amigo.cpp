// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 8
// Exercicio 1
// 26/01/2022

#include <iostream>
#include <string>
#include "Pessoa.h"
#include "Amigo.h"
using namespace std;

void Amigo::set_data(string data){
    this->data = data;
}

string Amigo::get_data(){
    return this->data;
}

void Amigo::set_info(){
    cout << "Digite nome, idade e data de aniversario de um AMIGO, nessa ordem:" << endl;
    string nome, data;
    int idade;
    cin >> nome >> idade >> data;
    this->set_nome(nome);
    this->set_data(data);
    this->set_idade(idade);

}

string Amigo::get_info(){
    return this->get_data();
}
