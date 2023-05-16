#include <iostream>
#include <string>
using namespace std;

class GymMember {
public:
    GymMember(int id, const string& name);
    void printStatus();
    bool extendSubscription(int months);
    void cancelSubscription();
    int getId() { return id; }

private:
    int id;
    string name;
    int subscriptionMonths;
};

GymMember::GymMember(int id, const string& name)
{
    this->id = id;
    this->name = name;
    subscriptionMonths = 0;
}

void GymMember::printStatus()
{
    cout << "Member " << id << " : " << name << ", subscription valid for " << subscriptionMonths << " months" << endl;
}

bool GymMember::extendSubscription(int months)
{
    if (months >= 0) {
        subscriptionMonths += months;
        return true;
    }
    return false;
}

void GymMember::cancelSubscription()
{
    subscriptionMonths = 0;
}

int main()
{
    GymMember members[10];
    string command;

    while (command != "quit") {
        cout << "What would you like to do?: ";
        getline(cin, command);

        if (command.substr(0, 7) == "create ") {
            int id = stoi(command.substr(7, 2));
            string name = command.substr(10);
            if (id >= 0 && id < 10 && members[id].getId() == 0) {
                members[id] = GymMember(id, name);
                cout << "Member " << id << " created" << endl;
            } else {
                cout << "Cannot perform this operation: member " << id << " already exists" << endl;
            }
        } else if (command.substr(0, 7) == "delete ") {
            int id = stoi(command.substr(7));
            if (id >= 0 && id < 10 && members[id].getId() != 0) {
                members[id] = GymMember(0, "");
                cout << "Member " << id << " deleted" << endl;
            } else {
                cout << "Cannot perform this operation: member " << id << " not found" << endl;
            }
        } else if (command.substr(0, 7) == "extend ") {
            int id = stoi(command.substr(7, 2));
            int months = stoi(command.substr(10));
            if (id >= 0 && id < 10 && members[id].getId() != 0) {
                if (members[id].extendSubscription(months)) {
                    cout << "Subscription extended for member " << id << endl;
                } else {
                    cout << "Cannot perform this operation: invalid number of months" << endl;
                }
            } else {
                cout << "Cannot perform this operation: member " << id << " not found" << endl;
            }
        } else if (command.substr(0, 7) == "cancel ") {
            int id = stoi(command.substr(7));
            if (id >= 0 && id < 10 && members[id].getId() != 0) {
                members[id].cancelSubscription();
                cout << "Subscription canceled for member " << id << endl;
            } else {
                cout << "Cannot perform this operation: member " << id << " not found" << endl;
            }
        }
    }

    return 0;
}
