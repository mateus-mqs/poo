// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 2
// Exercicio 2
// 06/11/2021

#include "Tempo.h"

using namespace std;

Tempo::Tempo(int dia, int hora, int min, int seg){
    this->dia = dia;
    this->hora = hora;
    this->min = min;
    this->seg = seg;
}

Tempo::~Tempo() {
    delete[] this;
}

void Tempo::consistencia(){
    if(this->seg > 59 || this->seg < 0){
        this->min += this->seg/60;
        this->seg = this->seg%60;
    }
    if(this->min > 59 || this->min < 0){
        this->hora += this->min/60;
        this->min = this->min%60;
    }
    if(this->hora > 23 || this->hora < 0){
        this->dia += this->hora/24;
        this->hora = this->hora%24;
    }
}

void Tempo::soma(Tempo t1){
    this->setDia(t1.dia + this->getDia()); 
    this->setHora(t1.hora + this->getHora());
    this->setMin(t1.min + this->getMin());
    this->setSeg(t1.seg + this->getSeg());
    this->consistencia();
}

void Tempo::imprime(){
    this->consistencia();
    cout << "Imprimindo dados: " << endl;
    cout << "Dias: " << this->dia << endl;
    cout << "Horas: " << this->hora << endl;
    cout << "Minutos: " << this->min << endl;
    cout << "Segundos: " << this->seg << endl;
}

void Tempo::leitura(){
    cin >> this->dia >> this->hora >> this->min >> this->seg;
    this->consistencia();
}

void Tempo::incrementa(){
    this->seg++;
    this->consistencia();
}

void Tempo::decrementa(){
    this->seg--;
    this->consistencia();
}

int Tempo::getDia() const {
    return this->dia;
}

int Tempo::getHora() const {
    return this->hora;
}

int Tempo::getMin() const {
    return this->min;
}

int Tempo::getSeg() const {
    return this->seg;
}

void Tempo::setDia(int dia){
    this->dia = dia;
}

void Tempo::setHora(int hora){
    this->hora = hora;
}

void Tempo::setMin(int min){
    this->min = min;
}

void Tempo::setSeg(int seg){
    this->seg = seg;
}