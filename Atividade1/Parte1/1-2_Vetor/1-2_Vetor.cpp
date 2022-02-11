// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 1
// Exercicio 1.2
// 29/10/2021

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
    int ch = 0;
    vector<int> vec = {}; //vetor entrada
    vector<int> comp = {1}; //vetor saida
    while (1){
        cin >> ch;
        if(ch >= 0) //se numero positivo
            vec.push_back(ch); //insere
        else
            break; //senao, finaliza insercao
    }
    comp.push_back(vec[0]);
    for(int i = 1; i < vec.size(); ++i){
        if(vec[i] != vec[i-1]){ //se o elemento for diferente do anterior
            comp.push_back(1); // insere um numero no vetor saida que possuira a contagem de certo elemento
            comp.push_back(vec[i]); // insere o elemento em questao
        } else {
            ++comp[comp.size() - 2]; //se for igual, apenas incremente na contagem
        }
    }
    for(int i = 0; i < comp.size(); ++i){ //print do vetor saida
        cout << comp[i] << " ";
    }
    return 0;
}