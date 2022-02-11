// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 2
// Exercicio 2
// 06/11/2021

#include "Tempo.h"

int main()
{
    Tempo t;
    Tempo t1(72);
    Tempo t2(90,3);
    Tempo t3(4, 7,55);
    Tempo t4(45, 30, 56, 65);
    Tempo t5;
    t5.leitura();
    t.imprime();
    t1.imprime();
    t2.imprime();
    t3.imprime();
    t4.imprime();
    t5.imprime();
    t4.soma(t3);
    t4.imprime();
    t2.incrementa();
    t2.incrementa();
    t2.imprime();
    t2.decrementa();
    t2.imprime();
    t.~Tempo();
    t1.~Tempo();
    t2.~Tempo();
    t3.~Tempo();
    t4.~Tempo();
    t5.~Tempo();
    return 0;
}