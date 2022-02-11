// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 6
// Exercicio 2
// 15/12/2021

#include <iostream>

template <class T>
T fibo(const T n){
    if (n == 1){
        return 0;
    }
    if (n == 2){
        return 1;
    }
    return fibo(n-1) + fibo(n-2);
}

int main(){
    double k = fibo(10);

    std::cout << k << std::endl;

    return 0;
}