// Vjezba 7, zadatak 2: napisite klasu Money i operatore iznad main.
// Datoteka racun.txt mora biti u mapi iz koje se program pokrece.

#include <fstream>
#include <iostream>
#include <string>

class Money {
    int cents{0};

public:
    Money(int euros = 0, int cents = 0) : cents(euros * 100 + cents) {}

    int get_cents() const { return cents; }

    Money& operator+=(const Money& rhs) {
        cents += rhs.cents;
        return *this;
    }
};

inline Money operator+(Money lhs, const Money& rhs) {
    lhs += rhs;
    return lhs;
}

inline bool operator<(const Money& lhs, const Money& rhs) {
    return lhs.get_cents() < rhs.get_cents();
}

inline std::ostream& operator<<(std::ostream& os, const Money& m) {
    int total = m.get_cents();
    int sign = total < 0 ? -1 : 1;
    int abs_total = total < 0 ? -total : total;
    int euros = abs_total / 100;
    int centi = abs_total % 100;

    if (sign < 0)
        os << '-';
    os << euros << '.';
    if (centi < 10)
        os << '0';
    os << centi << " EUR";
    return os;
}

inline std::istream& operator>>(std::istream& is, Money& m) {
    int euros = 0;
    char dot = '\0';
    int cents = 0;

    if (!(is >> euros >> dot >> cents))
        return is;

    if (dot != '.') {
        is.setstate(std::ios::failbit);
        return is;
    }

    if (cents < 0 || cents >= 100) {
        is.setstate(std::ios::failbit);
        return is;
    }

    int sign = (euros < 0) ? -1 : 1;
    m = Money(euros, sign * cents);
    return is;
}

int main()
{
    Money a(1, 5);
    Money b(0, 95);
    std::cout << a << " + " << b << " = " << a + b << '\n';

    std::ifstream in("racun.txt");
    if (!in) {
        std::cout << "Datoteka racun.txt ne postoji\n";
        return 1;
    }

    std::string item;
    Money price;
    Money total;
    Money max_price;
    std::string max_item;
    int count = 0;
    while (in >> item >> price) {
        total += price;
        if (max_price < price) {
            max_price = price;
            max_item = item;
        }
        ++count;
    }
    if (!in.eof())
        std::cout << "Neispravan zapis: " << item << '\n';

    std::cout << "Stavki: " << count << '\n';
    std::cout << "Ukupno: " << total << '\n';
    std::cout << "Najskuplje: " << max_item << ' ' << max_price << '\n';
    return 0;
}

/*
Ocekivani ispis:

    1.05 EUR + 0.95 EUR = 2.00 EUR
    Neispravan zapis: Sok
    Stavki: 5
    Ukupno: 17.23 EUR
    Najskuplje: Kava 7.99 EUR
*/
