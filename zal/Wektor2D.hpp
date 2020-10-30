class Wektor2D
{
    public:

    Wektor2D()
    {
      x=0;
      y=0;
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
};

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