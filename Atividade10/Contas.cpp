// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 10
// Exercicio 1
// 09/02/2022

#include <iostream>
#include <string>
#include <vector>

#include "Contas.h"

int ContaBancaria::nums = 1;

int ContaBancaria::validaSenha(){
    string s;
    cin >> s;
    return s == this->senha;
}

void ContaBancaria::alteraSenha(){
    string s;
    cout << "Digite sua senha atual: ";
    cin >> s;
    if(s != this->senha){
        cout << "A atual nao corresponde a senha que voce digitou!" << endl;
        return;
    }
    cout << "Agora digite sua senha nova: ";
    cin >> s;   
    this->senha = s;
    cout << "Senha alterada com sucesso" << endl;
}

int ContaBancaria::getNum(){
    return this->num;
}

double ContaBancaria::getSaldo(){
    return this->saldo;
}

void ContaBancaria::tiraExtrato(){
    cout << "Digite a senha para tirar o extrato da conta "<< this->getNum() << endl;
    if(this->validaSenha()){
        cout << endl << "----------------------------" << endl;
        cout << "Extrato da conta numero " << this->num << endl;
        cout << "Saldo: " << this->saldo << endl;
        cout << "----------------------------" << endl << endl;
        return;
    }
    cout << "Senha invalida" << endl;
}

void ContaBancaria::saca(double valor){
    cout << "Digite a senha para sacar " << valor << " reais da conta "<< this->getNum() << endl;
    if(!this->validaSenha()){
        cout << "Senha invalida" << endl;
        return;
    }
    if(valor <= 0){
        cout << "Valor invalido para saque." << endl;
        return;
    }
    if(valor > this->saldo){
        cout << "Saldo insuficiente para saque na conta numero " << this->num << endl;
        return;
    }
    cout << "Foram sacados "<< valor << " reais da conta numero " << this->num << endl;
    this->saldo -= valor;
}

void ContaBancaria::deposita(double valor){
    cout << "Digite a senha para depositar " << valor << " reais na conta "<< this->getNum() << endl;
    if(!this->validaSenha()){
        cout << "Senha invalida" << endl;
        return;
    }
    if(valor <= 0){
        cout << "Valor invalido para deposito." << endl;
        return;
    }
    cout << "Foram depositados " << valor << " reais na conta numero " << this->num << endl;
    this->saldo += valor;
}

void ContaPoupanca::saca(double valor){
    ContaBancaria::saca(valor);
}

void ContaPoupanca::deposita(double valor){
    ContaBancaria::deposita(valor);
}

void ContaPoupanca::setRend(double valor){
    this->taxa = valor;
}

double ContaPoupanca::getData(){
    return this->taxa;
}

void ContaPoupanca::tiraExtrato(){
    ContaBancaria::tiraExtrato();
}

void ContaCorrente::saca(double valor){
    ContaBancaria::saca(valor);
    this->quantTrans++;
}

void ContaCorrente::deposita(double valor){
    ContaBancaria::deposita(valor);
    this->quantTrans++;
}

double ContaCorrente::getData(){
    return this->quantTrans;
}

void ContaCorrente::tiraExtrato(){
    ContaBancaria::tiraExtrato();
}