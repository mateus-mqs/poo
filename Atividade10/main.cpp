// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 10
// Exercicio 1
// 09/02/2022

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#include "Contas.h"

int main() {
    int num;
    cout << "Indique quantas contas criar: " << endl;
    cin >> num;
    int p = 0;
    //vector<ContaBancaria*> list = {};
    vector<ContaBancaria*> list;
    for(int i = 0; i < num; i++){
        int aux;
        string sen;
        cout << "Aperte 0 para criar uma conta poupanca." << endl;
        cout << "Aperte 1 para criar uma conta corrente." << endl;
        cin >> aux;
        cout << "Indique a senha desta conta: " << endl;
        cin >> sen;
        if(aux == 0){
            list.insert(list.begin(), new ContaPoupanca(sen));
        } else if (aux == 1) {
            list.push_back(new ContaCorrente(sen));
        } else {
            cout << "Numero inválido, criando conta corrente." << endl;
        }
    }
    for( int i = 0; i < list.size(); ++i) { //conta quantas contas correntes e poupanca existem na lista
        ContaCorrente *aux = dynamic_cast<ContaCorrente *>(list[i]);
        if(aux){p++;}
    } 
    for(int i = 0; i < p; i++){ //define as taxas das contas poupancas
        double rend;
        cout << "Informe a taxa de rendimento da conta poupanca numero: " << list[i]->getNum() << endl;
        cin >> rend;
        ContaPoupanca* aux = dynamic_cast<ContaPoupanca*>(list[i]);
        aux->setRend(rend);
    }
    cout << "----------------------------------------------------------" << endl;
    for(int i = 0; i < list.size(); i++){ //deposita algumas quantias nas contas
        list[i]->deposita((i + 1) * 100);
        cout << "----------------------------------------------------------" << endl;
    }
    for(int i = 0; i < list.size(); i++){ //saca algumas quantias nas contas
        list[i]->saca((i + 1) * 50);
        cout << "----------------------------------------------------------" << endl;
    }
    cout << "----------------------------------------------------------" << endl;
    for(int i = 0; i < list.size(); i++){ //imprime as taxas e as transacoes das contas poupanca e corrente, respectivamente
        if(i < p){
            cout << "Taxa de rendimento da conta poupanca numero ";
        } else {
            cout << "Numero de transacoes da conta corrente numero ";
        }
        cout << list[i]->getNum() << ": " << list[i]->getData() << endl;
    }
    cout << "----------------------------------------------------------" << endl;
    list[0]->alteraSenha();
    cout << "----------------------------------------------------------" << endl;
    list[1]->tiraExtrato();

    return 0;
}