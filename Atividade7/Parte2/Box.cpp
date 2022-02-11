// Mateus Marques Goncalves de Paula
// Turma TECAD - POO
// Atividade 7
// Exercicio 2
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

//#include "Ponto2D"

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

class Box{
    
    public:
        Box(Ponto3D p1, Ponto3D p2){ // p1 eh o ponto no canto inferior esquerdo da frente e p2 eh o canto superior direito de tras
            alt = p2.get_z() - p1.get_z();
            lar = p2.get_x() - p1.get_x();
            prof = p2.get_y() - p1.get_y();
        }
        Ponto3D& operator= (const Ponto2D &p);
        double get_area(){
            return 2*(alt*lar + alt*prof + lar*prof);
        }
        double get_volume(){
            return alt*lar*prof;
        }
            
    
    private:
        double alt;
        double lar;
        double prof;
};

int main()
{

    Ponto3D p1(0,0,0);
    Ponto3D p2(1,1,1);
    Box b1(p1,p2);
    cout << "area de b1 eh: "<< b1.get_area() << endl <<"volume de b1 eh: "<< b1.get_volume() << endl;

    Ponto3D p3(1,2,3);
    Ponto3D p4(5,4,6);
    Box b2(p3,p4);
    cout << "area de b2 eh: "<< b2.get_area() << endl <<"volume de b2 eh: "<< b2.get_volume() << endl;


    return 0;
}