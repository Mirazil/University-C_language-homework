#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    int n; 
    std::cout << "Enter number of elemnts in array: ";
    std::cin >> n;
    float* arr = new float[n];
    int positive = 0, negative = 0;
    for (float* p = arr; p < arr + n; p++) {
        *p = -2 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (4)));
        std::cout << *p << " ";
        if (*p > 0)
            positive++;
        else if (*p < 0)
            negative++;
    }
    std::cout << std::endl;
    std::cout << "Positive numbers: " << positive << std::endl;
    std::cout << "Negative numbers: " << negative << std::endl;
    delete[] arr; // звільняємо пам'ять, виділену під масив
    return 0;
}