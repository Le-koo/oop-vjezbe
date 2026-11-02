#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string jmbag;
    string surname;
    int points;
};

int main() {
    vector<Student> registered{
        {"0302", "Kovac", 78}, {"0117", "Babic", 45},
        {"0255", "Maric", 91}, {"0117", "Babic", 45},
        {"0410", "Novak", 78}, {"0089", "Juric", 62},
        {"0255", "Maric", 91}, {"0520", "Maric", 55},
        {"0333", "Peric", 30}
    };


    sort(registered.begin(), registered.end(), [](const Student& a, const Student& b) {
        return a.jmbag < b.jmbag;
    });


    auto jedinstveni_kraj = unique(registered.begin(), registered.end(), [](const Student& a, const Student& b) {
        return a.jmbag == b.jmbag;
    });

    registered.erase(jedinstveni_kraj, registered.end());

    cout << "prijavljenih: " << registered.size() << endl;

    int prag;
    cout << "Prag: ";
    cin >> prag;

    auto loši_kraj = remove_if(registered.begin(), registered.end(), [prag](const Student& s) {
        return s.points < prag;
    });
    registered.erase(loši_kraj, registered.end());


    sort(registered.begin(), registered.end(), [](const Student& a, const Student& b) {
        if (a.points != b.points) {
            return a.points > b.points;
        }
        return a.surname < b.surname;
    });

    
    int poz = 1;
    for (const auto& s : registered) {
        cout << poz++ << ". " << s.surname << " (" << s.jmbag << ") " << s.points << endl;
    }

    return 0;
}