// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 4
// Exercicio 2
// 01/12/2021

#include "matrix.h"

int main()
{
    ifstream in("myMatrix.txt");
    Matrix Y;
    Matrix X(3,1);
    Matrix Z(3,2,7.0);
    Matrix W(in);
    
    std::cout << "Y:: " << std::endl;
    Y.print();
    std::cout << "Numero de linhas de Y:: " << Y.getRows() << std::endl;
    std::cout << "Numero de colunas de Y:: " << Y.getCols() << std::endl; 
   
    std::cout << std::endl;

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
    std::cout << "Numero de colunas de W:: " << W.getCols() << std::endl;

    std::cout << std::endl;

    std::cout << "Elemento na posicao (3,2) de W eh: " << W.get(3,2) << std::endl;

    std::cout << std::endl;

    Z.zeros();
    std::cout << "A matriz Z transformada em zeros eh: " << std::endl;
    Z.print();
    std::cout << "Numero de linhas de Z:: " << Z.getRows() << std::endl;
    std::cout << "Numero de colunas de Z:: " << Z.getCols() << std::endl;

    std::cout << std::endl;

    W.unit();
    std::cout << "A matriz W transformada em uma matriz identidade eh: " << std::endl;
    W.print();
    std::cout << "Numero de linhas de W:: " << W.getRows() << std::endl;
    std::cout << "Numero de colunas de W:: " << W.getCols() << std::endl;

    std::cout << std::endl;

    X.ones();
    std::cout << "A matriz X transformada em ones eh: " << std::endl;
    X.print();
    std::cout << "Numero de linhas de X:: " << X.getRows() << std::endl;
    std::cout << "Numero de colunas de X:: " << X.getCols() << std::endl;


    std::cout << std::endl;

    Matrix A = W;
    std::cout << "A matriz A, que eh uma copia de W, eh: " << std::endl;
    A.print();
    std::cout << "Numero de linhas de A:: " << A.getRows() << std::endl;
    std::cout << "Numero de colunas de A:: " << A.getCols() << std::endl;

    return 0;
}