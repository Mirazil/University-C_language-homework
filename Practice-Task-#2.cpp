#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

const int SIZE = 5; // розмірність масиву

int main() {
    int matrix[SIZE][SIZE];

    // заповнюємо масив випадковими значеннями
    srand(time(NULL));
    for (int* row = &matrix[0][0]; row <= &matrix[SIZE - 1][SIZE - 1]; row++) {
        *row = rand() % 21 - 10;
    }

    // виводимо масив та знаходимо головну діагональ
    int* ptr = &matrix[0][0];
    int sum_even = 0, sum_odd = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout.width(4);
            std::cout << *ptr;

            if (*ptr % 2 == 0) { // парне число
                sum_even++;
            }
            else { // непарне число
                sum_odd++;
            }
            ptr++;
        }
        std::cout << endl;
    }

    std::cout << "Number of even elements: " << sum_even << std::endl;
    std::cout << "Number of odd elements: " << sum_odd << std::endl;

    return 0;
}
