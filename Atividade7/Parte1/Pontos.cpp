// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 7
// Exercicio 1
// 12/01/2022

#include<iostream>
using namespace std;

class Ponto2D{
     public:
        Ponto2D(double xx = 0.0, double yy = 0.0):x(xx),y(yy){};
        friend ostream& operator<< (ostream &op, const Ponto2D &p);
        Ponto2D& operator= (const Ponto2D &p);
        ~Ponto2D(){};
        double get_x(void) { return x; }
        double get_y(void) { return y; }
        void set (double nx, double ny) { x=nx; y=ny; }
    
    private:                
        double x;
        double y;
};

ostream& operator<< (ostream &op, const Ponto2D &p){
            op << endl;
            op << "x = " << p.x << endl;
            op << "y = " << p.y << endl;
            return op;
}

Ponto2D& Ponto2D::operator= (const Ponto2D &p){
    x = p.x;
    y = p.y;
    return *this;
}
//-------------------------------------------------------------------------------------------------
class Ponto3D: public Ponto2D{
    
    public:
        Ponto3D(double xx = 0, double yy = 0, double zz=0):Ponto2D(xx,yy),z(zz){}
        friend ostream& operator<< (ostream &op, const Ponto2D &p);
        Ponto3D& operator= (const Ponto2D &p);
        void set(double nx = 0, double ny = 0, double nz=0){
            Ponto2D::set(nx,ny); z = nz;
        }
        double get_z(){return z;}
            
    
    private:
        double z;
};    

ostream& operator<< (ostream &op, Ponto3D &p){
    op << endl;
    op << "x = " << p.get_x() << endl;
    op << "y = " << p.get_y() << endl;
    op << "z = " << p.get_z() << endl;
    return op;
}

Ponto3D& Ponto3D::operator= (const Ponto2D &p){
    Ponto2D::operator=(p);
    z = 0.0;
    return *this;
}
//-------------------------------------------------------------------------------------------------
// código para teste da classe Ponto3D
    
int main()
{
    Ponto2D p1(3,4), p2;
    p2.set(2,1.5);
    cout << p1 << endl;
    cout << p2 << endl;

    p2 = p1;
    cout << p2 << endl;


    Ponto3D p3(2,4.5,5), p4;
    p4.set(1,0.3,12);
    cout << p3 << endl;
    cout << p4 << endl;

    p4 = p3;
    cout << p4 << endl;

    p4 = p1;
    cout << p4 << endl;

    return 0;
}