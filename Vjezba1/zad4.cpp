#include <iostream>

namespace geo {
    const double PI = 3.14159;
}

double area(double r) {
    return geo::PI * r * r;
}

double area(double a, double b) {
    return a * b;
}

int area(int a) {
    return a * a;
}

void print_line(char c = '-', int length = 30) {
    for (int i = 0; i < length; ++i) {
        std::cout << c;
    }
    std::cout << "\n";
}

int main() {
    print_line();

    std::cout << "area(5): " << area(5) << "\n";
    std::cout << "area(5.0): " << area(5.0) << "\n";
    std::cout << "area(2, 3): " << area(2, 3) << "\n";
    std::cout << "area('A'): " << area('A') << "\n";


    return 0;
}