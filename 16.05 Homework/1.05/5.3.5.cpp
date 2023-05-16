#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();

private:
    int numerator;
    int denominator;
};

Fraction::Fraction(int numerator, int denominator)
{
    int sign = 1;
    if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
        sign = -1;

    numerator = abs(numerator);
    denominator = abs(denominator);

    int commonDivisor = gcd(numerator, denominator);
    numerator /= commonDivisor;
    denominator /= commonDivisor;

    this->numerator = sign * numerator;
    this->denominator = denominator;
}

string Fraction::toString()
{
    int wholePart = numerator / denominator;
    int remainder = abs(numerator) % denominator;

    string result;

    if (wholePart != 0) {
        result += to_string(wholePart);
        if (remainder != 0)
            result += " ";
    }

    if (remainder != 0)
        result += to_string(remainder) + "/" + to_string(denominator);
    else if (wholePart == 0)
        result = "0";

    if (numerator < 0)
        result = "-" + result;

    return result;
}

double Fraction::toDouble()
{
    return static_cast<double>(numerator) / denominator;
}

int main()
{
    int num, den;
    string input;
    getline(cin, input);

    size_t slashPos = input.find("/");
    if (slashPos != string::npos) {
        num = stoi(input.substr(0, slashPos));
        den = stoi(input.substr(slashPos + 1));
    }

    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;

    return 0;
}
