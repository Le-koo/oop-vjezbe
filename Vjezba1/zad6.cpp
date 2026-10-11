#include <iostream>

int najveciZajednicki(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

struct Fraction {
    int numerator;
    int denominator;

    void reduce() {

        int zajednicki = najveciZajednicki(numerator, denominator);
        numerator /= zajednicki;
        denominator /= zajednicki;
        
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    double value() const {
        return static_cast<double>(numerator) / denominator;
    }

    void print() const {
        std::cout << numerator << "/" << denominator;
    }
};

Fraction sum(const Fraction& a, const Fraction& b) {
    int novi_brojnik = a.numerator * b.denominator + b.numerator * a.denominator;
    int novi_nazivnik = a.denominator * b.denominator;
    
    Fraction rezultat{novi_brojnik, novi_nazivnik};
    rezultat.reduce();
    return rezultat;
}

int main() {

    Fraction f1{2, 6};
    Fraction f2{3, 9};

    std::cout << "Prvi razlomak: ";
    f1.print();
    std::cout << "\n";

    f1.reduce();
    std::cout << "Prvi nakon skracivanja: ";
    f1.print();
    std::cout << ", decimalna vrijednost: " << f1.value() << "\n";

    std::cout << "Drugi razlomak: ";
    f2.print();
    std::cout << "\n";

    Fraction zbroj = sum(f1, f2);
    std::cout << "Zbroj razlomaka: ";
    zbroj.print();
    std::cout << ", decimalna vrijednost: " << zbroj.value() << "\n";



    return 0;
}