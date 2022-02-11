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

int main(){
    int x;
    cout << "Quantas pessoas haverao na lista?" << endl;
    cin >> x;
    Agenda ag(x);
    cout << "Existem " << ag.get_amigos() << " amigos e " << ag.get_conhecidos() << " conhecidos na agenda." << endl;

    cout << "Agora, adicione as informacoes na agenda." << endl;
    ag.addInformacoes();
    cout << "Imprimindo aniversarios dos amigos:" << endl;
    ag.imprimeAniversarios();
    cout << "Imprimindo e-mails dos conhecidos:" << endl;
    ag.imprimeEmail();

    return 0;
}