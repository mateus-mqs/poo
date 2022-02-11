// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 6
// Exercicio 2
// 15/12/2021

#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

template <class T> class Matrix;

template <class T>
class Matrix {
    private:
        T** m; // m é um array 2D a ser implementado como um pointer de pointers
        int nRows;  // numero de linhas
        int nCols;  //  numero de colunas

    public:

        // Construtores
        Matrix();                           
        Matrix(int, int, const T&);

        Matrix(ifstream &myFile);
        Matrix(const Matrix& that);

        // destrutor
        ~Matrix();
    
        // basic getters
        int rows() const;
        int cols() const;

        T get(int, int) const;
        
        // other methods
        Matrix transpose();
        void print() const;
        void unit();
        void zeros();
        void ones();
        
        T& operator()(const int, const int) const; 
        Matrix& operator=(const Matrix&);
        Matrix operator+ (const Matrix&) const;
        Matrix operator- (const Matrix&) const;
        void operator+= (const Matrix&);
        void operator-= (const Matrix&);
        Matrix operator~ () const;
        Matrix operator* (const Matrix&) const;
        void operator*= (const Matrix&);
        Matrix operator* (const int) const;
        void operator*= (const int);
        int operator== (const Matrix&) const;
        int operator!= (const Matrix&) const;
};

template <class T> 
ostream& operator<<(ostream&, const Matrix<T>&);

template <class T> 
istream& operator>>(istream&, Matrix<T>&); 


#endif