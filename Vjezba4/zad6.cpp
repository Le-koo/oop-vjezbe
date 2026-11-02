#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> split_words(const string& recenica) {
    stringstream ss(recenica);
    string rijec;
    vector<string> rez;
    while (ss >> rijec) {
        rez.push_back(rijec);
    }
    return rez;
}

int main() {

    vector<string> rjecnik = {
        "jabuka", "kuca", "pas", "stablo", "auto", "knjiga", "voda", "sunce", "grad", "put"
    };

    sort(rjecnik.begin(), rjecnik.end());


    string recenica;
    cout << "Recenica: ";
    getline(cin, recenica);

    vector<string> rijeci = split_words(recenica);

    vector<string> nepoznate_rijeci;


    auto je_zanak_za_izbaciti = [](unsigned char c) {
        return ispunct(c) && c != '+';
    };

    for (string& rijec : rijeci) {

        auto makni = remove_if(rijec.begin(), rijec.end(), je_zanak_za_izbaciti);
        rijec.erase(makni, rijec.end());

        for (char& c : rijec) {
            c = tolower(static_cast<unsigned char>(c));
        }

        if (!rijec.empty() && !binary_search(rjecnik.begin(), rjecnik.end(), rijec)) {
            nepoznate_rijeci.push_back(rijec);
        }
    }

    cout << "nepoznatih rijeci: " << nepoznate_rijeci.size() << " ";
    for (const string& nepoznata : nepoznate_rijeci) {
        cout << nepoznata << " ";
    }
    cout << endl;

    return 0;
}