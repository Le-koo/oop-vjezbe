#include <iostream>
#define MAX(a, b) a > b ? a : b 
int main()
{
    int a = MAX(3, 5);
    int b = 2 * MAX(3, 5);
    int c = MAX(3, 5) + 1;

    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";

}
