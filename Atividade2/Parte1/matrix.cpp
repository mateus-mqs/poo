// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 2
// Exercicio 1
// 06/11/2021

#include "matrix.h"

using namespace std;

// contrutor default - cria uma matriz vazia com nRows = nCols = 0  
Matrix::Matrix(){
    this->m = new double *[0];
}

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a elem (double)
Matrix::Matrix(int rows, int cols, double elem = 0){
    this->nRows = rows;
    this->nCols = cols;
    this->m = new double *[rows];
    for(int i = 0; i < rows; ++i){
        this->m[i] = new double[cols];
    }
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            this->m[i][j] = elem;
        }
    }
}

// destrutor
Matrix::~Matrix() {
    for(int i = 0; i < this->nRows; ++i){
        delete[] this->m[i];
    }
    delete[] this->m;
}

// obtem o numero de linhas
int Matrix::getRows() const {
    return this->nRows;
}

// obtem o numero de colunas
int Matrix::getCols() const {
    return this->nCols;
}

// retorna uma matriz transposta
Matrix Matrix::transpose() {
    Matrix nova = Matrix(this->nCols, this->nRows, 0);
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            nova.m[j][i] = this->m[i][j];
        }
    }
    return nova;
}

// imprime o conteudo da matriz
void Matrix::print() const {
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            cout << this->m[i][j] << " ";
        }
        cout << endl;
    }
}