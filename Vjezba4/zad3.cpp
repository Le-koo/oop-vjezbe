#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


bool starts_with(const string& s, const string& prefix) {
    if (prefix.length() > s.length()) return false;
    return equal(prefix.begin(), prefix.end(), s.begin());
}

bool ends_with(const string& s, const string& suffix) {
    if (suffix.length() > s.length()) return false;
    return equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

int main() {
    vector<string> datoteke = {"vjezba04.cpp", "slajdovi.pdf", "main.cpp", "README.md", "vjezba04.h", "notes.txt", "vjezba03.cpp"};

    auto lambda_cpp = [](const string& ime) {
        return ends_with(ime, ".cpp");
    };
    int broj_cpp = count_if(datoteke.begin(), datoteke.end(), lambda_cpp);

    cout << ".cpp datoteka: " << broj_cpp << endl;

    auto lambda_vjezba = [](const string& ime) {
        return starts_with(ime, "vjezba");
    };

    auto granica = remove_if(datoteke.begin(), datoteke.end(), lambda_vjezba);
    datoteke.erase(granica, datoteke.end());

    for (const auto& d : datoteke) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}