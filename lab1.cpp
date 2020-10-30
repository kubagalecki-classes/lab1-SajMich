// jak zrobic zadanie 9.

#include <iostream>

class Wektor2D
{
public:
    Wektor2D()
    {
        x = 0;
        y = 0;
    }

    Wektor2D(double X, double Y)
    {
        x = X;
        y = Y;
    }

    void   setX(int a) { x = a; }
    double getX() { return x; }
    void   setY(int a) { y = a; }
    double getY() { return y; }

    double x;
    double y;
};

double operator*(Wektor2D& W1, Wektor2D& W2)
{
    return W1.x * W2.x + W1.y * W2.y;
}

Wektor2D operator+(Wektor2D& W1, Wektor2D& W2)
{
    Wektor2D tmp = W1;
    tmp.x += W2.x;
    tmp.y += W2.y;
    return tmp;
}

int main()
{
    Wektor2D v1{};         // Konstruktor domyślny, wektor o wsp. [0, 0]
    v1.setX(10.);          // setter
    v1.setY(11.);          // setter
    double x1 = v1.getX(); // getter
    double y1 = v1.getY(); // getter

    std::cout << "x1= " << x1 << "y1= " << y1 << "\n";

    Wektor2D v2{100., 0.2}; // Konstruktor nadający współrzędne

    Wektor2D sum = v1 + v2; // dodawanie wektorów
    std::cout << "x= " << sum.x << "y= " << sum.y << "\n";

    double prod = v1 * v2; // iloczyn skalarny

    std::cout << "iloczyn= " << prod << "\n";
}
