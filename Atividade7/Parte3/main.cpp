// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 7
// Exercicio 3
// 12/01/2022

#include "BusinessTraveler.h"
#include <iostream>
#include <string>
#include "Traveler.h"
#include "Pager.h"

int main(){
    Traveler t1("a");
    cout << "t1 possui " << t1.s << endl;
    Traveler t2("b");
    cout << "t2 possui " << t2.s << endl;
    t2 = t1;
    cout << "t2 copiou t1. t2 agora possui " << t2.s << endl;

    Pager p1("c");
    cout << "p1 possui " << p1.s << endl;
    Pager p2("d");
    cout << "p2 possui " << p2.s << endl;
    p2 = p1;
    cout << "p2 copiou p1. p2 agora possui " << p2.s << endl;

    BusinessTraveler b1("2");
    cout << "b1 possui string " << b1.s << " e pager " << b1.pag.s << endl;
    BusinessTraveler b2("3");
    cout << "b2 possui string " << b2.s << " e pager " << b2.pag.s << endl;
    b2 = b1;
    cout << "b2 copiou b1. b2 agora possui " << b2.s << endl;

    return 0;
}