#include <iostream>
#include <string>

class IPAddress {
public:
    IPAddress(const std::string& address) : address(address) {}
    IPAddress(const IPAddress& other) : address(other.address) {}

    void print() const {
        std::cout << address << std::endl;
    }

protected:
    std::string address;
};

class IPAddressChecked : public IPAddress {
public:
    IPAddressChecked(const std::string& address, bool correct)
        : IPAddress(address), correct(correct) {}

    IPAddressChecked(const IPAddressChecked& other)
        : IPAddress(other), correct(other.correct) {}

    void print() const {
        IPAddress::print();
        std::cout << (correct ? " - Correct" : " - Not Correct") << std::endl;
    }

private:
    bool correct;
};

int main() {
    std::string address1, address2, address3;

    std::cout << "Enter IP address 1: ";
    std::cin >> address1;

    std::cout << "Enter IP address 2: ";
    std::cin >> address2;

    std::cout << "Enter IP address 3: ";
    std::cin >> address3;

    IPAddress ip1(address1);
    IPAddressChecked ipChecked1(address2, false);
    IPAddressChecked ipChecked2(address3, true);

    ip1.print();
    ipChecked1.print();
    ipChecked2.print();

    return 0;
}
