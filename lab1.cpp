// jak zrobic zadanie 9.

#include <iostream>

class Informer
{
public:
    Informer() { std::cout << "wykorzystano konstruktor informer" << '\n'; }
    ~Informer() { std::cout << "wykorzystano destruktor informer" << '\n'; }
};

class Wektor2D
{
public:
    // konstruktor domyslny
    Wektor2D()
    {
        x = 0;
        y = 0;
        ++num_wek;
        std::cout << "Konstruktor domyslny. X=" << x << "\t Y=" << y << " num_wek=" << num_wek
                  << "\n";
    };
    // konstruktor parametryczny
    Wektor2D(double X, double Y)
    {
        x = X;
        y = Y;
        ++num_wek;
        std::cout << "Konstruktor parametryczny. X=" << x << "\t Y=" << y << " num_wek=" << num_wek
                  << "\n";
    }
    // konstruktor kopiujacy
    Wektor2D(const Wektor2D& W)
    {
        x = W.x;
        y = W.y;
        ++num_wek;
        std::cout << "Konstruktor kopiujacy. X=" << x << "\t Y=" << y << " num_wek=" << num_wek
                  << "\n";
    }
    // destruktror
    ~Wektor2D()
    {
        --num_wek;
        std::cout << "Destruktor. X=" << x << "\t Y=" << y << " num_wek=" << num_wek << "\n";
    }

    void   setX(int a) { x = a; }
    double getX() { return x; }
    void   setY(int a) { y = a; }
    double getY() { return y; }
    double x;
    double y;
    int    populacja() { return num_wek; }

    static void kart(double x, double y) { Wektor2D(x, y); }

private:
    static int num_wek;
};

int Wektor2D::num_wek = 0;

std::ostream& operator<<(std::ostream& os, const Wektor2D& W1)
{
    os << "[" << W1.x << ", " << W1.y << "] \n";
    return os;
}

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

/*
class sum
{
public:
    sum() {}
    sum(Wektor2D W1, Wektor2D W2) { suma.x = W1.x + W2.x, suma.y = W1.y + W2.y; }
    Wektor2D suma;
};

sum operator+(Wektor2D W1, Wektor2D W2)
{
    return sum(W1, W2);
}
*/
/*
class iloczyn
{
public:
    iloczyn() {}
    iloczyn(Wektor2D W1, Wektor2D W2) { I = W1.x * W2.x + W1.y * W2.y; }
    double I;
};

iloczyn operator*(Wektor2D W1, Wektor2D W2)
{
    B = iloczyn(W1, W2);
    return B.I;
}
*/

int main()
{
    Wektor2D v1{};
    v1.setX(1.);           // setter
    v1.setY(1.);           // setter
    double x1 = v1.getX(); // getter
    double y1 = v1.getY(); // getter
    std::cout << "x1=" << x1 << "y1= " << y1 << "\n";
    Wektor2D v2{2., 2.};
    Wektor2D sumo = v1 + v2; // dodawanie wektorów
    double   prod = v1 * v2; // iloczyn skalarny

    std::cout << "x= " << sumo.x << " y= " << sumo.y << "\n";
    std::cout << "prod: " << prod << "\n";

    /*Wektor2D B(20, 0);
    Suma     s;
    s = A + B;
    std::cout << "suma: " << s.X << "\t" << s.Y << "\n";
    iloczyn I;
    I = A * B;
    std::cout << licznik << "\n";
    std::cout << "iloczyn: " << I.I << "\n";
    std::cout << A << '\n' << B << '\n';
    */
}
