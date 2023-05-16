#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    FlightBooking();
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);
    int getId() { return id; }

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    this->id = id;
    this->capacity = capacity;
    this->reserved = (reserved < 0) ? 0 : reserved;
    if (reserved > capacity * 1.05) {
        this->reserved = capacity * 1.05;
    }
}

FlightBooking::FlightBooking()
{
    id = 0;
    capacity = 0;
    reserved = 0;
}

void FlightBooking::printStatus()
{
    double percentage = static_cast<double>(reserved) / capacity * 100;
    cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << fixed << setprecision(0) << percentage << "%) seats reserved" << endl;
}

bool FlightBooking::reserveSeats(int number_of_seats)
{
    if (reserved + number_of_seats <= capacity * 1.05) {
        reserved += number_of_seats;
        return true;
    }
    return false;
}

bool FlightBooking::cancelReservations(int number_of_seats)
{
    if (reserved - number_of_seats >= 0) {
        reserved -= number_of_seats;
        return true;
    }
    return false;
}

int main() {
    FlightBooking booking[10];
    string command;

    while (command != "quit") {
        cout << "What would you like to do?: ";
        getline(cin, command);

        if (command.substr(0, 7) == "create ") {
            int id = stoi(command.substr(7, 3));
            int capacity = stoi(command.substr(11));
            if (id >= 0 && id < 10 && booking[id].getId() == 0) {
                booking[id] = FlightBooking(id, capacity, 0);
                cout << "Flight " << id << " created with capacity " << capacity << endl;
            } else {
                cout << "Cannot perform this operation: flight " << id << " already exists" << endl;
            }
        } else if (command.substr(0, 7) == "delete ") {
            int id = stoi(command.substr(7));
            if (id >= 0 && id < 10 && booking[id].getId() != 0) {
                booking[id] = FlightBooking();
                cout << "Flight " << id << " deleted" << endl;
            } else {
                cout << "Cannot perform this operation: flight " << id << " not found" << endl;
            }
        } else if (command.substr(0, 4) == "add ") {
            int id = stoi(command.substr(4, 3));
            int num_seats = stoi(command.substr(8));
            if (id >= 0 && id < 10 && booking[id].getId() != 0) {
                if (booking[id].reserveSeats(num_seats)) {
                    cout << "Seats successfully added to flight " << id << endl;
                } else {
                    cout << "Cannot perform this operation: capacity reached for flight " << id << endl;
                }
            } else {
                cout << "Cannot perform this operation: flight " << id << "
