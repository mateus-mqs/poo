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

BusinessTraveler::BusinessTraveler():Traveler("1"),pag("1"){}

BusinessTraveler::BusinessTraveler(const string ss):Traveler(ss),pag(ss){}

BusinessTraveler::BusinessTraveler(const BusinessTraveler& p):Traveler(p), pag(p.pag){};

BusinessTraveler& BusinessTraveler::operator= (const BusinessTraveler &b){
    Traveler::operator=(b);
    this->pag = b.pag;
    return *this;
}

