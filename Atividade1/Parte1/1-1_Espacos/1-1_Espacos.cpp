// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 1
// Exercicio 1.1
// 29/10/2021

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main () {
  string line;
  int cont = 0;
  ifstream myfile ("arquivo.txt");
  if (myfile.is_open()) { // se abriu o arquivo corretamente
    while (!myfile.eof()){ //enquanto end of file for false continua{
      getline (myfile,line); // obtem linha
        for(int i = 0; i < line.size(); ++i){
            if(line[i] == ' '){ //se achar um espaco em branco
                ++cont; //incrementa o contador
            }
        }
    }
    myfile.close();
  } else {
    cout << "Nao foi possível abrir o arquivo.";
    exit(1);
  }
  cout << "O arquivo possui" << cont << "espacos em branco." << endl;

  return 0;
}