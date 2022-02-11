// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 4
// Exercicio 2
// 01/12/2021

#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>
#include <iostream>
using namespace std;

class Matrix {
    private:
        double** m; // m é um array 2D a ser implementado como um pointer de pointers
        int nRows;  // numero de linhas
        int nCols;  //  numero de colunas

    public:

        // Construtores
        Matrix();                           
        Matrix(int rows, int cols, const double &value = 0.0);

        Matrix(ifstream &myFile);
        Matrix(const Matrix& that);

        // destrutor
        ~Matrix();
    
        // basic getters
        int getRows() const;
        int getCols() const;

        double get(int row, int col) const;
        
        // other methods
        Matrix transpose();
        void print() const;
        void unit();
        void zeros();
        void ones();
        
        
};

#endif