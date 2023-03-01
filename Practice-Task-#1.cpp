#include <iostream>

int main()
{
    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
    int n = sizeof(vector) / sizeof(vector[0]);

    int* min_ptr = &vector[0];

    for (int i = 1; i < n; i++) {
        if (*(vector + i) < *min_ptr) {
            min_ptr = (vector + i);
        }
    }

    std::cout << "Minimal element is: " << *min_ptr << std::endl;

    return 0;
}   