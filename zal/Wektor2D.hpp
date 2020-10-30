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