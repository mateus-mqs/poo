// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 7
// Exercicio 4
// 12/01/2022

// As respostas estão no arquivo de texto "Respostas_Exercicio_4"

#include <iostream>

class Base{
    
    int i;
    
    protected:
        int read() const { return i; }
        void set(int ii) { i = ii; }
    
    public:
        Base(int ii = 0) : i(ii) {}
        int value(int m) const { return m*i; }
};


class Derived : protected Base{
        
        int j;
        public:
            Derived(int jj = 0) : j(jj) {}
            void change(int x) { set(x); }
};

class Derived2 : public Derived{
    public:
        int chama1(){
            return read();
        }
        int chama2(){
            return value(1);
        }
};