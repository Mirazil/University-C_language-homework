#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);

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
    int reserved = 0, capacity = 0;
    cout << "Provide flight capacity: ";
    cin >> capacity;
    cout << "Provide number of reserved seats: ";
    cin >> reserved;

    FlightBooking booking(1, capacity, reserved);

    string command;
    while (command != "quit") {
        booking.printStatus();
        cout << "What would you like to do?: ";
        getline(cin, command);

        if (command.substr(0, 4) == "add ") {
            int num_seats = stoi(command.substr(4));
            if (booking.reserveSeats(num_seats)) {
                cout << "Seats successfully added." << endl;
            } else {
                cout << "Cannot perform this operation." << endl;
            }
        } else if (command.substr(0, 7) == "cancel ") {
            int num_seats = stoi(command.substr(7));
            if (booking.cancelReservations(num_seats)) {
                cout << "Reservations successfully canceled." << endl;
            } else {
                cout << "Cannot perform this operation." << endl;
            }
        }
    }

    return 0;
}
