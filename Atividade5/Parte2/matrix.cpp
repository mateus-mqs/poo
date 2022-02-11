// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 5
// Exercicio 2
// 07/12/2021

#include "matrix.h"
#include <fstream>
#include <iostream>
using namespace std;


// contrutor default - cria uma matriz vazia com nRows = nCols = 0  
Matrix::Matrix(){
    this->nCols = 0;
    this->nRows = 0;
    this->m = new double *[0];
}

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a elem (double)
Matrix::Matrix(int rows, int cols, const double &value){
    this->nRows = rows;
    this->nCols = cols;
    this->m = new double *[rows];
    for(int i = 0; i < rows; ++i){
        this->m[i] = new double[cols];
    }
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            this->m[i][j] = value;
        }
    }
}

// contrutor parametrico 2 - cria uma matriz com os dados fornecidos pelo arquivo texto myFile.
Matrix::Matrix(ifstream &myFile){
    int rows, cols;
    myFile >> rows >> cols;
    this->nRows = rows;
    this->nCols = cols;
    this->m = new double *[rows];
    for(int i = 0; i < rows; ++i){
        this->m[i] = new double[cols];
    }
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            myFile >> this->m[i][j];
        }
    }
}

// contrutor de copia
Matrix::Matrix(const Matrix& that){
    this->nCols = that.getCols();
    this->nRows = that.getRows();
    this->m = new double *[this->nRows];
    for(int i = 0; i < this->nRows; ++i){
        this->m[i] = new double[this->nCols];
    }
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            this->m[i][j] = that.m[i][j];
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

double Matrix::get(int row, int col) const {
    if(row > this->getRows() || row < 0){
        cout << "Linha invalida. Foi obtida a ultima linha" << endl;
        row = this->getRows();
    }
    if(col > this->getCols() || col < 0){
        cout << "Coluna invalida. Foi obtida a ultima coluna" << endl;
        col = this->getCols();
    }
    return this->m[row-1][col-1];
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
    if (this->getCols() == 0 || this->getRows() == 0){
        cout << "Matriz de tamanho 0." << endl;
        return;
    }
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            cout << this->m[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::unit(){
   for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            if(i == j){
                this->m[i][j] = 1;
            } else {
                this->m[i][j] = 0;
            }
        }
   }
}

void Matrix::zeros(){
   for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            this->m[i][j] = 0;
        }
   }
}

void Matrix::ones(){
   for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            this->m[i][j] = 1;
        }
   }
}

Matrix& Matrix::operator=(const Matrix& mat){
    this->nRows = mat.nRows;
    this->nCols = mat.nCols;
    this->m = new double *[mat.nRows];
    for(int i = 0; i < mat.nRows; ++i){
        this->m[i] = new double[mat.nCols];
    }
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            this->m[i][j] = mat.m[i][j];
        }
    }
}

Matrix Matrix::operator+(const Matrix& mat) const{
    if(mat.getCols() != this->getCols() || mat.getRows() != this->getRows()){
        cout << "Matrizes de tamanhos diferentes." << endl;
        exit(1);
    }
    Matrix aux(this->getRows(),this->getCols());
    for(int i = 0; i < this->getRows(); ++i){
        for(int j = 0; j < this->getCols(); ++j){
            aux.m[i][j] = this->m[i][j] + mat.m[i][j];
        }
    }
    return aux;
}

Matrix Matrix::operator-(const Matrix& mat) const{
    if(mat.getCols() != this->getCols() || mat.getRows() != this->getRows()){
        cout << "Matrizes de tamanhos diferentes." << endl;
        exit(1);
    }
    Matrix aux(this->getRows(),this->getCols());
    for(int i = 0; i < this->getRows(); ++i){
        for(int j = 0; j < this->getCols(); ++j){
            aux.m[i][j] = this->m[i][j] - mat.m[i][j];
        }
    }
    return aux;
}

void Matrix::operator+=(const Matrix& mat){
    if(mat.getCols() != this->getCols() || mat.getRows() != this->getRows()){
        cout << "Matrizes de tamanhos diferentes." << endl;
        exit(1);
    }
    for(int i = 0; i < this->getRows(); ++i){
        for(int j = 0; j < this->getCols(); ++j){
            this->m[i][j] = this->m[i][j] + mat.m[i][j];
        }
    }
}

void Matrix::operator-=(const Matrix& mat){
    if(mat.getCols() != this->getCols() || mat.getRows() != this->getRows()){
        cout << "Matrizes de tamanhos diferentes." << endl;
        exit(1);
    }
    for(int i = 0; i < this->getRows(); ++i){
        for(int j = 0; j < this->getCols(); ++j){
            this->m[i][j] = this->m[i][j] - mat.m[i][j];
        }
    }
}

Matrix Matrix::operator~() const{
    Matrix aux(this->getCols(),this->getRows());
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            aux.m[j][i] = this->m[i][j];
        }
    }
    return aux;
}

Matrix Matrix::operator*(const Matrix& mat) const{
    if(this->nCols != mat.nRows){
        cout << "Matrizes de tamanhos incompativeis para a multiplicacao." << endl;
        exit(1);
    }
    Matrix aux(this->nRows, mat.nCols);
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < mat.nCols; ++j){
            for(int k = 0; k < mat.nRows; ++k){
                aux.m[i][j] += this->m[i][k] * mat.m[k][j];
            }
        }
    }
    return aux;
}

void Matrix::operator*=(const Matrix& mat){
    *this = *this * mat;
}

Matrix Matrix::operator*(const int a) const{
    Matrix aux(this->nRows, this->nCols);
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            aux.m[i][j] = this->m[i][j] * a;
        }
    }
    return aux;
}

void Matrix::operator*=(const int a){
    *this = *this * a;
}

int Matrix::operator==(const Matrix& mat) const{
    if(mat.getCols() != this->getCols() || mat.getRows() != this->getRows()){
        return 0;
    }
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nRows; ++j){
            if(this->m[i][j] != mat.m[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

int Matrix::operator!=(const Matrix& mat) const{
    return !(*this == mat);
}

ostream& operator<<(ostream& os, const Matrix& mat){
    os << std::endl;
    for(int i = 0; i < mat.nRows; ++i){
        for(int j = 0; j < mat.nCols; ++j){
            os << mat.m[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

istream& operator>>(istream& is, Matrix& mat){
    for(int i = 0; i < mat.nRows; ++i){
        for(int j = 0; j < mat.nCols; ++j){
            is >> mat.m[i][j];
        }
    }
    return is;
}