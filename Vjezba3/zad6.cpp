#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split_words(const std::string& text){

    std::vector<std::string> rijeci;

    std::size_t pocetak = 0;

    std::size_t kraj = text.find(' ');

    while(kraj != std::string::npos){

        if (kraj > pocetak){
            rijeci.push_back(text.substr(pocetak, kraj - pocetak));
        }

        pocetak = kraj + 1;
        kraj = text.find(' ', pocetak);
    }

    if(pocetak < text.length()){
        rijeci.push_back(text.substr(pocetak));
    }

    return rijeci;
}

int main(){

    std::string unos;

    std::cout << "Unesite recenicu: ";


    if (std::getline(std::cin, unos)) {
        std::vector<std::string> rijeci = split_words(unos);

        if (rijeci.empty()) {
            std::cout << "Niste unijeli nijednu rijec.\n";
            return 0;
        }


        int broj_rijeci = rijeci.size();
        std::string najdulja = rijeci[0];
        std::string prva_abecedi = rijeci[0];


        for (std::size_t i = 1; i < rijeci.size(); ++i){
            if (rijeci[i].length() > najdulja.length()){
                najdulja = rijeci[i];
            }

            if (rijeci[i] < prva_abecedi){
                prva_abecedi = rijeci[i];
            }

        }

        std::cout << "broj rijeci: " << broj_rijeci << "\n";

        std::cout << "najdulja: " << najdulja << "\n";

        std::string obrnuto_spojeno = "";

        for (int i = rijeci.size() - 1; i >= 0; --i){
            obrnuto_spojeno += rijeci[i];
            if (i > 0) {
                obrnuto_spojeno += "-";
            }
        }

        std::cout << obrnuto_spojeno << "\n";

        std::cout << "prva po abecedi: " << prva_abecedi << "\n";
    }

    return 0;
}