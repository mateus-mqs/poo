// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 5
// Exercicio 1
// 08/12/2021
#include<iostream> 

class Ponto2D{
    
    int x,y;
    
    public:
        Ponto2D(int xx=0, int yy=0):x(xx),y(yy){ };
        Ponto2D& operator-- ();
        Ponto2D operator+ (const Ponto2D& ) const;
        ~Ponto2D(){}; 
        void print();
};

Ponto2D& Ponto2D::operator--(){
    this->x--;
    this->y--;
    return *this;
}

Ponto2D Ponto2D::operator+(const Ponto2D& p) const{
    Ponto2D aux(this->x + p.x , this->y + p.y);
    return aux;
}

void Ponto2D::print(){
    std::cout << "(" << this->x << "|" << this->y << ")" << std::endl;
}

int main() {
    Ponto2D a(1,4), b(3,2), c;
    std::cout << "As coordenadas de C sao: ";
    c.print();
    c = a + b;               // soma as coordenadas dos pontos a e b 
    std::cout << "As coordenadas de C sao: ";
    c.print();
    --c;                    // decrementa em uma unidade as coordenadas de c
    std::cout << "As coordenadas de C sao: ";
    c.print();
    return 0;
}