#include <iostream>
#include <string>
using namespace std;

class AdHocSquare
{
public:
    AdHocSquare(double side);
    void set_side(double side);
    double get_area();

private:
    double side;
};

AdHocSquare::AdHocSquare(double side)
{
    this->side = side;
}

void AdHocSquare::set_side(double side)
{
    this->side = side;
}

double AdHocSquare::get_area()
{
    return side * side;
}

class LazySquare
{
public:
    LazySquare(double side);
    void set_side(double side);
    double get_area();

private:
    double side;
    double area;
    bool side_changed;
};

LazySquare::LazySquare(double side)
{
    this->side = side;
    this->area = side * side;
    this->side_changed = false;
}

void LazySquare::set_side(double side)
{
    if (this->side != side)
    {
        this->side = side;
        this->side_changed = true;
    }
}

double LazySquare::get_area()
{
    if (side_changed)
    {
        this->area = side * side;
        this->side_changed = false;
    }
    return this->area;
}

int main()
{
    AdHocSquare adhoc(4);
    cout << "AdHocSquare area: " << adhoc.get_area() << endl;

    adhoc.set_side(5);
    cout << "AdHocSquare area: " << adhoc.get_area() << endl;

    LazySquare lazy(4);
    cout << "LazySquare area: " << lazy.get_area() << endl;

    lazy.set_side(5);
    cout << "LazySquare area: " << lazy.get_area() << endl;

    return 0;
}
