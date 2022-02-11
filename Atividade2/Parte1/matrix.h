// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 2
// Exercicio 1
// 06/11/2021

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
    private:

        double** m; // m é um array 2D a ser implementado como um pointer de pointers
        int nRows;  // numero de linhas
        int nCols;  //  numero de colunas

    public:

        // Construtores
        Matrix();                           
        Matrix(int rows, int cols, double elem);
        // destrutor
        ~Matrix();
    
        // basic getters
        int getRows() const;
        int getCols() const;
        
        // other methods
        Matrix transpose();
        void print() const;
        
        
};

#endif