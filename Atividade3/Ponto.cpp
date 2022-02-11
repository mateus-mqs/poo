// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 3
// Exercicio 1
// 13/11/2021
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Ponto.h"

using namespace std;

inline double dist(float x1, float y1, float x2, float y2){return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));}

std::list<int> Ponto::_ids = {};

Ponto::Ponto(float x, float y){
    this->_x = x;
    this->_y = y;
    this->_id = getNextId();
}

Ponto::~Ponto() {
    _ids.remove(*(this->_id));
}

int* Ponto::getNextId(){
    srand((int)time(0));
    int r = (rand() % 1000) + 1;
    while(1){
        std::list<int>::iterator it = std::find(_ids.begin(), _ids.end(), r);
        if(!(it != _ids.end())){ // se o id NAO estiver na lista
            break;  // sai
        }
        srand((int)time(0));
        r = (rand() % 1000) + 1;
    }
    _ids.push_back(r);
    return &(_ids.back());
}

float Ponto::getX() const {
    return this->_x;
}

float Ponto::getY() const {
    return this->_y;
}

int Ponto::getID() const {
    return *this->_id;
}

void Ponto::setX(const float x) {
    this->_x = x;
}

void Ponto::setY(const float y) {
    this->_y = y;
}

void Ponto::setID(int id) {
    *this->_id = id;
} 

void Ponto::print() const {
    cout << "(" << this->getX() << "," << this->getY() << ")" << endl;
}

double Ponto::distTo(const Ponto &p) const{
    return dist(this->getX(), this->getY(), p.getX(), p.getY());
}

double Ponto::distToOrig() const {
    return dist(this->getX(), this->getY(), 0, 0);
}

void Ponto::soma(const Ponto &p){
    this->_x = this->_x + p._x;
    this->_y = this->_y + p._y;
}

Ponto Ponto::sumOf(const Ponto &p){
    Ponto P(this->_x + p._x, this->_y + p._y);
    return P;
}