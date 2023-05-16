#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int age;
    string occupation; // New member: occupation

    // Function to introduce the person
    void introduce()
    {
        cout << "My name is " << name << ", I am " << age << " years old, and I work as a " << occupation << "." << endl;
    }
};

int main()
{
    Person person;
    person.name = "Harry";
    person.age = 23;
    person.occupation = "Software Engineer";

    cout << "Meet " << person.name << endl;
    person.introduce();

    return 0;
}
