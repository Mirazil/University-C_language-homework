#include <iostream>
#include <string>
using namespace std;

class Square
{
private:
    double side;
    double area;

public:
    Square(double side);
    void set_side(double newSide);
    void print();
};

Square::Square(double side)
{
    this->side = side;
    this->area = side * side;
}

void Square::set_side(double newSide)
{
    if (newSide >= 0)
    {
        side = newSide;
        area = side * side;
    }
}

void Square::print()
{
    cout << "Square: side=" << side << " area=" << area << endl;
}

int main()
{
    Square s(4);
    s.print();

    s.set_side(2.0);
    s.print();

    s.set_side(-33.0);
    s.print();

    return 0;
}
