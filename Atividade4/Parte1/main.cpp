// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 4
// Exercicio 1
// 01/12/2021
#include "Ponto.h"

using namespace std;

int main()
{
    Ponto p1;
    Ponto p2(6,8);
    Ponto p3(1,1);

    cout << "p1 possui coordenadas: ";
    p1.print();
    cout << "ID de p1: " << p1.getID() << endl;
    cout << "p2 possui coordenadas: ";
    p2.print();
    cout << "ID de p2: " << p2.getID() << endl;
    cout << "p3 possui coordenadas: ";
    p3.print();
    cout << "ID de p3: " << p3.getID() << endl;


    cout << "Distancia de p1 para a origem: " << p1.distToOrig() << endl;
    cout << "Distancia de p2 para a origem: " << p2.distToOrig() << endl;
    cout << "Distancia de p3 para a origem: " << p3.distToOrig() << endl;

    cout << "Distancia de p1 a p2: " << p1.distTo(p2) << endl;

    p1.soma(p2);
    cout << "p1 depois de ser somado com p2 possui coordenadas: ";
    p1.print(); 

    Ponto p4 = p2.sumOf(p3);
    cout << "p4 eh a soma de p2 com p3, que possui coordenadas: ";
    p4.print();

    Ponto p5 = p2;
    cout << "p5 possui coordenadas: ";
    p5.print();
    cout << "ID de p5: " << p5.getID() << endl;

    Ponto p6(p2);
    cout << "p6 possui coordenadas: ";
    p6.print();
    cout << "ID de p6: " << p6.getID() << endl;

    return 0;
}