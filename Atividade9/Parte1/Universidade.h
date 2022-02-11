#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Professor{
        string nome;
    public:
        Professor(string n):nome(n){}
        string getName(){return this->nome;}
        virtual void printProf(){cout << "Nome: " << this->nome << endl;}
        virtual double getSalario() = 0;
        virtual ~Professor(){}
};

class ProfHorista: public Professor {
        double nrNorasTrabalhadas;
        double valorHora;
    public:
        ProfHorista(string n, double nht = 0, double vh = 0): Professor(n),nrNorasTrabalhadas(nht), valorHora(vh){}
        double getSalario();
        virtual ~ProfHorista(){}
        void printProf();
};

class ProfIntegral: public Professor {
        double salarioMensal;
    public:
       ProfIntegral(string n, double sm = 0):Professor(n),salarioMensal(sm){}
       double getSalario();
       virtual ~ProfIntegral(){}
       void printProf();
};

class Universidade {
	vector<Professor*> profs;

public:
    double totalPago();
	void addProfessor(Professor *p);
	void printProfessores();
};

#endif