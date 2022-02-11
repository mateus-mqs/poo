#include <iostream>
#include <string>
#include <vector>
#include "Universidade.h"

using namespace std;

int main()
{
	Universidade univ;
    ProfIntegral p1("Beltrano", 50000);
	ProfHorista p2("Fulano", 100, 100);
    ProfHorista p3("Siclano", 100, 80);

	univ.addProfessor(&p1);
	univ.addProfessor(&p2);
	univ.addProfessor(&p3);

    cout << "O total pago para os professor eh: " << univ.totalPago() << endl;
    univ.printProfessores();
}