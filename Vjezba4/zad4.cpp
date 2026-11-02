#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

struct PasswordInfo {
    int length;
    int digits;
    int uppercase;
    int special;
};

PasswordInfo analyze(const string& password) {
    PasswordInfo info;
    info.length = password.length();

    info.digits = count_if(password.begin(), password.end(), [](unsigned char c) {
        return isdigit(c);
    });

    info.uppercase = count_if(password.begin(), password.end(), [](unsigned char c) {
        return isupper(c);
    });

    info.special = count_if(password.begin(), password.end(), [](unsigned char c) {
        return ispunct(c);
    });

    return info;
}

bool is_strong(const PasswordInfo& info) {
    return (info.length >= 10 && info.digits >= 1 && info.uppercase >= 1 && info.special >= 1);
}

int main() {
    string lozinka1 = "Lozinka123";
    string lozinka2 = "Lozinka123!";

    PasswordInfo info1 = analyze(lozinka1);
    cout << lozinka1 << ": duljina " << info1.length 
        << ", znamenke " << info1.digits 
        << ", velika " << info1.uppercase 
        << ", posebni " << info1.special << " -> " 
        << (is_strong(info1) ? "jaka" : "slaba") << endl;

    PasswordInfo info2 = analyze(lozinka2);
    cout << lozinka2 << ": duljina " << info2.length 
        << ", znamenke " << info2.digits 
        << ", velika " << info2.uppercase 
        << ", posebni " << info2.special << " -> " 
        << (is_strong(info2) ? "jaka" : "slaba") << endl;

    return 0;
}