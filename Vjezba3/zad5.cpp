#include <iostream>
#include <string>

std::string with_separators(std::string digits){

    int brojac = 0;
    int pocetak = (digits.length() > 0 && digits[0] == '-') ? 1 : 0;

    for (int i = digits.length() - 1; i >= pocetak; --i){
        brojac++;

        if (brojac % 3 == 0 && i > pocetak) {
            digits.insert(i, ".");
        }

    }
    return digits;
}

std::string without_separators(std::string text) {
    std::size_t pos = text.find('.');
    while (pos != std::string::npos) {
        text.erase(pos, 1);
        pos = text.find('.', pos);
    }
    return text;
}

int main() {
    std::string t1 = "1234567";
    std::string t2 = "-1234567";
    std::string t3 = "100000";
    std::string t4 = "1.234.567";

    std::cout << "\"" << t1 << "\" -> \"" << with_separators(t1) << "\"\n";
    std::cout << "\"" << t2 << "\" -> \"" << with_separators(t2) << "\"\n";
    std::cout << "\"" << t3 << "\" -> \"" << with_separators(t3) << "\"\n";
    std::cout << "\"" << t4 << "\" -> \"" << without_separators(t4) << "\"\n";

    return 0;
}