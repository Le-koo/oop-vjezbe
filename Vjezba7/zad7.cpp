// Vjezba 7, zadatak 6: citanje datoteke tekst.txt, brojanje rijeci i ispis statistike.

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct WordCount {
    std::string word;
    int count;
};

std::string clean(const std::string& word) {
    std::string rezultat;
    for (unsigned char znak : word) {
        if (std::isalpha(znak)) {
            rezultat.push_back(static_cast<char>(std::tolower(znak)));
        }
    }
    return rezultat;
}

int main() {
    
    std::ifstream in("tekst.txt");
    if (!in) {
        std::cout << "Datoteka tekst.txt ne postoji\n";
        return 1;
    }

    std::map<std::string, int> freq;
    std::string rijec;
    while (in >> rijec) {
        std::string ociscena = clean(rijec);
        if (!ociscena.empty()) {
            ++freq[ociscena];
        }
    }

    std::cout << "razlicitih rijeci: " << freq.size() << '\n';
    std::cout << "alice: " << freq["alice"] << '\n';

    std::vector<WordCount> popis;

    popis.reserve(freq.size());
    for (const auto& par : freq) {
        popis.push_back(WordCount{par.first, par.second});
    }

    std::sort(popis.begin(), popis.end(), [](const WordCount& a, const WordCount& b) {
        if (a.count != b.count)
            return a.count > b.count;
        return a.word < b.word;
    });

    std::size_t granica = std::min<std::size_t>(5, popis.size());
    for (std::size_t i = 0; i < granica; ++i) {
        std::cout << popis[i].word << ": " << popis[i].count << '\n';
    }

    return 0;
}