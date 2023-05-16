#include <iostream>
#include <string>
using namespace std;

class ShopItemOrder
{
private:
    string itemName;
    double unitPrice;
    int numberOfItems;

public:
    ShopItemOrder(string itemName, double unitPrice, int numberOfItems);

    // Access methods
    string getItemName();
    void setItemName(string name);

    double getUnitPrice();
    void setUnitPrice(double price);

    int getNumberOfItems();
    void setNumberOfItems(int number);

    double getTotalPrice();

    void printOrder();
};

ShopItemOrder::ShopItemOrder(string itemName, double unitPrice, int numberOfItems)
{
    this->itemName = itemName;
    this->unitPrice = unitPrice;
    this->numberOfItems = numberOfItems;
}

string ShopItemOrder::getItemName()
{
    return itemName;
}

void ShopItemOrder::setItemName(string name)
{
    itemName = name;
}

double ShopItemOrder::getUnitPrice()
{
    return unitPrice;
}

void ShopItemOrder::setUnitPrice(double price)
{
    unitPrice = price;
}

int ShopItemOrder::getNumberOfItems()
{
    return numberOfItems;
}

void ShopItemOrder::setNumberOfItems(int number)
{
    numberOfItems = number;
}

double ShopItemOrder::getTotalPrice()
{
    return unitPrice * numberOfItems;
}

void ShopItemOrder::printOrder()
{
    cout << "Order Details:" << endl;
    cout << "Item: " << itemName << endl;
    cout << "Unit Price: $" << unitPrice << endl;
    cout << "Quantity: " << numberOfItems << endl;
    cout << "Total Price: $" << getTotalPrice() << endl;
}

int main()
{
    ShopItemOrder order("Book", 9.99, 2);
    order.printOrder();

    order.setNumberOfItems(3);
    order.printOrder();

    order.setUnitPrice(14.99);
    order.printOrder();

    return 0;
}
