// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 1
// Exercicio 2
// 29/10/2021

#include <iostream>

using namespace std;

typedef struct{
    double** m;
    int nLinhas;
    int nColunas;
}Matriz;

void inicializaMatriz(Matriz &X, int ls, int cs, const double elem){
    X.nColunas = cs;
    X.nLinhas = ls;
    X.m = new double *[ls];
    for(int i = 0; i < ls; ++i){
        X.m[i] = new double[cs];
    }
    for(int i = 0; i < X.nLinhas; ++i){
        for(int j = 0; j < X.nColunas; ++j){
            X.m[i][j] = elem;
        }
    }
}

void apagaMatriz(Matriz &X){
    for(int i = 0; i < X.nLinhas; ++i){
        delete[] X.m[i];
    }
    delete[] X.m;
}

Matriz transposta(Matriz &X){
    Matriz nova;
    nova.nColunas = X.nLinhas;
    nova.nLinhas = X.nColunas;
    inicializaMatriz(nova, nova.nLinhas, nova.nColunas, 0.0);
    for(int i = 0; i < X.nLinhas; ++i){
        for(int j = 0; j < X.nColunas; ++j){
            nova.m[j][i] = X.m[i][j];
        }
    }
    return nova;
}

Matriz multiplica_por_cte(Matriz &X, double k){   
    Matriz nova;
    nova.nColunas = X.nColunas;
    nova.nLinhas = X.nLinhas;
    inicializaMatriz(nova, nova.nLinhas, nova.nColunas, k);
    for(int i = 0; i < nova.nLinhas; ++i){
        for(int j = 0; j < nova.nColunas; ++j){
            nova.m[i][j] *= X.m[i][j];
        }
    }
    return nova;
}

void imprimeMatriz(Matriz &X){
    for(int i = 0; i < X.nLinhas; ++i){
        for(int j = 0; j < X.nColunas; ++j){
            cout << X.m[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Matriz A, B, T, R;

    cout << "A:: " << endl;
    inicializaMatriz(A,2,3,7.0);
    imprimeMatriz(A);
    
    cout << "Transposta de A:: " << endl;
    T = transposta(A);
    imprimeMatriz(T);
    apagaMatriz(T);

    cout << endl << "B:: " << endl;
    inicializaMatriz(B,4,4,5.0);
    imprimeMatriz(B);
    
    cout << endl << "R = k*B " << endl;
    R = multiplica_por_cte(B,5); 
    imprimeMatriz(R);
    
    apagaMatriz(B);
    apagaMatriz(R);

    return 0;
}