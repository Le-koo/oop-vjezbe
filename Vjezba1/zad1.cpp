#include <iostream>

int main() {
    int a{};
    int b{};

    std::cout << "Unesi dva a i b:" << "\n";
    std::cin >> a >> b;

    int zbroj = a + b;
    double sredina = (a+b) / 2.0;

    bool manji = (a < b);

    std::cout << "Zbroj: " << zbroj << "\n";
    std::cout << "Aritmetička sredina: " << sredina << "\n";

    if(manji){
        std::cout << "Broj a je manji od broja b";
    }
    else{
        std::cout << "Broj b je manji od broja a";
    }
    

    return 0;
}