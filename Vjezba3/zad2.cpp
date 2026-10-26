#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cout << "Broj dana: ";
    if (!(cin >> n)) return 0;

    vector<double> temperature(n);
    cout << "Unesite temperature: ";
    
    for (int i = 0; i < n; ++i) {
        cin >> temperature[i];
    }

    vector<double> promjene;
    if (n > 1) {
        promjene.reserve(n - 1);
        for (auto it = temperature.begin(); it + 1 != temperature.end(); ++it) {
            promjene.push_back(*(it + 1) - *it);
        }
    }

    cout << "Promjene:";
    for (double p : promjene) {
        cout << " " << p;
    }

    cout << endl;

    vector<double> izvjestaj = temperature;

    if (n >0) {
        double zadnja_temp = temperature.back();
        izvjestaj.resize(7, zadnja_temp);
    }
    else {
        izvjestaj.resize(7, 0.0);
    }

    cout << "Izvjestaj:";
    for (double t : izvjestaj){
        cout << " " << t;
    }

    cout << endl;

    return 0;
}