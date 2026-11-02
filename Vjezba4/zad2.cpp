#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Song {

    string title;
    string artist;
    int year;
    int plays;

};

void print_song(const Song& s){

    cout << "\"" << s.title << "\" - " << s.artist << " (" << s.year << ") | Slušanja: " << s.plays << endl;

}

int main(){

    vector <Song> pjesme = {
        {"Bohemian Rhapsody", "Queen", 1975, 500000},
        {"Stairway to Heaven", "Led Zeppelin", 1971, 450000},
        {"Somebody to Love", "Queen", 1976, 300000},
        {"Hotel California", "Eagles", 1976, 600000},
        {"Smells Like Teen Spirit", "Nirvana", 1991, 700000}
    };

    auto sortiranje = [](const Song& a, const Song& b){
        if (a.year != b.year) {
            return a.year < b.year;
        }
        return a.title < b.title;
    };

    sort(pjesme.begin(), pjesme.end(), sortiranje);

    cout << "Sortirane pjesme:" << endl;
    for (const auto& s : pjesme) {
        print_song(s);
    }
    cout << endl;

    string izvodac;
    cout<< "Unesite izvodaca: ";
    cin >> izvodac;

    auto izvodacCount = [izvodac](const Song& pisma){return izvodac==pisma.artist;};
    const Song* najstarija = nullptr;
    int brojPisama = count_if(pjesme.begin(), pjesme.end(), izvodacCount);

    if(brojPisama > 0){
        cout<< "Izvodac "<< izvodac <<" ima " << brojPisama <<" pjesama"<< endl;

        for(const auto& pisma : pjesme){
            if(pisma.artist == izvodac){
                if(najstarija==nullptr){
                    najstarija = &pisma;
                }
            }
        }

        cout<< "Najstarija pjesma mu je "<< najstarija->title<< " ("<<najstarija->year<<")"<< endl;
    }
    else{
        cout << "Na popisu nema pjesama od izvodaca "<< izvodac << endl;
    }


    auto usporedi_slusanja = [](const Song& a, const Song& b) {
        return a.plays < b.plays;
    };

    if (!pjesme.empty()) {
        auto najslusanija = max_element(pjesme.begin(), pjesme.end(), sortiranje);

        cout << "Najslusanija pjesma: " << endl;
        print_song(*najslusanija);
    }
    

    return 0;
}