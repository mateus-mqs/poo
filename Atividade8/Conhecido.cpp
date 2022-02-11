// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 8
// Exercicio 1
// 26/01/2022

#include <iostream>
#include <string>
#include "Pessoa.h"
#include "Conhecido.h"
using namespace std;

void Conhecido::set_email(string email){
    this->email = email;
}

string Conhecido::get_email(){
    return this->email;
}

void Conhecido::set_info(){
    cout << "Digite nome, idade e email de um CONHECIDO, nessa ordem:" << endl;
    string nome, email;
    int idade;
    cin >> nome >> idade >> email;
    this->set_nome(nome);
    this->set_email(email);
    this->set_idade(idade);

}

string Conhecido::get_info(){
    return this->get_email();
}