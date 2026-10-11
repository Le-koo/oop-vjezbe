#include <iostream>
#include <string>

int main() {
    int godina_rodjenja{};
    
    std::cout << "Unesi godinu rođenja: ";
    std::cin >> godina_rodjenja;

    std::cin.ignore(); 

    std::string ime_prezime{};
    std::cout << "Unesi ime i prezime: ";
    std::getline(std::cin, ime_prezime);

    char inicijal_imena = ime_prezime[0];
    char inicijal_prezimena = ' ';
    
    for (size_t i = 0; i < ime_prezime.length(); ++i) {
        if (ime_prezime[i] == ' ') {
            inicijal_prezimena = ime_prezime[i + 1];
            break;
        }
    }
    
    std::cout << "Inicijali: " << inicijal_imena << "." << inicijal_prezimena << "." << "\n";

    int broj_znakova = 0;
    for (char znak : ime_prezime) {
        if (znak != ' ') {
            broj_znakova++;
        }
    }

    std::cout << "Broj znakova: " << broj_znakova << "\n";

    int trenutna_godina = 2026; 
    int navrsava_godina = trenutna_godina - godina_rodjenja;
    std::cout << "Ove godine navrsava: " << navrsava_godina << " godina." << "\n";

    return 0;
}