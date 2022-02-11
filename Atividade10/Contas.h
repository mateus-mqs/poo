// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 10
// Exercicio 1
// 09/02/2022

#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ContaBancaria {
    private:
        string senha;
        int num;
        double saldo;
        static int nums;
    public:
        ContaBancaria(string s = "000000"):senha(s),saldo(0.0),num(nums++){}
        virtual void saca(double valor) = 0;
        virtual void deposita(double valor) = 0;
        virtual void tiraExtrato() = 0;
        void alteraSenha();
        void setSaldo(double valor);
        double getSaldo();
        int getNum();
        virtual double getData() = 0;
        int validaSenha();
};

class ContaCorrente : public ContaBancaria {
    private:
        int quantTrans;
    public:
        ContaCorrente(string s = "000000"):ContaBancaria(s),quantTrans(0){}
        void saca(double valor);
        void deposita(double valor);
        void tiraExtrato();
        double getData();
};

class ContaPoupanca : public ContaBancaria {
    private:
        double taxa;
    public:
        ContaPoupanca(string s = "000000", double tax = 0.0):ContaBancaria(s),taxa(tax){}
        void saca(double valor);
        void deposita(double valor);
        void tiraExtrato();
        void setRend(double valor);
        double getData();
};

#endif