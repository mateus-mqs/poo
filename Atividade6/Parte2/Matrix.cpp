// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 6
// Exercicio 2
// 15/12/2021

#include <fstream>
#include <iostream>
#include "Matrix.h"

using namespace std;


// contrutor default - cria uma matriz vazia com nRows = nCols = 0  
template <class T>
Matrix<T>::Matrix(){
    this->nCols = 0;
    this->nRows = 0;
    this->m = new T *[0];
}

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a elem (double)
template <class T>
Matrix<T>::Matrix(int rows, int cols, const T &value){
    this->nRows = rows;
    this->nCols = cols;
    this->m = new T *[rows];
    for(int i = 0; i < rows; ++i){
        this->m[i] = new T[cols];
    }
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            this->m[i][j] = value;
        }
    }
}

// contrutor parametrico 2 - cria uma matriz com os dados fornecidos pelo arquivo texto myFile.
template <class T>
Matrix<T>::Matrix(ifstream &myFile){
    int rows, cols;
    myFile >> rows >> cols;
    this->nRows = rows;
    this->nCols = cols;
    this->m = new T *[rows];
    for(int i = 0; i < rows; ++i){
        this->m[i] = new T[cols];
    }
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            myFile >> this->m[i][j];
        }
    }
}

// contrutor de copia
template <class T>
Matrix<T>::Matrix(const Matrix& that){
    this->nCols = that.nCols;
    this->nRows = that.nRows;
    this->m = new T *[this->nRows];
    for(int i = 0; i < this->nRows; ++i){
        this->m[i] = new T[this->nCols];
    }
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            this->m[i][j] = that.m[i][j];
        }
    }
}

// destrutor
template <class T>
Matrix<T>::~Matrix() {
    for(int i = 0; i < this->nRows; ++i){
        delete[] this->m[i];
    }
    delete[] this->m;
}

template <class T>
T Matrix<T>::get(int row, int col) const {
    if (row >= this->nRows || col >= this->nCols) throw std::invalid_argument("Coordenadas invalidas.");
    return this->m[row][col];
}

// obtem o numero de linhas
template <class T>
int Matrix<T>::rows() const {
    return this->nRows;
}

// obtem o numero de colunas
template <class T>
int Matrix<T>::cols() const {
    return this->nCols;
}

// retorna uma matriz transposta
template <class T>
Matrix<T> Matrix<T>::transpose() {
    Matrix<T> nova = Matrix<T>(this->nCols, this->nRows, 0);
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            nova.m[j][i] = this->m[i][j];
        }
    }
    return nova;
}

// imprime o conteudo da matriz
template <class T>
void Matrix<T>::print() const {
    if (this->nCols == 0 || this->nRows == 0){
        return;
    }
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            cout << this->m[i][j] << " ";
        }
        cout << endl;
    }
}

template <class T>
void Matrix<T>::unit(){
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

template <class T>
void Matrix<T>::zeros(){
   for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            this->m[i][j] = 0;
        }
   }
}

template <class T>
void Matrix<T>::ones(){
   for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            this->m[i][j] = 1;
        }
   }
}

template <class T>
T& Matrix<T>::operator()(const int x, const int y) const{
    return this->m[x][y];
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix& mat){
    this->nRows = mat.nRows;
    this->nCols = mat.nCols;
    this->m = new T *[mat.nRows];
    for(int i = 0; i < mat.nRows; ++i){
        this->m[i] = new T[mat.nCols];
    }
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            this->m[i][j] = mat.m[i][j];
        }
    }
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix& mat) const{
    if(mat.nCols != this->nCols || mat.nRows != this->nRows){
        throw Erro("Matrizes de tamanhos diferentes.");
    }
    Matrix<T> aux(this->nRows,this->nCols, 0);
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            aux.m[i][j] = this->m[i][j] + mat.m[i][j];
        }
    }
    return aux;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& mat) const{
    if(mat.nCols != this->nCols || mat.nRows != this->nRows){
        throw Erro("Matrizes de tamanhos diferentes.");
    }
    Matrix<T> aux(this->nRows,this->nCols, 0);
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            aux.m[i][j] = this->m[i][j] - mat.m[i][j];
        }
    }
    return aux;
}

template <class T>
void Matrix<T>::operator+=(const Matrix& mat){
    if(mat.nCols != this->nCols || mat.nRows != this->nRows){
        throw Erro("Matrizes de tamanhos diferentes.");
    }
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            this->m[i][j] = this->m[i][j] + mat.m[i][j];
        }
    }
}

template <class T>
void Matrix<T>::operator-=(const Matrix& mat){
    if(mat.nCols != this->nCols || mat.nRows != this->nRows){
        throw Erro("Matrizes de tamanhos diferentes.");
    }
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            this->m[i][j] = this->m[i][j] - mat.m[i][j];
        }
    }
}

template <class T>
Matrix<T> Matrix<T>::operator~() const{
    Matrix<T> aux(this->nCols,this->nRows, 0);
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            aux.m[j][i] = this->m[i][j];
        }
    }
    return aux;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix& mat) const{
    if(this->nCols != mat.nRows){
        throw Erro("Matrizes incompativeis para multiplicacao.");
    }
    Matrix<T> aux(this->nRows, mat.nCols, 0);
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < mat.nCols; ++j){
            for(int k = 0; k < mat.nRows; ++k){
                aux.m[i][j] += this->m[i][k] * mat.m[k][j];
            }
        }
    }
    return aux;
}

template <class T>
void Matrix<T>::operator*=(const Matrix& mat){
    *this = *this * mat;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const int a) const{
    Matrix<T> aux(this->nRows, this->nCols, 0);
    for(int i = 0; i < this->nRows; ++i){
        for(int j = 0; j < this->nCols; ++j){
            aux.m[i][j] = this->m[i][j] * a;
        }
    }
    return aux;
}

template <class T>
void Matrix<T>::operator*=(const int a){
    *this = *this * a;
}

template <class T>
int Matrix<T>::operator==(const Matrix& mat) const{
    if(mat.nCols != this->nCols || mat.nRows != this->nRows){
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

template <class T>
int Matrix<T>::operator!=(const Matrix& mat) const{
    return !(*this == mat);
}

template <class T>
ostream& operator<<(ostream& os, const Matrix<T>& mat){
    os << std::endl;
    for(int i = 0; i < mat.rows(); ++i){
        for(int j = 0; j < mat.cols(); ++j){
            os << mat.get(i,j) << " ";
        }
        os << std::endl;
    }
    return os;
}

template <class T>
istream& operator>>(istream& is, Matrix<T>& mat){
    for(int i = 0; i < mat.rows(); ++i){
        for(int j = 0; j < mat.cols(); ++j){
            is >> mat.get(i,j);
        }
    }
    return is;
}

template ostream& operator<<(ostream&, const Matrix<int>&);
template ostream& operator<<(ostream&, const Matrix<float>&);
template ostream& operator<<(ostream&, const Matrix<double>&);
template ostream& operator<<(ostream&, const Matrix<long>&);

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;
template class Matrix<long>;
