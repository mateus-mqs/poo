#include <iostream>
#include <string>
#include <vector>
#include "Universidade.h"

void ProfHorista::printProf(){
    cout << "Professor Horista" << endl;
    cout << "Nome: " << this->getName() << endl;
    cout << "Salario: " << this->getSalario() << endl;
    cout << "Horas Trabalhadas no mes: " << this->nrNorasTrabalhadas << endl;
    cout << "Valor pago por hora trabalhada: " << this->valorHora << endl;
}

double ProfHorista::getSalario(){
    return this->valorHora * this->nrNorasTrabalhadas;
}

void ProfIntegral::printProf(){
    cout << "Professor Integral" << endl;
    Professor::printProf();
    cout << "Salario: " << this->getSalario() << endl;
}

double ProfIntegral::getSalario(){
    return this->salarioMensal;
}

double Universidade::totalPago(){
    double tot = 0;
    for(int i = 0; i < this->profs.size(); i++){
        tot += this->profs[i]->getSalario();
    }
    return tot;
}

void Universidade::addProfessor(Professor *p){
	this->profs.push_back(p);
}

void Universidade::printProfessores() {
	for (int i = 0; i < this->profs.size(); i++) {
		this->profs[i]->printProf();
	}
	cout << "Valor total pago para os professore eh de: " << this->totalPago() << " reais." << endl;
}