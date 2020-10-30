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
    /*
        void   setX(int a) { x = a; }
        double getX() { std::cout << x << '\n'; }
        void   setY(int a) { y = a; }
        double getY() { std::cout << y << '\n'; }
    */
    double x;
    double y;
    int    populacja() { return num_wek; }

    static void kart(double x, double y) { Wektor2D(x, y); }

private:
    static int num_wek;

    // konstruktor parametryczny
    Wektor2D(double X, double Y)
    {
        x = X;
        y = Y;
        ++num_wek;
        std::cout << "Konstruktor parametryczny. X=" << x << "\t Y=" << y << " num_wek=" << num_wek
                  << "\n";
    }
};

int Wektor2D::num_wek = 0;

std::ostream& operator<<(std::ostream& os, const Wektor2D& W1)
{
    os << "[" << W1.x << ", " << W1.y << "] \n";
    return os;
}

class Suma
{
public:
    Suma() {}
    Suma(Wektor2D W1, Wektor2D W2) { X = W1.x + W2.x, Y = W1.y + W2.y; }
    double X;
    double Y;
};

Suma operator+(Wektor2D W1, Wektor2D W2)
{
    return Suma(W1, W2);
}

class iloczyn
{
public:
    iloczyn() {}
    iloczyn(Wektor2D W1, Wektor2D W2) { I = W1.x * W2.x + W1.y * W2.y; }
    double I;
};

iloczyn operator*(Wektor2D W1, Wektor2D W2)
{
    return iloczyn(W1, W2);
}

int main()
{
    Wektor2D A;
    Wektor2D::kart(10, 0);
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
