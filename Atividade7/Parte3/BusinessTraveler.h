// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 7
// Exercicio 3
// 12/01/2022

#ifndef BUSINESSTRAVELER_H
#define BUSINESSTRAVELER_H

#include<iostream>
#include<string>
#include "Traveler.h"
#include "Pager.h"

class BusinessTraveler: public Traveler{
     public:
        BusinessTraveler();
        BusinessTraveler(const string ss);
        BusinessTraveler(const BusinessTraveler& p);
        BusinessTraveler& operator= (const BusinessTraveler &b);              
        Pager pag;
};

#endif