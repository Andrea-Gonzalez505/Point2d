#include <cmath>

#include <iostream>
using namespace std;

class Point2d {
private: 
    double x;
    double y;

public:
    //constructores
    Point2d(): x(0), y(0) {} // Constructor por defecto (punto en el origen)
    Point2d(double x_ingresado, double y_ingresado) : x(x_ingresado), y(y_ingresado) {} // Constructor con parámetros

    // Getters
    double getX() const 
    { 
        return x; 
    }
    double getY() const 
    { 
        return y; 
    }

    // Setters
    void setX(double x_ingresado) 
    { 
        x = x_ingresado; 
    }
    void setY(double y_ingresado) 
    { 
        y = y_ingresado;
    }

    // Sobrecarga de operadores aritméticos
    Point2d operator+(const Point2d& p) const {
        return Point2d(x + p.x, y + p.y);
    }
    Point2d operator-(const Point2d& p) const {
        return Point2d(x - p.x, y - p.y);
    }

    Point2d operator*(double escalar) const {
        return Point2d(x * escalar, y * escalar);
    }

    Point2d operator/(double escalar) const {
        if (escalar != 0)
            return Point2d(x / escalar, y / escalar);
        else {
            cerr << "Error: División por cero" << endl;
            return *this;
        }
    }
// Método para calcular la distancia a otro punto
double distancia(const Point2d& p) const {
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2)); 
}    

// Método para calcular el punto medio con otro punto
Point2d puntoMedio(const Point2d& p) const {
    return Point2d((x + p.x) / 2, (y + p.y) / 2);
}

// Método para obtener el vector unitario asociado
Point2d vectorUnitario(const Point2d& p) const {
    
    double mag = sqrt(pow(x - p.x, 2) + pow(y - p.y, 2)); // Distancia desde el origen
    if (mag!= 0){
        return Point2d((x-p.x) / mag, (y-p.y) / mag);
        
    }
    else{
        return Point2d(0, 0);
    }
    
}


void imprimir() const {
    cout << "(" << x << ", " << y << ")" << endl;
}

};

int main() {
    double x1, y1, x2, y2;
    
    cout << "ingresa la cordenada x del punto 1: " << endl;
    cin >> x1;
    if (cin.fail()) {
        cout << "Entrada no valida, se asumira el punto (0,0)" << endl;
        x1 = 0;
        y1 = 0;
        cin.clear();
        cin.ignore();
        
    }

    else 
    {
        cout << "ingresa la cordenada y del punto 1: " << endl;
        cin >> y1;
        if (cin.fail()) {
            cout << "Entrada no valida, se asumira el punto (0,0)" << endl;
            x1 = 0;
            y1 = 0;
            cin.clear();
            cin.ignore();

        }
        
    }
    cout << "ingresa la cordenada x del punto 2: " << endl;
        cin >> x2;
    if (cin.fail()) {
        cout << "Entrada no valida, se asumira el punto (0,0)" << endl;
        x2 = 0;
        y2 = 0;
        cin.clear();
        cin.ignore();
    }
    else 
    {
        cout << "ingresa la cordenada y del punto 2: " << endl;
        cin >> y2;
        if (cin.fail()) {
            cout << "Entrada no valida, se asumira el punto (0,0)" << endl;
            x2 = 0;
            y2 = 0;
            cin.clear();
            cin.ignore();
        }
        
    } 
    Point2d p1(x1, y1);
    Point2d p2(x2, y2); 
    cout << "Punto 1: "; p1.imprimir();
    cout << "Punto 2: "; p2.imprimir();

    //cout << "Suma: "; (p1 + p2).imprimir();
    //cout << "Resta: "; (p1 - p2).imprimir();
    //cout << "Multiplicación por escalar 2: "; (p1 * 2).imprimir();
    //cout << "División por escalar 2: "; (p1 / 2).imprimir();
    cout << "Distancia entre P1 y P2: " << p1.distancia(p2) << endl;
    cout << "Punto medio entre P1 y P2: "; p1.puntoMedio(p2).imprimir();
    cout << "Vector unitario entre P1 (cabeza) y P2(cola): "; p1.vectorUnitario(p2).imprimir();
    return 0;
}