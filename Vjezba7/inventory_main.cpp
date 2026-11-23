// Vjezba 7, zadatak 4: napisite klasu Inventory iznad funkcije show.

#include <iostream>
#include <string>
#include <vector>

class Inventory {
private:
    std::vector<std::string> predmeti;
    std::size_t max_predmeta;

public:
    explicit Inventory(std::size_t max_predmeta) : max_predmeta(max_predmeta) {
        predmeti.reserve(max_predmeta);
    }

    Inventory& operator+=(const std::string& predmet) {
        if (predmeti.size() < max_predmeta) {
            predmeti.push_back(predmet);
        }
        return *this;
    }

    std::string& operator[](std::size_t indeks) {
        return predmeti[indeks];
    }

    const std::string& operator[](std::size_t indeks) const {
        return predmeti[indeks];
    }

    std::size_t size() const {
        return predmeti.size();
    }

    explicit operator bool() const {
        return !predmeti.empty();
    }
};

void show(const Inventory& inv)
{
    if (!inv) {
        std::cout << "prazno\n";
        return;
    }
    for (std::size_t i = 0; i < inv.size(); ++i)
        std::cout << i << ": " << inv[i] << '\n';
}

int main()
{
    Inventory bag(3);
    show(bag);

    bag += "mac";
    bag += "stit";
    bag += "kljuc";
    bag += "baklja";          // ne stane
    show(bag);

    bag[0] = "zlatni mac";
    std::cout << bag[0] << ' ' << bag.size() << '\n';

    if (bag)
        std::cout << "ima predmeta\n";
    return 0;
}

/*
Ocekivani ispis:

    prazno
    0: mac
    1: stit
    2: kljuc
    zlatni mac 3
    ima predmeta
*/