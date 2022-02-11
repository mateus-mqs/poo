// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 5
// Exercicio 2
// 07/12/2021

#include "matrix.h"

int main()
{
    /*
    std::cout << "A matrix X eh: " << std::endl;
    X.print();
    std::cout << "Numero de linhas de X:: " << X.getRows() << std::endl;
    std::cout << "Numero de colunas de X:: " << X.getCols() << std::endl;

    std::cout << std::endl;

    std::cout << "A matriz Z eh: " << std::endl;
    Z.print();
    std::cout << "Numero de linhas de Z:: " << Z.getRows() << std::endl;
    std::cout << "Numero de colunas de Z:: " << Z.getCols() << std::endl;

    std::cout << std::endl;
    
    std::cout << "A matriz W eh: " << std::endl;
    W.print();
    std::cout << "Numero de linhas de W:: " << W.getRows() << std::endl;
    std::cout << "Numero de colunas de W:: " << W.getCols() << std::endl;*/
    ifstream in("myMatrix.txt");
    Matrix Y;
    Matrix X(3,4,10), A(4,3,3), C(4,3), D(4,3,8);
    Matrix Z(3,2,7.0);
    Matrix W(in);
    
    // operadores a serem implementados em sua classe:
    C = A + A;                                  // Soma
    std::cout << "A matrix C eh: " << C << std::endl;
    C -= A;                                     // Subtração
    std::cout << "A matrix C eh: " << C << std::endl;  
    A = C - D;                                  // Subtração
    std::cout << "A matrix A eh: " << A << std::endl;  
    A += A;                                   // Soma
    std::cout << "A matrix A eh: " << A << std::endl;  
    A = ~C;                                  // A é igual a transposta de C
    std::cout << "A matrix A eh: " << A << std::endl;  
    X *= 2;                                   // multiplicação por uma constante
    std::cout << "A matrix X eh: " << X << std::endl;  
    A = ~A;
    C = A*X;                                         // multiplicação de matrizes
    std::cout << "A matrix C eh: " << C << std::endl;
    std::cout << "A matrix W eh: " << W << endl; 
    C *= W;                                            // multiplicação de matrizes
    std::cout << "A matrix C eh: " << C << std::endl;
    A = C;
    std::cout << "A matrix A eh: " << A << std::endl;
    if (A == C){                                 // verifica a igualdade entre A e C
        std::cout << "A matrix A eh igual a matriz C" << std::endl;
    }
    if(X != Y){                                  // verifica a desigualdade entre A e C
        std::cout << "A matrix X eh diferente da matriz Y" << std::endl;
    }
    std::cout << "Digite a matriz W: " << std::endl;
    std::cin >> W;                                        // leitura de dados para dentro da matriz Y 
    std::cout << "A matrix W eh: " << W << std::endl; 
    return 0;
}